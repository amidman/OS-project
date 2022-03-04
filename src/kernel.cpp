extern "C"{
#include "graphics/graphics.h"
#include "graphics/primitives.h"
#include "kernel/reg.h"
#include "kernel/print.h"

// tell compiler our int32 function is external
extern void int32(unsigned char intnum, regs16_t *regs);

/*
void memset(char* str, Color c, int count){
	for(int i=0;i<count;i++){
		str[i*3+0] = c.b;
		str[i*3+1] = c.g;
		str[i*3+2] = c.r;
	}
}
*/

void memset(char* str, char c, int count){
	for(int i=0;i<count;i++){
		str[i*2+0] = c;
		str[i*2+1] = 0x07;
	}
}

int getPtr(int x){
	int* p = &x;    // pointer points to a location.
	int a = *p;     // dereference, a == 5
	int b = (int)p;
	return b;
}

// int32 test
void int32_test(){
	int y;
	regs16_t regs;

	// 1280*1024*8:8:8
	//regs.bx = 0x011B;
	//regs.ax = 0x4F02;
	//int32(0x10, &regs);

	regs.ax = 0x0013;
	int32(0x10, &regs);

	for(int i=0;i<320;i++){
		for(int j=0;j<200;j++){
			Color c = {254,0,0};
			pixel(i,j,1);
		}
	}

	// wait for key
	regs.ax = 0x0000;
	int32(0x16, &regs);
	
	//switch to 80x25x16 text mode
	//regs.ax = 0x0003;
	//int32(0x10, &regs);
	//
	//memset((char*)0xB8000, ' ', 80*25);
	//printh(regs.bx);

	while(1){}
}
}
