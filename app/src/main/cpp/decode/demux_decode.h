//
// Created by xiongliang on 2019/5/11.
//

#ifndef FFMPEGPRATICE_MASTER_DEMUX_DECODE_H
#define FFMPEGPRATICE_MASTER_DEMUX_DECODE_H
#define __STDC_CONSTANT_MACROS

extern "C"{
#include <libavutil/imgutils.h>
#include <libavutil/samplefmt.h>
#include <libavutil/timestamp.h>
#include <libavformat/avformat.h>
}
#include <common/CommonTools.h>
#define LOG_TAG "demux_decode"


static int decode_packet(int *got_frame, int cached);

static int open_codec_context(int *stream_idx,
                              AVCodecContext **dec_ctx, AVFormatContext *fmt_ctx, enum AVMediaType type);

static int get_format_from_sample_fmt(const char **fmt,
                                      enum AVSampleFormat sample_fmt);

int demuxAndDecodeForFFmpeg (char *inputPath, char *outputAudioPath,char *outputVideoPath);

#endif //FFMPEGPRATICE_MASTER_DEMUX_DECODE_H
