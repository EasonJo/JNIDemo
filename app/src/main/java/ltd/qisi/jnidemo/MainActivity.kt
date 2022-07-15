package ltd.qisi.jnidemo

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import ltd.qisi.jnidemo.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private lateinit var soaManager: SoaWindowManager
    private lateinit var hacManager: SoaHACManager

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        soaManager = SoaWindowManager()
        hacManager = SoaHACManager()
        hacManager.initService()
        var i = 0
        hacManager.setSoaServiceImpl(object : SoaServerInterface {
            override fun getAndroidVersion(): Int = ++i

            override fun getAndroidName(): String = "SOA Server From APP: ${++i}"
        })

        // Example of a call to a native method
        binding.sampleText.text = soaManager.stringFromJNI()
        binding.sampleText.append("\n=======\n")
        binding.sampleText.append(hacManager.stringFromJNI())
        binding.sampleText.append("\n=======\n")
        hacManager.hacStatues = 3
        binding.sampleText.append(hacManager.hacStatues.toString())

    }
}