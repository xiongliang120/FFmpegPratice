#ifndef FFMPEGPRATICE_RESAMPLE_H
#define FFMPEGPRATICE_RESAMPLE_H
extern "C"{
#include <libavutil/opt.h>
#include <libavutil/channel_layout.h>
#include <libavutil/samplefmt.h>
#include <libswresample/swresample.h>
};

#include "CommonTools.h"

static int get_format_from_sample_fmt(const char **fmt,
                                      enum AVSampleFormat sample_fmt);

static void fill_samples(double *dst, int nb_samples, int nb_channels, int sample_rate, double *t);

int resampleForFFmpeg(char* filePath);

#endif //FFMPEGPRATICE_RESAMPLE_H
