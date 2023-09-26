#include "GearSelectionClient.hpp"

#include <iostream>
#include <thread>

using namespace v1::commonapi;

GearSelectionClient::GearSelectionClient() {
    CommonAPI::Runtime::setProperty("LogContext", "GS_C");
    CommonAPI::Runtime::setProperty("LogApplication", "GS_C");
    CommonAPI::Runtime::setProperty("LibraryBase", "GearSelection");

    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "commonapi.Gear";
    std::string connection = "client-gear";

    gearProxy_ = runtime->buildProxy<GearSelectionProxy>(domain, instance, connection);
}

void GearSelectionClient::run() {
    std::cout << "Waiting for GearSelection service to become available." << std::endl;
    while (!gearProxy_->isAvailable()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    gearProxy_->getGearAttribute().getChangedEvent().subscribe(
        [&](const int32_t& gear){std::cout << gear << std::endl;}
    );

}

