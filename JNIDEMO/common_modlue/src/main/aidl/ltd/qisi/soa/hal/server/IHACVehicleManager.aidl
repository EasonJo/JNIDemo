// IHACVehicleManager.aidl
package ltd.qisi.soa.hal.server;


/**
* 空调相关的Manager接口定义
*/
//@VintfStability
interface IHACVehicleManager {
    void setHacLevel(in int level);

    void setHacMode(in int model,int position);

    int getHacLevel();

    double getTempure();
}