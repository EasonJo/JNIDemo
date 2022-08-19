// ISOAServiceManager.aidl
package ltd.qisi.soa;
import ltd.qisi.soa.ServiceContext;
import ltd.qisi.soa.IServiceConnection;

/**
* Hal层Manager管理类
*/
//@VintfStability
interface ISOAServiceManager {

    /**
    * Get Remote Service
    */
    IBinder getService(in ServiceContext name);

    /**
    * 获取远端soa服务，并提供连接状态回调
    */
    IBinder getServiceWithStatus(in ServiceContext name, IServiceConnection serviceConnection);
}
