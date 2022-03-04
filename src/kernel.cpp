extern "C"{
extern void int32(unsigned char intnum, regs16_t *regs);

#include "../include/C/stdint.h"
#include "../include/C/stdio.h"
#include "../include/ports/io.h"
#include "../include/interrupts/idt.h"
#include "../include/interrupts/pic.h"
#include "../include/graphics/graphics.h"
#include "../include/graphics/primitives.h"

// int32 test
void kernel(){
	init_video();

	for(int i=0;i<320;i++){
		for(int j=0;j<200;j++){
			Color c;
			c.col = 1;
			pixel(i,j, graphic_config, c);
		}
	}

	// wait for key
	regs.ax = 0x0000;
	int32(0x16, &regs);
	while(1){}
}
}
