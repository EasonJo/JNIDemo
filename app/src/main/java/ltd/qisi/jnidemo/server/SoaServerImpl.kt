package ltd.qisi.jnidemo.server

import ltd.qisi.jnidemo.SoaServerInterface

/**
 * 模拟Android APP端作为Server提供API接口,此类会被Native层调用
 */
class SoaServerImpl : SoaServerInterface {

    private var i = 0
    override fun getAndroidVersion(): Int = i++

    override fun getAndroidName(): String = "SOA Server From APP: ${++i}"
}