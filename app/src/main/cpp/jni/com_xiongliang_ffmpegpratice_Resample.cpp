#include "com_xiongliang_ffmpegpratice_Resample.h"
#include "resample.h"
JNIEXPORT void JNICALL Java_com_xiongliang_ffmpegpratice_Resample_resample
  (JNIEnv *env, jobject object, jstring inputAudioPath){
    char *inputAudioFilePath = (char *)(env->GetStringUTFChars(inputAudioPath, NULL));
    resampleForFFmpeg(inputAudioFilePath);
    env->ReleaseStringUTFChars(inputAudioPath,inputAudioFilePath);
}

