#include "SpeedStatusClient.hpp"

#include <iostream>
#include <thread>

using namespace v1::commonapi;

SpeedStatusClient::SpeedStatusClient() {
    CommonAPI::Runtime::setProperty("LogContext", "SS_C");
    CommonAPI::Runtime::setProperty("LogApplication", "SS_C");
    CommonAPI::Runtime::setProperty("LibraryBase", "SpeedStatus");

    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "commonapi.Speed";
    std::string connection = "client-speed";

    speedProxy_ = runtime->buildProxy<SpeedStatusProxy>(domain, instance, connection);
}

void SpeedStatusClient::run() {
    std::cout << "Waiting for GearSelection service to become available." << std::endl;
    while (!speedProxy_->isAvailable()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    speedProxy_->getSpeedAttribute().getChangedEvent().subscribe(
        [&](const float& speed){std::cout << speed << std::endl;}
        );

    /*
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    */
}

