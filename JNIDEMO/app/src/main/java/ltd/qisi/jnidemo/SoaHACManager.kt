package ltd.qisi.jnidemo

class SoaHACManager {

    /**
     * field
     */
    var hacStatues: Int = 0
        set(value) {
            if (field != value) {
                sendEvent(value)
            }
        }

    /**
     * A native method that is implemented by the 'jnidemo' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    /**
     * 初始化服务
     */
    external fun initService()

    /**
     * 停止服务
     */
    external fun stopService()

    /**
     * 方法 Call
     */
    external fun doMethod(method: String)

    external fun getTemperature(): Float

    external fun getHACLevel(): Int

    private external fun sendEvent(event: Int)

    external fun testJniCallBack()

    /**
     * 将能力暴露给其他域,APP 作为 Server,在soaServerInterface中提供API实现.
     */
    external fun setSoaServiceImpl(soaServerInterface: SoaServerInterface)

    /**
     * 提供服务的方法,JNI会调用此方法
     */
    fun serverImpl(mode: Int): String {
        return "I am APP."
    }

    /**
     * 提供服务的方法,JNI会调用此方法
     */
    fun serverImpl(): Int {
        return 1
    }

    companion object {
        // Used to load the 'jnidemo' library on application startup.
        init {
            System.loadLibrary("hac_soa")
        }
    }
}