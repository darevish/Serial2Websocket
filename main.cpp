#include "SerialLink.hpp"
#include "WebsocketLink.hpp"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout<<"Usage: "<<argv[0]<<" <device>"<<std::endl;
        exit(1);
    }

    std::string device(argv[1]);
    boost::asio::io_service io_service;

    try {
        SerialLink serialLink(io_service, device);
        WebsocketLink websocketLink(io_service);

        serialLink.setWebsocketLink(&websocketLink);
        websocketLink.setSerialLink(&serialLink);

        io_service.run();
    } catch (std::exception& e) {
        std::cout<<e.what()<<std::endl;
    }

    return 0;
}
