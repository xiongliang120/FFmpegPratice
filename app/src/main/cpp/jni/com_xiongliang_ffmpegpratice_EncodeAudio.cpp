#include "com_xiongliang_ffmpegpratice_EncodeAudio.h"
#include "encodeAudio.h"
JNIEXPORT void JNICALL Java_com_xiongliang_ffmpegpratice_EncodeAudio_encodeAudio
  (JNIEnv *env, jobject object, jstring outputAudioPath){
    char *outputAudioFilePath = (char *)(env->GetStringUTFChars(outputAudioPath, NULL));
    encodeAudioForFFmpeg(outputAudioFilePath);
    env->ReleaseStringUTFChars(outputAudioPath,outputAudioFilePath);
}

