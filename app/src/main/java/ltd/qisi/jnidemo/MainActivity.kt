package ltd.qisi.jnidemo

import android.os.Bundle
import android.view.View
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import ltd.qisi.jnidemo.databinding.ActivityMainBinding
import ltd.qisi.jnidemo.server.SoaServerImpl

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private lateinit var soaWindowManager: SoaWindowManager
    private lateinit var hacManager: SoaHACManager
    private val soaServerInterface by lazy {
        SoaServerImpl()
    }

    private lateinit var info: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        soaWindowManager = SoaWindowManager()
        hacManager = SoaHACManager()
        hacManager.initService()
        hacManager.setSoaServiceImpl(soaServerInterface)

        info = binding.sampleText
        // Example of a call to a native method
        binding.sampleText.text = soaWindowManager.stringFromJNI()
        binding.sampleText.append("\n=======\n")
        binding.sampleText.append(hacManager.stringFromJNI())
        binding.sampleText.append("\n=======\n")
        //sentAEvent
        hacManager.hacStatues = 3
        binding.sampleText.append(hacManager.hacStatues.toString())
    }

    fun onClick(view: View) {
        when (view) {
            binding.hac -> {
                val hacLevel = hacManager.getHACLevel()
                val temperature = hacManager.getTemperature()
                info.append("HAC LEVEL: $hacLevel\n")
                info.append("HAC temperature: $temperature\n")
            }
            binding.windows -> {
                //val stringFromJNI = soaWindowManager.stringFromJNI()
                //测试
                hacManager.doMethod("Test")
            }

            binding.initCallback -> {
                //JNI会回调SosServerImpl类
                hacManager.testJniCallBack()

            }
        }
    }
}