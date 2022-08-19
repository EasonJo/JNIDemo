package ltd.qisi.soa.hal.server;

import ltd.qisi.soa.ServiceContext;
import ltd.qisi.soa.app.server.ITestInterface;

/**
* 模拟Hal层一个业务Manager
*/
//@VintfStability
interface ISoaCall{
    oneway void startService(in ServiceContext service);

    oneway void stopService(in ServiceContext service);

    /**
    * 获取field对应的value
    */
    int getValue(in String field);

    /**
    * 客户端发送一个事件
    */
    void sendEvent(in int event);

    /**
    * 注册客户端的实现,HAL层回调
    */
    oneway void registClientServerImpl(ITestInterface callBack);

    /**
    * 发布客户端的服务
    */
    void publishAsServer();
}