//需要放到文件最上面,因为头文件中回去判断这个宏是否存在,不存在就使用默认的TAG.
#define LOG_TAG "WINDOWS_SOA_NATIVE"

#include <jni.h>
#include <string>
#include "header/commonDef.h"

/**
 * Print android log
 * @param log
 */

extern "C"
JNIEXPORT jstring JNICALL
Java_ltd_qisi_jnidemo_SoaWindowManager_stringFromJNI(JNIEnv *env, jobject thiz) {
    std::string hello = "Hello From Window SOA C++";
    LOGI("init Window soa native!");
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaWindowManager_initService(JNIEnv *env, jobject thiz) {
    //print_log("start Native Service.");
    LOGI("init Window soa native");
}
extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaWindowManager_stopService(JNIEnv *env, jobject thiz) {
//    print_log("stop Native Service");
    LOGI("Stop Window SOA Natvie.");
}