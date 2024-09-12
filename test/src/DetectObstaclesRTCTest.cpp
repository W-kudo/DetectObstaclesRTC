// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  DetectObstaclesRTCTest.cpp
 * @brief ModuleDescription (test code)
 *
 */
// </rtc-template>

#include "DetectObstaclesRTCTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const detectobstaclesrtc_spec[] =
#else
static const char* detectobstaclesrtc_spec[] =
#endif
  {
    "implementation_id", "DetectObstaclesRTCTest",
    "type_name",         "DetectObstaclesRTCTest",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "Kudo",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
DetectObstaclesRTCTest::DetectObstaclesRTCTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_LRFdataOut("LRFdata", m_LRFdata),
    m_SignalIn("Signal", m_Signal)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
DetectObstaclesRTCTest::~DetectObstaclesRTCTest()
{
}



RTC::ReturnCode_t DetectObstaclesRTCTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("Signal", m_SignalIn);
  
  // Set OutPort buffer
  addOutPort("LRFdata", m_LRFdataOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t DetectObstaclesRTCTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t DetectObstaclesRTCTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DetectObstaclesRTCTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t DetectObstaclesRTCTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t DetectObstaclesRTCTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t DetectObstaclesRTCTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t DetectObstaclesRTCTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DetectObstaclesRTCTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DetectObstaclesRTCTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DetectObstaclesRTCTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DetectObstaclesRTCTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool DetectObstaclesRTCTest::runTest()
{
    return true;
}


extern "C"
{
 
  void DetectObstaclesRTCTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(detectobstaclesrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<DetectObstaclesRTCTest>,
                             RTC::Delete<DetectObstaclesRTCTest>);
  }
  
}
