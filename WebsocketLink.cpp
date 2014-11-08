#include "WebsocketLink.hpp"
#include "SerialLink.hpp"

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

WebsocketLink::WebsocketLink(boost::asio::io_service& _io_service) : io_service(_io_service)
{
    hdl_inited = false;

    echo_server.set_access_channels(websocketpp::log::alevel::none);
    echo_server.set_error_channels(websocketpp::log::elevel::none);

    // Initialize ASIO
    echo_server.init_asio(&io_service);
    echo_server.set_reuse_addr(true);

    // Register our open handler
    echo_server.set_open_handler(websocketpp::lib::bind(&WebsocketLink::onOpen, this, &echo_server,::_1));

    // Register our message handler
    echo_server.set_message_handler(websocketpp::lib::bind(&WebsocketLink::onMessage, this, &echo_server,::_1,::_2));

    // Listen on port 9002
    echo_server.listen(9002);

    // Start the server accept loop
    echo_server.start_accept();
}

void WebsocketLink::setSerialLink(SerialLink *_serialLink) {
    serialLink = _serialLink;
}

void WebsocketLink::doSend(std::string& message) {
    if (hdl_inited) {
        echo_server.send(hdl, message, websocketpp::frame::opcode::text);
    }
}

void WebsocketLink::onOpen(server* s, websocketpp::connection_hdl _hdl) {
    hdl = _hdl;
    hdl_inited = true;
    std::cout<<std::endl<< "hello new visitor" << std::endl;
    io_service.post(boost::bind(&SerialLink::readNewLine, serialLink));
}

void WebsocketLink::onMessage(server* s, websocketpp::connection_hdl _hdl, message_ptr msg) {
    std::cout << "onMessage called with _hdl: " << _hdl.lock().get()
              << " and message: " << msg->get_payload()
              << std::endl;

    try {
        std::string message(msg->get_payload());
        io_service.post(boost::bind( &SerialLink::addToQueue, serialLink, message ));
    } catch (const websocketpp::lib::error_code& e) {
        std::cout << "Echo failed because: " << e
                  << "(" << e.message() << ")" << std::endl;
    }
}

