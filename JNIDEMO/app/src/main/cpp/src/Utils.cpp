//
// Created by Eason on 2022/7/22.
//

#include <commonDef.h>
#include "../header/Utils.h"

void Utils::set_evn() {
    char *cm_log_level = getenv("CM_LOG_LEVEL");
    char *cm_log_type = getenv("CM_LOG_TYPE");
    char *cm_config_file_path = getenv("CM_CONFIG_FILE_PATH");
    char *someip_config_file = getenv("SOMEIP_CONFIG_FILE");

    LOGI("CM_LOG_LEVEL: %s", cm_log_level);
    LOGI("CM_LOG_TYPE: %s", cm_log_type);
    LOGI("CM_CONFIG_FILE_PATH: %s", cm_config_file_path);
    LOGI("SOMEIP_CONFIG_FILE: %s", someip_config_file);

    //设置环境变量
    setenv("CM_CONFIG_FILE_PATH", "/vendor/etc/CalculatorClientConfig", 1);
    setenv("SOMEIP_CONFIG_FILE",
           "/vendor/etc/CalculatorClientSomeipConfig/someipd-ClientEthernetCommunicationConnector_1.json",
           1);
//    std::this_thread::sleep_for(std::chrono::seconds(30));

    cm_log_level = getenv("CM_LOG_LEVEL");
    cm_log_type = getenv("CM_LOG_TYPE");
    cm_config_file_path = getenv("CM_CONFIG_FILE_PATH");
    someip_config_file = getenv("SOMEIP_CONFIG_FILE");

    LOGI("=============================");
    LOGI("CM_LOG_LEVEL: %s", cm_log_level);
    LOGI("CM_LOG_TYPE: %s", cm_log_type);
    LOGI("CM_CONFIG_FILE_PATH: %s", cm_config_file_path);
    LOGI("SOMEIP_CONFIG_FILE: %s", someip_config_file);
}
