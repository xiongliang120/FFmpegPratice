#include "com_xiongliang_ffmpegpratice_DemuxAndDecode.h"
#include "demux_decode.h"
JNIEXPORT void JNICALL Java_com_xiongliang_ffmpegpratice_DemuxAndDecode_demuxAndDecode
  (JNIEnv *env, jobject obj, jstring inputPath, jstring outputAudioPath,jstring outputVideoPath){
    char *inputFile = (char *)(env->GetStringUTFChars(inputPath, NULL));
    char *outputAudioFile = (char *)(env->GetStringUTFChars(outputAudioPath, NULL));
    char *outputVideoFile = (char *)(env->GetStringUTFChars(outputVideoPath, NULL));
    demuxAndDecodeForFFmpeg(inputFile,outputAudioFile,outputVideoFile);
    env->ReleaseStringUTFChars(inputPath,inputFile);
    env->ReleaseStringUTFChars(outputAudioPath,outputAudioFile);
    env->ReleaseStringUTFChars(outputVideoPath,outputVideoFile);
}
