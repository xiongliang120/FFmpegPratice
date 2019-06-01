
#ifndef FFMPEGPRATICE_ENCODEVIDEO_H
#define FFMPEGPRATICE_ENCODEVIDEO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern "C"{
#include <libavcodec/avcodec.h>
#include <libavutil/opt.h>
#include <libavutil/imgutils.h>
};

#include <common/CommonTools.h>
#define LOG_TAG "encode_video"


static void encode(AVCodecContext *enc_ctx, AVFrame *frame, AVPacket *pkt,
                   FILE *outfile);
int encodeVideoForFFmpeg(char* outputVideoPath,char* codecName);

#endif //FFMPEGPRATICE_ENCODEVIDEO_H
