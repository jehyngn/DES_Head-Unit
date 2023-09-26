/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/GearSelectionSomeIPProxy.hpp>

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

std::shared_ptr<CommonAPI::SomeIP::Proxy> createGearSelectionSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< GearSelectionSomeIPProxy>(_address, _connection);
}

void initializeGearSelectionSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.GearSelection:v1_0:commonapi.Gear",
        0x1237, 0x5678, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.GearSelection:v1_0",
        &createGearSelectionSomeIPProxy);
}

INITIALIZER(registerGearSelectionSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeGearSelectionSomeIPProxy);
}

GearSelectionSomeIPProxy::GearSelectionSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          gear_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x80f3), CommonAPI::SomeIP::event_id_t(0x80ff), CommonAPI::SomeIP::method_id_t(0xbbb), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, CommonAPI::SomeIP::method_id_t(0xbbc), true, static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr))
{
}

GearSelectionSomeIPProxy::~GearSelectionSomeIPProxy() {
    completed_.set_value();
}

GearSelectionSomeIPProxy::GearAttribute& GearSelectionSomeIPProxy::getGearAttribute() {
    return gear_;
}


void GearSelectionSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> GearSelectionSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace commonapi
} // namespace v1
