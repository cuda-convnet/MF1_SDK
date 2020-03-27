#ifndef __AUDIO_H
#define __AUDIO_H

#include <stdint.h>

typedef enum
{
    AUDIO_TYPE_ES8374 = 0,
    AUDIO_TYPE_PT8211,
    AUDIO_TYPE_MAX,
} audio_type;

typedef struct _autio audio_t;

typedef struct _autio
{
    uint8_t (*config)(void);

    /* 文件要求，WAV文件去掉头部44Byte */
    /* 可使用 https://audio.online-convert.com/convert-to-wav 讲MP3转为WAV*/
    /* 选项设置为 16Bit, 16000Hz, Mono */
    uint8_t (*play)(audio_t *audio, uint8_t *audio_buf, uint32_t audio_len);

} audio_t;

uint8_t audio_init(audio_type type);

uint8_t audio_play(uint8_t *audio_buf, uint32_t audio_len);

#endif /* __AUDIO_H */
