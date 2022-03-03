#pragma once

struct color{
    union{
        unsigned char r;
        unsigned char col;
    };
	unsigned char g;
	unsigned char b;
};
typedef struct color color;

struct gr_con{
    uint16_t width;
    uint16_t height;
    uint8_t bpp;
    enum type{
        TYPE_16,
        TYPE_256,
        TYPE_1555,
        TYPE_565,
        TYPE_888,
    };
};

#include "primitives.h"