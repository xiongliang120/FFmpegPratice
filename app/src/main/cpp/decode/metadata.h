//
// Created by 123 on 2019/5/21.
//

#ifndef FFMPEGPRATICE_METADATA_H
#define FFMPEGPRATICE_METADATA_H
#include <stdio.h>
extern "C" {
#include <libavformat/avformat.h>
#include <libavutil/dict.h>
};


int metadata (char* inputFilePath);
#endif //FFMPEGPRATICE_METADATA_H
