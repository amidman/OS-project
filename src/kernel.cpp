extern "C"{
#include "../include/C/stdint.h"
#include "../include/C/stdio.h"
#include "../include/graphics/graphics.h"
#include "../include/graphics/primitives.h"

// tell compiler our int32 function is external
extern void int32(unsigned char intnum, regs16_t *regs);

// int32 test
void kernel(){
	int y;
	regs16_t regs;

	// 1280*1024*8:8:8
	//regs.bx = 0x011B;
	//regs.ax = 0x4F02;
	//int32(0x10, &regs);

	regs.ax = 0x0013;
	int32(0x10, &regs);

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
