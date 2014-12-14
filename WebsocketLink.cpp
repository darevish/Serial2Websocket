#include "WebsocketLink.hpp"
#include "SerialLink.hpp"

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

WebsocketLink::WebsocketLink(boost::asio::io_service& _io_service, short websocketPort) : io_service(_io_service)
{
    std::cout<<"WebsocketLink constructor begin"<<std::endl;

    hdl_inited = false;

    ws_server.set_access_channels(websocketpp::log::alevel::none);
    ws_server.set_error_channels(websocketpp::log::elevel::none);

    // Initialize ASIO
    ws_server.init_asio(&io_service);
    ws_server.set_reuse_addr(true);

    // Register our open handler
    ws_server.set_open_handler(websocketpp::lib::bind(&WebsocketLink::onOpen, this, &ws_server,::_1));
    ws_server.set_fail_handler(websocketpp::lib::bind(&WebsocketLink::onFail, this, &ws_server,::_1));
    ws_server.set_close_handler(websocketpp::lib::bind(&WebsocketLink::onClose, this, &ws_server,::_1));

    // Register our message handler
    ws_server.set_message_handler(websocketpp::lib::bind(&WebsocketLink::onMessage, this, &ws_server,::_1,::_2));

    // Listen on port 9002
    ws_server.listen(websocketPort);

    // Start the server accept loop
    ws_server.start_accept();

    std::cout<<"WebsocketLink constructor end"<<std::endl;
}

WebsocketLink::~WebsocketLink() {
    std::cout<<"WebsocketLink desctructor begin"<<std::endl;
    if (hdl_inited) {
        std::cout<<"closing connection"<<std::endl;
        ws_server.stop_listening();
        ws_server.close(hdl, websocketpp::close::status::normal, "");
    }
    std::cout<<"WebsocketLink desctructor end"<<std::endl;
}

void WebsocketLink::setSerialLink(SerialLink *_serialLink) {
    serialLink = _serialLink;
}

void WebsocketLink::doSend(std::string& message) {
    if (hdl_inited) {
        ws_server.send(hdl, message, websocketpp::frame::opcode::text);
    }
}

void WebsocketLink::onOpen(server* s, websocketpp::connection_hdl _hdl) {

    if (hdl_inited == true) {
        s->close(_hdl, websocketpp::close::status::normal, "");
    } else {        
        hdl = _hdl;
        hdl_inited = true;
        std::cout<< "hello new visitor" << std::endl;
        io_service.post(boost::bind(&SerialLink::readNewLine, serialLink));
    }
}

void WebsocketLink::onFail(server* s, websocketpp::connection_hdl _hdl) {
    std::cout<< "connection fail" << std::endl;
}

void WebsocketLink::onClose(server* s, websocketpp::connection_hdl _hdl) {
    std::cout<< "connection close" << std::endl;
}

void WebsocketLink::onMessage(server* s, websocketpp::connection_hdl _hdl, message_ptr msg) {
    std::cout << "onMessage called with _hdl: " << _hdl.lock().get()
              << " and message: " << msg->get_payload()
              << std::endl;

    try {
        std::string message(msg->get_payload());
        io_service.post(boost::bind( &SerialLink::doWrite, serialLink, message ));
    } catch (const websocketpp::lib::error_code& e) {
        std::cout << "Echo failed because: " << e
                  << "(" << e.message() << ")" << std::endl;
    }
}

