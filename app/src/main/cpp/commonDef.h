//
// Created by Eason on 2022/7/14.
//

#ifndef JNIDEMO_COMMONDEF_H
#define JNIDEMO_COMMONDEF_H

#ifndef LOG_TAG
#define LOG_TAG "SOA_JNI"
#endif //LOG_TAG

#include <string>
#include <android/log.h>

#define  LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define  LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define  LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define  LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)

#endif //JNIDEMO_COMMONDEF_H