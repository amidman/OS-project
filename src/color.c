#include "graphics.h"

static const Color base[16]={
	{0,0,0},
	{0,0,170},
	{0,170,0},
	{0,170,170},
	{170,0,0},
	{170,0,170},
	{170,85,0},
	{170,170,170},
	{85,85,85},
	{85,85,255},
	{85,255,85},
	{85,255,255},
	{255,85,85},
	{255,85,255},
	{255,255,85},
	{255,255,255}
};
static const uint8_t gray[16]={
	0,16,32,53,
	69,85,101,117,
	138,154,170,186,
	202,223,239,255
};
static const Color base2[24]={
	{0,0,255},
	{65,0,255},
	{130,0,255},
	{190,0,255},
	{255,0,255},
	{255,0,190},
	{255,0,130},
	{255,0,65},
	{255,0,0},
	{255,65,0},
	{255,130,0},
	{255,190,0},
	{255,255,0},
	{190,255,0},
	{130,255,0},
	{65,255,0},
	{0,255,0},
	{0,255,65},
	{0,255,130},
	{0,255,190},
	{0,255,255},
	{0,190,255},
	{0,130,255},
	{0,65,255}
};

static const uint8_t coef[9][5]={
	{0,65,130,190,255},
	{130,158,190,223,255},
	{186,202,223,239,255},
	{0,28,57,85,113},
	{57,69,85,97,113},
	{81,89,97,105,113},
	{0,16,32,49,65},
	{32,40,49,57,65},
	{45,49,53,61,65}
};

Color convert(uint8_t c){
	Color color;
	if(c<16){
		color = base[16];
	}else if(c>=16 && c<32){
		uint8_t value = gray[(c-16)*16];
		color.r=color.g=color.b=value;
	}else if(c>=32 && c<248){
		uint8_t color1 = (c-32)%24;
		uint8_t group1 = (c-32)/24;
		uint8_t color2 = color1%4;
		uint8_t group2 = color1/4;

		uint8_t min = coef[group1][0];
		uint8_t max = coef[group2][4];
		uint8_t value1 = coef[group1][color2];
		uint8_t value2 = coef[group1][4-color2];

		switch(group2){
			case 0: color.r=value1;color.g=min;color.b=max; break;
			case 1: color.r=max;color.g=min;color.b=value2; break;
			case 2: color.r=max;color.g=value1;color.b=min; break;
			case 3: color.r=value2;color.g=max;color.b=min; break;
			case 4: color.r=min;color.g=max;color.b=value1; break;
			case 5: color.r=min;color.g=value2;color.b=max; break;
		}
	}else
		color.r=color.g=color.b=0;
	return color;
}

