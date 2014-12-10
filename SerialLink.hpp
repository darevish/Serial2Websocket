#ifndef _SERIALLINK_H
#define _SERIALLINK_H

#include <iostream>
#include <queue>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class WebsocketLink;

class SerialLink
{
private:
    boost::asio::io_service& io_service;
    boost::asio::strand strand;

    boost::asio::serial_port serial_port;

    boost::asio::serial_port_base::flow_control flow_control;
    boost::asio::serial_port_base::parity parity;
    boost::asio::serial_port_base::stop_bits stop_bits;
    boost::asio::serial_port_base::baud_rate baud_rate;
    boost::asio::serial_port_base::character_size character_size;

    std::string device;

    boost::asio::streambuf read_buffer;

    boost::asio::deadline_timer timer;

    WebsocketLink *websocketLink;

    std::queue<std::string> writeQueue;

    bool needWrite;

    void restart(const boost::system::error_code& err);

    void processLine(const boost::system::error_code& err, std::size_t bytes_transferred);

    void writeHandler(const boost::system::error_code& error, std::size_t bytes_transferred);

    void destroy();

public:
    SerialLink(
        boost::asio::io_service& _io_service,
        std::string& _device,
        unsigned int _baud_rate = 9600,
        unsigned int _character_size = 8
    );

    ~SerialLink();

    void initOptions();

    void readNewLine();

    unsigned int getBaudRate();

    void setWebsocketLink(WebsocketLink *_websocketLink);

    void doWrite(std::string& msg);
};

#endif
