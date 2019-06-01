#include "com_xiongliang_ffmpegpratice_ScaleVideo.h"
#include "scale_video.h"
JNIEXPORT void JNICALL Java_com_xiongliang_ffmpegpratice_ScaleVideo_scaleVideo
  (JNIEnv *env, jobject object, jstring inputVideoPath,jstring videoSize){
    char *inputVideoFilePath = (char *)(env->GetStringUTFChars(inputVideoPath, NULL));
    char *videoSizeChar = (char *)(env->GetStringUTFChars(videoSize, NULL));
    scaleVideo(inputVideoFilePath,videoSizeChar);
    env->ReleaseStringUTFChars(inputVideoPath,inputVideoFilePath);
    env->ReleaseStringUTFChars(videoSize,videoSizeChar);
}

