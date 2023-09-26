#include "SpeedServer.hpp"

#include <iostream>
#include <thread>

SpeedServer::SpeedServer() {
    CommonAPI::Runtime::setProperty("LogContext", "SS_S");
    CommonAPI::Runtime::setProperty("LogApplication", "SS_S");
    CommonAPI::Runtime::setProperty("LibraryBase", "SpeedServer");

    runtime = CommonAPI::Runtime::get();
    myService_ = std::make_shared<SpeedStubImpl>();

    std::string domain = "local";
    std::string instance = "commonapi.Speed";
    std::string connection = "service-sample";

    while (!runtime->registerService(domain, instance, myService_, connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Successfully Registered Service!" << std::endl;
}

void SpeedServer::run(int speed) {
    myService_->setSpeedAttribute(speed);
    std::cout << "Commonapi: "<< speed << std::endl;
}
