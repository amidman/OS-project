#include "kernel/print.h"
#include <stdint.h>

static int x_coursor = 0;
static int y_coursor = 0;

void printid(int a){
	uint8_t* vid = (uint8_t*)0xB8000;
	do{
		if(x_coursor==80){
			x_coursor = 0;
			y_coursor++;
		}
		vid[(y_coursor*80+x_coursor)*2+0] = a%10+48;
		vid[(y_coursor*80+x_coursor)*2+1] = 0x07;
		a = (a-a%10)/10;
		x_coursor++;
	}while(a!=0);
}

void printih(int a){
	uint8_t* vid = (uint8_t*)0xB8000;
	do{
		if(x_coursor==80){
			x_coursor = 0;
			y_coursor++;
		}

		uint8_t t = a%16;

		if(t>9){
			t=t+65-10;
		}else{
			t=t+48;
		}

		vid[(y_coursor*80+x_coursor)*2+0] = t;
		vid[(y_coursor*80+x_coursor)*2+1] = 0x07;
		a = (a-a%16)/16;
		x_coursor++;
	}while(a!=0);
}
