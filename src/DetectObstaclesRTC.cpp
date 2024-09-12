// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  DetectObstaclesRTC.cpp
 * @brief ModuleDescription
 *
 */
// </rtc-template>

#include "DetectObstaclesRTC.h"
using namespace std;

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const detectobstaclesrtc_spec[] =
#else
static const char* detectobstaclesrtc_spec[] =
#endif
  {
    "implementation_id", "DetectObstaclesRTC",
    "type_name",         "DetectObstaclesRTC",
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
DetectObstaclesRTC::DetectObstaclesRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_LRFdataIn("LRFdata", m_LRFdata),
    m_SignalOut("Signal", m_Signal)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
DetectObstaclesRTC::~DetectObstaclesRTC()
{
}



RTC::ReturnCode_t DetectObstaclesRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("LRFdata", m_LRFdataIn);
  
  // Set OutPort buffer
  addOutPort("Signal", m_SignalOut);

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t DetectObstaclesRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t DetectObstaclesRTC::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DetectObstaclesRTC::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t DetectObstaclesRTC::onActivated(RTC::UniqueId /*ec_id*/)
{
    cout << "RecognizeObstaclesRTC activated" << endl;
    count = 0;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t DetectObstaclesRTC::onDeactivated(RTC::UniqueId /*ec_id*/)
{
    cout << "RecognizeObstaclesRTC deactivated" << endl;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t DetectObstaclesRTC::onExecute(RTC::UniqueId /*ec_id*/)
{
    if (m_LRFdataIn.isNew()) {
        m_LRFdataIn.read();

        //cout << m_LRFdata.ranges.length() << endl;
        /*for (int i = 0;i < m_LRFdata.ranges.length();i++)
            cout << "Index" << i << ":" << m_LRFdata.ranges[i] << endl;*/

        //cout << "Index" << 0 << ":" << m_LRFdata.ranges[0] << endl;
        if (m_LRFdata.ranges[0] > 0 && m_LRFdata.ranges[0] < 0.5) {
            int x = 0;
            m_Signal.data = x;
            m_SignalOut.write();
        }
        else {
            
            count++;
            if (count = 4000)
            {
                // 乱数のシードを初期化
                srand(static_cast<unsigned int>(std::time(nullptr)));

                // 0～4の乱数を生成
                new_random_number = std::rand() % 5;

                // 生成された乱数を出力
				random_number = new_random_number;

				count = 0;
            }

            m_Signal.data = random_number;
			cout << "random_number" << m_Signal.data << endl;
            m_SignalOut.write();
        }
    }
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t DetectObstaclesRTC::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DetectObstaclesRTC::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DetectObstaclesRTC::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DetectObstaclesRTC::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DetectObstaclesRTC::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void DetectObstaclesRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(detectobstaclesrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<DetectObstaclesRTC>,
                             RTC::Delete<DetectObstaclesRTC>);
  }
  
}
