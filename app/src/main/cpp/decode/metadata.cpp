#include "metadata.h"
#include <common/CommonTools.h>
#define LOG_TAG "metadata"
int metadata (char* inputFilePath)
{
    AVFormatContext *fmt_ctx = NULL;
    AVDictionaryEntry *tag = NULL;
    int ret;

    if ((ret = avformat_open_input(&fmt_ctx, inputFilePath, NULL, NULL)))
        return ret;
    while ((tag = av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX)))
        LOGI("xiongliang %s=%s\n", tag->key, tag->value);
    avformat_close_input(&fmt_ctx);
    return 0;
}

