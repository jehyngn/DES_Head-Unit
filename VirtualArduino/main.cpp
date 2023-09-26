#include "CanSender.hpp"
#include <unistd.h>
#include <iostream>

int main() {
    CanSender sender("can0");
    float rpm = 0.0f;
    float speed = 0.0f;

    while (true) {
        sender.sendData(rpm, speed);
        std::cout << "Sent rpm: " << rpm << " Sent speed: " << speed << std::endl;
        rpm += 1.0f;
        speed += 1.0f;
        sleep(1); 
    }

    return 0;
}
