package ltd.qisi.jnidemo.server

import android.util.Log
import ltd.qisi.jnidemo.SoaServerInterface

/**
 * 模拟Android APP端作为Server提供API接口,此类会被Native层调用
 */
class SoaServerImpl : SoaServerInterface {

    private var i = 0
    override fun getAndroidVersion(): Int {
        Log.d("SoaServerImpl", "GetAndroidVersion ThreadID: ${Thread.currentThread().id}")
        return i++
    }

    override fun getAndroidName(): String {
        Log.d("SoaServerImpl", "GetAndroidName ThreadID: ${Thread.currentThread().id}")
        return "SOA Server From APP: ${++i}"
    }
}