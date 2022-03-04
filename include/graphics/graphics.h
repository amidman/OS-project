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
    uint8_t bpp;    //byte per pixel in framebuffer
    Type type;      //color type
}; //graphic config

gr_con graphic_config = {
    320,
    200,
    1,
    TYPE_256,
};

#include "primitives.h"


void init_video(){
    regs16_t regs;

	// 1280*1024*8:8:8
	//regs.bx = 0x011B;
	//regs.ax = 0x4F02;
	//int32(0x10, &regs);
	
	regs.ax = 0x0013;
	int32(0x10, &regs);
}