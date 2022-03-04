#pragma once
#include "../C/stdint.h"


typedef struct{
    union{
        unsigned char r;
        unsigned char col;
    };
	unsigned char g;
	unsigned char b;
} Color;

typedef enum Type{
    TYPE_16,
    TYPE_256,
    TYPE_1555,
    TYPE_565,
    TYPE_888,
};

struct gr_con{
    uint16_t width;
    uint16_t height;
    uint8_t bpp;
    Type type;
};

gr_con graphic_config = {
    320,
    200,
    1,
    TYPE_256,
};

#include "primitives.h"
