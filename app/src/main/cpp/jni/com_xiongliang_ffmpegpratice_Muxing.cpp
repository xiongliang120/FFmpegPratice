#include "com_xiongliang_ffmpegpratice_Muxing.h"
#include "muxing.h"
JNIEXPORT void JNICALL Java_com_xiongliang_ffmpegpratice_Muxing_muxing
  (JNIEnv *env , jobject obj, jstring inputAudioPath, jstring inputVideoPath, jstring outputPath){
  char *inputAudioFile = (char *)(env->GetStringUTFChars(inputAudioPath, NULL));
  char *inputVideoFile = (char *)(env->GetStringUTFChars(inputVideoPath, NULL));
  char *outputFile = (char *)(env->GetStringUTFChars(outputPath, NULL));
  muxing(inputAudioFile,inputVideoFile,outputFile);
  env->ReleaseStringUTFChars(inputAudioPath,inputAudioFile);
  env->ReleaseStringUTFChars(inputVideoPath,inputVideoFile);
  env->ReleaseStringUTFChars(outputPath,outputFile);
}


