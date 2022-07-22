//
// Created by eason on 2022/7/15.
//
#define LOG_TAG "SoaHacImpl"

#include "header/calculator_client.h"
#include <thread>
#include "header/SoaInterface.h"
#include "header/commonDef.h"
#include "header/SoaHacImpl.h"

float SoaHacImpl::getTemperature() {
    LOGI("Read HAC temperature form HAC.");
    //从soa的client调用温度
    return 23.5;
}

int SoaHacImpl::getHacLevel() {
    LOGI("Read HAC LEVEL form HAC.");
    return 3;
}

void SoaHacImpl::initSoaHAC() {
    //todo 初始化
    LOGD("initSoaHAC......");
}

//SoaHacImpl::~SoaHacImpl() {
//    LOGI("~SoaHacImpl");
//    //释放资源
//}

SoaHacImpl::SoaHacImpl() {
    //todo 初始化
    int i = 0;
    //soaApClient = new SoaApClient()
}

void SoaHacImpl::doTest() {
    LOGI("Jus Do Test");

    char *cm_log_level = getenv("CM_LOG_LEVEL");
    char *cm_log_type = getenv("CM_LOG_TYPE");
    char *cm_config_file_path = getenv("CM_CONFIG_FILE_PATH");
    char *someip_config_file = getenv("SOMEIP_CONFIG_FILE");

    LOGI("CM_LOG_LEVEL: %s", cm_log_level);
    LOGI("CM_LOG_TYPE: %s", cm_log_type);
    LOGI("CM_CONFIG_FILE_PATH: %s", cm_config_file_path);
    LOGI("SOMEIP_CONFIG_FILE: %s", someip_config_file);

    //设置环境变量
    //setenv("CM_CONFIG_FILE_PATH", "",0);
    //setenv("SOMEIP_CONFIG_FILE", "",0);
    CalculatorClient::ClientAct clientAct;
    std::thread t([&]() {
        clientAct.Init();
        std::this_thread::sleep_for(std::chrono::seconds(10));
        clientAct.Act();
        std::this_thread::sleep_for(std::chrono::seconds(20));
        clientAct.Stop();
    });
    t.detach();
}

