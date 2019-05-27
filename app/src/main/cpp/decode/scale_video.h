

#ifndef FFMPEGPRATICE_SCALE_VIDEO_H
#define FFMPEGPRATICE_SCALE_VIDEO_H
#define __STDC_CONSTANT_MACROS
extern "C"{
#include <libavutil/imgutils.h>
#include <libavutil/parseutils.h>
#include <libswscale/swscale.h>
}
#include "CommonTools.h"
#define LOG_TAG "scalevideo"

static void fill_yuv_image(uint8_t *data[4], int linesize[4],
                           int width, int height, int frame_index);

int scaleVideo(char* inputVideoPath,char* inputVideoSize);

#endif //FFMPEGPRATICE_SCALE_VIDEO_H
