#include <jni.h>
#include <string>
#include "commonDef.h"
#include <thread>

//
// Created by Eason on 2022/7/14.
//

#define LOG_TAG "HAC_SOA_NATIVE"

JavaVM *javaVm = nullptr; //全局指针,用于保存JNI对象
jobject pJobject = nullptr;

jobject soa_server_interface = nullptr;

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    javaVm = vm;
    LOGI("JNI_OnLoad!");
    return JNI_VERSION_1_6;
}

extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_initService(JNIEnv *env, jobject thiz) {
    LOGI("init HAC soa native");
    env->GetJavaVM(&javaVm); //保存全局对象
    pJobject = env->NewGlobalRef(thiz);
}

extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_stopService(JNIEnv *env, jobject thiz) {
    LOGI("init HAC soa native");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_stringFromJNI(JNIEnv *env, jobject thiz) {
    std::string str = "Hello From HAC SOA Native.";
    LOGI("init HAC soa native!");
    return env->NewStringUTF(str.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_sendEvent(JNIEnv *env, jobject thiz, jint event) {
    //do sent soaEvent
    LOGI("send event %d to soa server!", event);
}

extern void testCallBack();

extern "C"
JNIEXPORT jint JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_getHACStatus(JNIEnv *env, jobject thiz) {
    //从 SOA 读取 HAC 的状态,返回给应用层
    testCallBack();
    return 1;
}
extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_doMethod(JNIEnv *env, jobject thiz, jstring pJstring) {
    //method call.
    auto s = env->GetStringUTFChars(pJstring, 0);
    LOGI("do method call %s to soa server!", std::string(s).c_str());
}

bool mNeedDetach = JNI_FALSE;

//定义一个回调函数
using Callback = std::function<std::string(JNIEnv *env, jobject jObj)>;

std::string call_from_thread(jobject jObj, const Callback &pFunction) {
    //从 Java 层获取 value
    JNIEnv *env;
    //获取当前native线程是否有没有被附加到jvm环境中
    jint getEnvStat = javaVm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
    if (getEnvStat == JNI_EDETACHED) {
        //如果没有， 主动附加到jvm环境中，获取到env
        if (javaVm->AttachCurrentThread(&env, nullptr) != 0) {
            return "";
        }
        mNeedDetach = JNI_TRUE;
    }

    if (jObj == nullptr || javaVm == nullptr) {
        LOGE("pJobject is Null!!!");
        return "";
    }

    std::string s = pFunction(env, jObj);
    if (!s.empty()) {
        LOGI("%s", s.c_str());
    }

    //释放当前线程
    if (mNeedDetach) {
        javaVm->DetachCurrentThread();
    }
    env = nullptr;
    return s;
}

void run() {
    std::string a = call_from_thread(
            pJobject,
            [](JNIEnv *env, jobject jobject1) -> std::string {
                //通过全局变量g_obj 获取到要回调的类
                jclass javaClass = env->GetObjectClass(pJobject);
                if (javaClass == nullptr) {
                    LOGI("Unable to find class");
                    javaVm->DetachCurrentThread();
                    return "";
                }

                //获取要回调的方法ID
                jmethodID javaCallbackId = env->GetMethodID(javaClass,
                                                            "serverImpl",
                                                            "(I)Ljava/lang/String;");
//        jmethodID javaCallbackId1 = env->GetMethodID(javaClass,
//                                                    "serverImpl", "()I");
                if (javaCallbackId == nullptr) {
                    LOGD("Unable to find method:serverImpl");
                    return "";
                }
                //执行回调
//                jstring method = static_cast<jstring>(env->CallObjectMethod(
//                        pJobject, javaCallbackId, 1));
                auto method = (jstring) env->CallObjectMethod(pJobject, javaCallbackId, 1);
                const char *result = env->GetStringUTFChars(method, 0);
                return {result};
            });
    LOGD("Call From SOA Client!!!! %s", a.c_str());
    int i = 0;
    while (i < 50) {
        LOGD("Call From SOA Client!!!! %d", i++);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        call_from_thread(soa_server_interface, [](JNIEnv *env, jobject jObj) -> std::string {
            if (env != nullptr) {
                jclass soa_interface = env->GetObjectClass(jObj);
                if (soa_interface == nullptr) {
                    LOGI("Unable to find class");
                    javaVm->DetachCurrentThread();
                    return "";
                }
                jmethodID getAndroidVersion = env->GetMethodID(soa_interface, "getAndroidVersion","()I");
                jmethodID getAndroidName = env->GetMethodID(soa_interface, "getAndroidName",
                                                            "()Ljava/lang/String;");
                if (getAndroidVersion == nullptr || getAndroidName == nullptr) {
                    LOGW("Unable to find method:getAndroidVersion or getAndroidName");
                    return "";
                }
                jint version = env->CallIntMethod(jObj, getAndroidVersion);
                jstring name = static_cast<jstring>(env->CallObjectMethod(jObj, getAndroidName));
                LOGD("getAndroidVersion: %d", version);
                LOGD("getAndroidName: %s", env->GetStringUTFChars(name, 0));
            }
            return "";
        });
    }
}

void testCallBack() {
    std::thread thread(run);
    thread.detach();
}


extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_setSoaServiceImpl(JNIEnv *env, jobject thiz,
                                                      jobject soaServerInterface) {
    ::soa_server_interface = env->NewGlobalRef(soaServerInterface);
}