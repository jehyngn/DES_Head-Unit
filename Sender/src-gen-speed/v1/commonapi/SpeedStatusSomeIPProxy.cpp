/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/SpeedStatusSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createSpeedStatusSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< SpeedStatusSomeIPProxy>(_address, _connection);
}

void initializeSpeedStatusSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.SpeedStatus:v1_0:commonapi.Speed",
        0x1238, 0x5679, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.SpeedStatus:v1_0",
        &createSpeedStatusSomeIPProxy);
}

INITIALIZER(registerSpeedStatusSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeSpeedStatusSomeIPProxy);
}

SpeedStatusSomeIPProxy::SpeedStatusSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          speed_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x80f4), CommonAPI::SomeIP::event_id_t(0x8100), CommonAPI::SomeIP::method_id_t(0xbbc), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, CommonAPI::SomeIP::method_id_t(0xbbd), true, static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr))
{
}

SpeedStatusSomeIPProxy::~SpeedStatusSomeIPProxy() {
    completed_.set_value();
}

SpeedStatusSomeIPProxy::SpeedAttribute& SpeedStatusSomeIPProxy::getSpeedAttribute() {
    return speed_;
}


void SpeedStatusSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> SpeedStatusSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace commonapi
} // namespace v1
