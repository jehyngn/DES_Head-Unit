#include "CanReceive.hpp"
#include "SpeedServer.hpp"
#include <iostream>

int main() {
    CanReceive receiver("can0");
    SpeedServer speed_server;
    //RPMServer rpm_server();

    while (true) {
        float rpm, speed;
        if (receiver.getData(rpm, speed)) {
            speed_server.run(speed);
            //rpm_server.run(speed)
            std::cout << "Speed: " << speed << std::endl;
            //std::cout << "RPM: " << rpm << ", Speed: " << speed << std::endl;
        } else {
            std::cout << "Error receiving data." << std::endl;
        }

    }

    return 0;
}
