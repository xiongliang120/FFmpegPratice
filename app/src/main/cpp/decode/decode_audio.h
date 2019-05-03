extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libavutil/frame.h>
#include <libavutil/mem.h>
#include <libavcodec/avcodec.h>
#include <common/CommonTools.h>
}

#ifndef AUDIO_INBUF_SIZE
#define AUDIO_INBUF_SIZE 20480
#endif

#ifndef AUDIO_REFILL_THRESH
#define AUDIO_REFILL_THRESH 4096
#endif

#define LOG_TAG "decode_audio"

static void decode(AVCodecContext *dec_ctx, AVPacket *pkt, AVFrame *frame,
                   FILE *outfile);
int decodeAudioByFFmpeg(char *intputPath, char *outputpath);