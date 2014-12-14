#ifndef _WEBSOCKETLINK_H
#define _WEBSOCKETLINK_H

#include <websocketpp/config/asio_no_tls.hpp>

#include <websocketpp/server.hpp>

#include <iostream>

typedef websocketpp::server<websocketpp::config::asio> server;

// pull out the type of messages sent by our config
typedef server::message_ptr message_ptr;

class SerialLink;

class WebsocketLink {
public:

    WebsocketLink(boost::asio::io_service& _io_service, short websocketPort);

    ~WebsocketLink();

    void doSend(std::string& message);

    void setSerialLink(SerialLink *_serialLink);

    SerialLink *serialLink;

private:
    server ws_server;
    boost::asio::io_service& io_service;

    websocketpp::connection_hdl hdl;
    bool hdl_inited;

    void onOpen(server* s, websocketpp::connection_hdl _hdl);
    void onFail(server* s, websocketpp::connection_hdl _hdl);
    void onClose(server* s, websocketpp::connection_hdl _hdl);

    // Define a callback to handle incoming messages
    void onMessage(server* s, websocketpp::connection_hdl _hdl, message_ptr msg);

};

#endif
