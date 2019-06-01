#include "com_xiongliang_ffmpegpratice_EncodeVideo.h"
#include "encodeVideo.h"
JNIEXPORT void JNICALL Java_com_xiongliang_ffmpegpratice_EncodeVideo_encodeVideo
  (JNIEnv *env, jobject object, jstring outputVideoPath,jstring codecName){
    char *outputVideoFilePath = (char *)(env->GetStringUTFChars(outputVideoPath, NULL));
    char *codecNameChar = (char *)(env->GetStringUTFChars(codecName, NULL));
    encodeVideoForFFmpeg(outputVideoFilePath,codecNameChar);
    env->ReleaseStringUTFChars(outputVideoPath,outputVideoFilePath);
    env->ReleaseStringUTFChars(codecName,codecNameChar);
}
