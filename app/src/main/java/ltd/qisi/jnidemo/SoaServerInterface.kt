package ltd.qisi.jnidemo


/**
 * APP 作为 Server端,给其他域提供接口实现
 */
interface SoaServerInterface {
    fun getAndroidVersion(): Int

    fun getAndroidName(): String
}