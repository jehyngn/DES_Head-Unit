#ifndef SPEEDSERVER_HPP_
#define SPEEDSERVER_HPP_

#include <memory>
#include <CommonAPI/CommonAPI.hpp>
#include "SpeedStubImpl.hpp"

using namespace v1::commonapi;

class SpeedServer {
public:
    SpeedServer();
    void run(int speed);
    
private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedStubImpl> myService_;
    
};

#endif 
