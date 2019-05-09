//
// Created by 123 on 2019/5/9.
//

#ifndef FFMPEGPRATICE_DECODE_VIDEO_H
#define FFMPEGPRATICE_DECODE_VIDEO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern "C"{
   #include <libavcodec/avcodec.h>
};
#include <common/CommonTools.h>
#define LOG_TAG "decode_video"
#define INBUF_SIZE 4096

static void pgm_save(unsigned char *buf, int wrap, int xsize, int ysize,
                     char *filename);

static void decode(AVCodecContext *dec_ctx, AVFrame *frame, AVPacket *pkt,
                   const char *filename);

int decodeVideoByFFmpeg(char *inputPath, char *outputPath);



#endif
