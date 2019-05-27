#ifndef FFMPEGPRATICE_ENCODEAUDIO_H
#define FFMPEGPRATICE_ENCODEAUDIO_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
extern "C"{
#include <libavcodec/avcodec.h>
#include <libavutil/channel_layout.h>
#include <libavutil/common.h>
#include <libavutil/frame.h>
#include <libavutil/samplefmt.h>
};
#include <common/CommonTools.h>
#define LOG_TAG "encode_audio"
static int check_sample_fmt(const AVCodec *codec, enum AVSampleFormat sample_fmt);
static int select_sample_rate(const AVCodec *codec);
static int select_channel_layout(const AVCodec *codec);
static void encode(AVCodecContext *ctx, AVFrame *frame, AVPacket *pkt,FILE *output);
int encodeAudioForFFmpeg(char* encodeAudioPath);

#endif //FFMPEGPRATICE_ENCODEAUDIO_H
