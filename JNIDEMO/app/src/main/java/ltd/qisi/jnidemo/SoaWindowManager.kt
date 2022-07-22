package ltd.qisi.jnidemo

class SoaWindowManager {

    /**
     * A native method that is implemented by the 'jnidemo' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun initService()

    external fun stopService()

    fun windowsChange(mode: Int) {

    }

    companion object {
        // Used to load the 'jnidemo' library on application startup.
        init {
            System.loadLibrary("window_soa")
        }
    }
}