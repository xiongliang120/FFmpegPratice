#include "com_xiongliang_ffmpegpratice_DecodeAudio.h"
#include <decode/decode_audio.h>

JNIEXPORT void JNICALL Java_com_xiongliang_ffmpegpratice_DecodeAudio_devodeAudio
(JNIEnv *env, jobject object, jstring inputPath, jstring outputPath){
    char *input = (char *)(env->GetStringUTFChars(inputPath, NULL));
    char *output = (char *)(env->GetStringUTFChars(outputPath, NULL));
    decodeAudioByFFmpeg(input,output);
    env->ReleaseStringUTFChars(inputPath,input);
    env->ReleaseStringUTFChars(outputPath,output);
}
