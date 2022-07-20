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

