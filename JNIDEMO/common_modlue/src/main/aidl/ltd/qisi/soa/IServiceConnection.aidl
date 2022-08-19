// IServiceConnection.aidl
package ltd.qisi.soa;


//@VintfStability
interface IServiceConnection {

    /**
    * 远程服务连接回调
    */
    void onServiceConntect();

    /**
    * 远程服务断开回调
    */
    void onServiceDisConnect();
}