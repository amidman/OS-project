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

typedef struct{
    uint16_t width;
    uint16_t height;
    uint8_t bpp;
    enum Type{
        TYPE_16,
        TYPE_256,
        TYPE_1555,
        TYPE_565,
        TYPE_888,
    };
} gr_con;

#include "primitives.h"
