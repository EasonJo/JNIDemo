package ltd.qisi.soa.app.server;


//@VintfStability
interface ITestInterface{

    /**
    * 打开导航
    */
   oneway void openNavi();

    /**
    * 播放TTS
    */
    oneway void speakTTS(in String tts);

    /**
    * 获取当前位置信息
    */
    Map getCurrentPosition();
}