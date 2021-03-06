#include "SerialLink.hpp"
#include "WebsocketLink.hpp"

SerialLink::SerialLink(
    boost::asio::io_service& _io_service,
    std::string& _device,
    unsigned int _baud_rate,
    unsigned int _character_size
) : io_service(_io_service),
    strand(_io_service),
    serial_port(_io_service, _device),
    device(_device),
    baud_rate(_baud_rate),
    character_size(_character_size),
    flow_control(boost::asio::serial_port_base::flow_control::none),
    parity(boost::asio::serial_port_base::parity::none),
    stop_bits(boost::asio::serial_port_base::stop_bits::one),
    timer(_io_service)
{
    std::cout<<"SerialLink constructor begin"<<std::endl;
    initOptions();
    std::cout<<"SerialLink constructor end"<<std::endl;
}

SerialLink::~SerialLink() {
    destroy();
}

void SerialLink::initOptions()
{
    // what baud rate do we communicate at
    serial_port.set_option(baud_rate);
    // how big is each "packet" of data (default is 8 bits)
    serial_port.set_option(character_size);
    // what flow control is used (default is none)
    serial_port.set_option(flow_control);
    // what parity is used (default is none)
    serial_port.set_option(parity);
    // how many stop bits are used (default is one)
    serial_port.set_option(stop_bits);
}

unsigned int SerialLink::getBaudRate() {
    boost::asio::serial_port_base::baud_rate temp_baud_rate;
    serial_port.get_option(temp_baud_rate);

    return temp_baud_rate.value();        
}

void SerialLink::setWebsocketLink(WebsocketLink *_websocketLink) {
    websocketLink = _websocketLink;
}

void SerialLink::restart(const boost::system::error_code& err) {
    std::cout<<"restart begin"<<std::endl;
    try {
        if (serial_port.is_open()) {
            std::cout<<"dest"<<std::endl;
            destroy();
            std::cout<<"dest. end."<<std::endl;
        }
        serial_port.open(device);
        std::cout<<"open end."<<std::endl;
        initOptions();
        readNewLine();
    } catch (std::exception e) {
        std::cout<<"e "<<e.what()<<std::endl;
        timer.expires_from_now(boost::posix_time::seconds(5));
        timer.async_wait(boost::bind(&SerialLink::restart, this, boost::asio::placeholders::error));
    }
    std::cout<<"restart end"<<std::endl;
}

void SerialLink::processLine(const boost::system::error_code& err, std::size_t bytes_transferred) {
    std::cout<<"process begin"<<std::endl;
    if (!err)
    {
        std::istream is(&read_buffer);
        std::string line;
        std::getline(is, line);

        std::cout<<"Line: "<<line<<std::endl;

        io_service.post(strand.wrap( boost::bind(&WebsocketLink::doSend, websocketLink, line) ));
        io_service.post(strand.wrap( boost::bind(&SerialLink::readNewLine, this) ));
    } else {
        timer.expires_from_now(boost::posix_time::seconds(5));
        timer.async_wait(boost::bind(&SerialLink::restart, this, boost::asio::placeholders::error));
        std::cout << "Error: " << err << std::endl;
    }

    std::cout<<"process end"<<std::endl;
}

void SerialLink::readNewLine() {
    std::cout<<"readline begin"<<std::endl;
    boost::asio::async_read_until(serial_port, read_buffer, "\n",
        boost::bind(&SerialLink::processLine, this,
            boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred
    ));
    std::cout<<"readline end"<<std::endl;
}

void SerialLink::writeHandler(const boost::system::error_code& error, std::size_t bytes_transferred) {
    std::cout<<"written "<<bytes_transferred<<" bytes to serial port"<<std::endl;
}

void SerialLink::doWrite(std::string& msg) {
    boost::asio::async_write(serial_port, boost::asio::buffer(msg), 
        boost::bind(
            &SerialLink::writeHandler,
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

void SerialLink::destroy() {
    serial_port.cancel();

    if (serial_port.is_open()) {
        serial_port.close();
    }
}
