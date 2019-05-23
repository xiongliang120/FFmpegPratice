#include "com_xiongliang_ffmpegpratice_Remuxing.h"
#include "remuxing.h"
JNIEXPORT void JNICALL Java_com_xiongliang_ffmpegpratice_Remuxing_remuxing
  (JNIEnv *env, jobject object, jstring inputPath, jstring ouputPath){
    char *inputFilePath = (char *)(env->GetStringUTFChars(inputPath, NULL));
    char *outputFilePath = (char *)(env->GetStringUTFChars(ouputPath, NULL));
    remuxing(inputFilePath,outputFilePath);
    env->ReleaseStringUTFChars(inputPath,inputFilePath);
    env->ReleaseStringUTFChars(ouputPath,outputFilePath);
}

