# SOA架构下JNIDemo

SOA架构下的JNI学习Demo

1. App调用 JNI;
2. JNI 子线程回到 APP;
3. APP 暴露接口给 JNI 调用;
4. 模拟 SOA 架构;

## APP使用第三方的SO

从Android12开始，如果APP需要调用非公开的三方SO，需要在功能清单文件中加入以下声明

```xml

<uses-native-library android:name="lib name" android:required="true" />
```

## 添加其他原生库

同时在系统中增加三方的SO，需要为期配置白名单，并且提供64和32位的库 参考官方文档：
[添加其他原生库](https://source.android.com/devices/tech/config/namespaces_libraries?hl=zh-cn#adding-additional-native-libraries)

如果不再APP中集成这些依赖的SO,则需要将这些SO预编译到ROM中,路径为: vendor/lib64,vendor/lib,并修改vendor/etc/public.libraries.txt文件,添加需要暴露的so文件
```shell
libqti-perfd-client.so
libadsprpc.so
libcdsprpc.so
libsdsprpc.so
liblistensoundmodel2.so
libOpenCL.so
libara_com.so
libara_core.so
libara_log.so
libCrc.so
libddscore.so
libddscpp.so
libdp_adapter.so
libdlt.so
libE2ELib.so
libE2EXf_CM.so
libE2EXf_Static.so
libhwcrc.so
libJsonParser.so
liblogging.so
libplog.so
librtf_cm.so
libsecoc_library.so
libsecurec.so
libsomeip.so
libvcc_ddsdriver.so
libvcc_someipdriver.so
libvrtf_vcc.so
```

## 编译指南

1. 先下载HUAWEI的sdk(找同事要),将三个文件(两个压缩包,一个脚本)放到同一目录,然后执行脚本；
2. 下载NDK,Cmake;
3. 配置HUAWEI的SDK的系统路径，增加一个系统环境变量或者在CmakeLists.txt增加中声明HUAWEI的sdk的路径；

```cmake
#需要修改此变量，指定你的电脑上SDK的路径
#set(HUAWEI_SDK /Users/eason/SDK/huawei)
set(HUAWEI_SDK /home/eason/Android/huawei_sdk)
```

3. Sync代码,检查头文件是否还报错,如果报错,则证明include的路径有问题,继续分析sdk的路径是否正确;
4. sync build;