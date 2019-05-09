#include "com_xiongliang_ffmpegpratice_DecodeVideo.h"
#include "decode_video.h"
JNIEXPORT void JNICALL Java_com_xiongliang_ffmpegpratice_DecodeVideo_devodeVideo
  (JNIEnv *env, jobject obj, jstring inputPath, jstring outputPath){
    char *inputFile = (char *)(env->GetStringUTFChars(inputPath, NULL));
    char *outputFile = (char *) env->GetStringUTFChars(outputPath,NULL);
    decodeVideoByFFmpeg(inputFile,outputFile);
    env->ReleaseStringUTFChars(inputPath,inputFile);
    env->ReleaseStringUTFChars(outputPath,outputFile);
}

