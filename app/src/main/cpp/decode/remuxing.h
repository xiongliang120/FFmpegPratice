/**
 * 转封装, mp4, flv, avi等文件格式之间的转换
 */
#ifndef FFMPEGPRATICE_REMUXING_H
#define FFMPEGPRATICE_REMUXING_H

extern "C"{
#include <libavutil/timestamp.h>
#include <libavformat/avformat.h>
};

#include "CommonTools.h"

static void log_packet(const AVFormatContext *fmt_ctx, const AVPacket *pkt, const char *tag);
int remuxing(char* inputPath,char* outputPath);

#endif //FFMPEGPRATICE_REMUXING_H
