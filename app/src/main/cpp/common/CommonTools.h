#ifndef SONG_STUDIO_COMMON
#define SONG_STUDIO_COMMON
#include <jni.h>
#include <android/log.h> 
#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>


#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#define UINT64_C        uint64_t
#define INT16_MAX        32767
#define INT16_MIN       -32768
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
typedef signed short SInt16;
typedef unsigned char byte;
#define ARRAY_LEN(a) (sizeof(a) / sizeof(a[0]))
#define AUDIO_PCM_OUTPUT_CHANNEL 2
#define ACCOMPANY_PCM_OUTPUT_CHANNEL 2

static inline char* intToStr(int paramIntValue) {
	char* result = new char[10];
	sprintf(result, "%d", paramIntValue);
	return result;
}

static inline int getIndexOfMaxValueInArray(long* array, int length) {
	if (length <= 0) {
		return -1;
	}
	int result = 0;
	long max = array[0];
	for (int i = 0; i < length - 1; i++) {
		if (array[i] < array[i + 1]) {
			max = array[i + 1];
			result = i + 1;
		}
	}
	return result;
}

static inline bool isAACSuffix(const char* accompanyPath){
	bool ret = false;
	const char *suffix = strrchr(accompanyPath, '.');
	if (0 == strcmp(suffix, ".aac")) {
		ret = true;
	}
	return ret;
}

static inline bool isPNGSuffix(const char* picFilePath){
	bool ret = false;
	const char *suffix = strrchr(picFilePath, '.');
	if (0 == strcmp(suffix, ".png")) {
		ret = true;
	}
	return ret;
}

static inline long getCurrentTime()
{
   struct timeval tv;
   gettimeofday(&tv,NULL);
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

static inline long long currentTimeMills(){
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

static inline long getCurrentTimeSecSinceReferenceDate()
{
   struct timeval tv;
   gettimeofday(&tv,NULL);
   return tv.tv_sec;
}
inline int readShortFromFile(short *shortarray, int size, FILE* fp) {
	int actualSize = fread(shortarray, 2, size, fp);
	if (actualSize != size) {
		int flag = feof(fp);
		if (flag != 0 && actualSize == 0) {
			//到达文件末尾
			return -1;
		}
	}
	return actualSize;
}

inline int readByteFromFile(byte *bytearray, int size, FILE* fp) {
	int actualSize = fread(bytearray, 1, size, fp);
	if (actualSize != size) {
		int flag = feof(fp);
		if (flag != 0 && actualSize == 0) {
			//到达文件末尾
			return -1;
		}
	}
	return actualSize;
}

//合并两个short，返回一个short
inline SInt16 TPMixSamples(SInt16 a, SInt16 b) {
	int tmp = a < 0 && b < 0 ? ((int) a + (int) b) - (((int) a * (int) b) / INT16_MIN) : (a > 0 && b > 0 ? ((int) a + (int) b) - (((int) a * (int) b) / INT16_MAX) : a + b);
	return tmp > INT16_MAX ? INT16_MAX : (tmp < INT16_MIN ? INT16_MIN : tmp);
}

//合并两个float，返回一个short
inline SInt16 TPMixSamplesFloat(float a, float b) {
	int tmp = a < 0 && b < 0 ? ((int) a + (int) b) - (((int) a * (int) b) / INT16_MIN) : (a > 0 && b > 0 ? ((int) a + (int) b) - (((int) a * (int) b) / INT16_MAX) : a + b);
	return tmp > INT16_MAX ? INT16_MAX : (tmp < INT16_MIN ? INT16_MIN : tmp);
}

//把一个short转换为一个长度为2的byte数组
inline void converttobytearray(SInt16 source, byte* bytes2) {
	bytes2[0] = (byte) (source & 0xff);
	bytes2[1] = (byte) ((source >> 8) & 0xff);
}

//将两个byte转换为一个short
inline SInt16 convertshort(byte* bytes) {
	return (bytes[0] << 8) + (bytes[1] & 0xFF);
}

//调节音量的方法
inline SInt16 adjustAudioVolume(SInt16 source, float volume) {
	SInt16 result = source;
	int temp = (int) ((int) source * volume);
	if (temp < -0x8000) {
		result = -0x8000;
	} else if (temp > 0x7FFF) {
		result = 0x7FFF;
	} else {
		result = (short) temp;
	}
	return result;
}




inline int strindex(char *s1, char *s2) {
	int nPos = -1;
	char *res = strstr(s1, s2);
	if (res)
		nPos = res - s1;
	return nPos;
}

#endif //SONG_STUDIO_COMMON
