#ifndef SPEEDSTATUSCLIENT_H
#define SPEEDSTATUSCLIENT_H

#include <memory>
#include <QObject>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/SpeedStatusProxy.hpp>

using namespace v1::commonapi;

class SpeedStatusClient : public QObject {
    Q_OBJECT
    //Q_PROPERTY(int gear READ getGear NOTIFY gearChanged)
public:
    SpeedStatusClient();
    void run();

private:

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedStatusProxy<>> speedProxy_;

};

#endif // SPEEDSTATUSCLIENT_H
