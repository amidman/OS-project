#pragma once
#include "stdint.h"


typedef struct {
    union{
        unsigned char r;
        unsigned char col;
    };
	unsigned char g;
	unsigned char b;
}Color;

Color convert(uint8_t);

typedef enum {
    TYPE_16,
    TYPE_256,
    TYPE_1555,
    TYPE_565,
    TYPE_888,
}Type;

typedef struct {
    uint16_t width;
    uint16_t height;
    uint8_t bpp;
    Type type;
}gr_con;
