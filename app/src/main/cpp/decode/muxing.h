
#ifndef FFMPEGPRATICE_MASTER_MUXING_H
#define FFMPEGPRATICE_MASTER_MUXING_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
extern "C"{
#include <libavutil/avassert.h>
#include <libavutil/channel_layout.h>
#include <libavutil/opt.h>
#include <libavutil/mathematics.h>
#include <libavutil/timestamp.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
}


#define STREAM_DURATION   10.0
#define STREAM_FRAME_RATE 25 /* 25 images/s */
#define STREAM_PIX_FMT    AV_PIX_FMT_YUV420P /* default pix_fmt */
#define SCALE_FLAGS SWS_BICUBIC
// a wrapper around a single output AVStream
typedef struct OutputStream {
    AVStream *st;
    AVCodecContext *enc;
    /* pts of the next frame that will be generated */
    int64_t next_pts;
    int samples_count;
    AVFrame *frame;
    AVFrame *tmp_frame;
    float t, tincr, tincr2;
    struct SwsContext *sws_ctx;
    struct SwrContext *swr_ctx;
} OutputStream;

static void log_packet(const AVFormatContext *fmt_ctx, const AVPacket *pkt);
static int write_frame(AVFormatContext *fmt_ctx, const AVRational *time_base, AVStream *st, AVPacket *pkt);

static void add_stream(OutputStream *ost, AVFormatContext *oc,
                       AVCodec **codec,
                       enum AVCodecID codec_id);

static AVFrame *alloc_audio_frame(enum AVSampleFormat sample_fmt,
                                  uint64_t channel_layout,
                                  int sample_rate, int nb_samples);

static void open_audio(AVFormatContext *oc, AVCodec *codec, OutputStream *ost, AVDictionary *opt_arg);

static AVFrame *get_audio_frame(OutputStream *ost);

static int write_audio_frame(AVFormatContext *oc, OutputStream *ost);

static AVFrame *alloc_picture(enum AVPixelFormat pix_fmt, int width, int height);

static void open_video(AVFormatContext *oc, AVCodec *codec, OutputStream *ost, AVDictionary *opt_arg);

static void fill_yuv_image(AVFrame *pict, int frame_index,
                           int width, int height);

static AVFrame *get_video_frame(OutputStream *ost);

static int write_video_frame(AVFormatContext *oc, OutputStream *ost);

static void close_stream(AVFormatContext *oc, OutputStream *ost);

int muxing(char* inputAudioPath,char * inputVideoPath,char* outputPath);

#endif //FFMPEGPRATICE_MASTER_MUXING_H
