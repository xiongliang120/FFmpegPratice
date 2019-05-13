cmake_minimum_required(VERSION 3.4.1)

set(PATH_TO_MEDIACORE ${CMAKE_SOURCE_DIR}/../cpp)
set(PATH_TO_JNI_LAYER ${CMAKE_SOURCE_DIR}/jni)
set(PATH_TO_PRE_BUILT ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})



# 包含进头文件就可以找的到了
include_directories(${PATH_TO_MEDIACORE}/)
include_directories(${PATH_TO_MEDIACORE}/decode/)
include_directories(${PATH_TO_MEDIACORE}/common/)
include_directories(${PATH_TO_JNI_LAYER}/)
include_directories(${CMAKE_SOURCE_DIR}/../jniLibs/include/)


file(GLOB FILES_JNI_LAYER "${PATH_TO_JNI_LAYER}/*.cpp")
file(GLOB FILES_LIB_DECODE "${PATH_TO_MEDIACORE}/decode/*.cpp")



add_library(ffmpegpratice  SHARED
            ${FILES_JNI_LAYER}
            ${FILES_LIB_DECODE}
            )


add_library(avfilter
           SHARED
           IMPORTED)
set_target_properties(avfilter
                    PROPERTIES IMPORTED_LOCATION
                    ${PATH_TO_PRE_BUILT}/libavfilter.so)

add_library(avformat
           SHARED
           IMPORTED)
set_target_properties(avformat
                    PROPERTIES IMPORTED_LOCATION
                    ${PATH_TO_PRE_BUILT}/libavformat.so)

add_library(avcodec
           SHARED
           IMPORTED)
set_target_properties(avcodec
                    PROPERTIES IMPORTED_LOCATION
                    ${PATH_TO_PRE_BUILT}/libavcodec.so)

add_library(swresample
           SHARED
           IMPORTED)
set_target_properties(swresample
                    PROPERTIES IMPORTED_LOCATION
                    ${PATH_TO_PRE_BUILT}/libswresample.so)


add_library(swscale
           SHARED
           IMPORTED)
set_target_properties(swscale
                    PROPERTIES IMPORTED_LOCATION
                    ${PATH_TO_PRE_BUILT}/libswscale.so)

add_library(avutil
           SHARED
           IMPORTED)
set_target_properties(avutil
                    PROPERTIES IMPORTED_LOCATION
                    ${PATH_TO_PRE_BUILT}/libavutil.so)

add_library(avdevice
           SHARED
           IMPORTED)
set_target_properties(avdevice
                    PROPERTIES IMPORTED_LOCATION
                    ${PATH_TO_PRE_BUILT}/libavdevice.so)


target_link_libraries( ffmpegpratice
                       log
                       android
                       z
                       # 引入ffmpeg相关静态库/动态库
                       avfilter
                       avformat
                       avutil
                       avcodec
                       swresample
                       swscale
                       avdevice
                       )