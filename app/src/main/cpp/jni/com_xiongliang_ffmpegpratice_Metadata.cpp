#include "com_xiongliang_ffmpegpratice_Metadata.h"
#include "metadata.h"
JNIEXPORT void JNICALL Java_com_xiongliang_ffmpegpratice_Metadata_metadata
  (JNIEnv *env, jobject object, jstring inputFilePath){
    char *inputFile = (char *)(env->GetStringUTFChars(inputFilePath, NULL));
    metadata(inputFile);
    env->ReleaseStringUTFChars(inputFilePath,inputFile);
}


