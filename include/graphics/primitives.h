#pragma once

//#include "../C/stdint.h"


void pixel(int x, int y, gr_con con, Color c){
	uint8_t *framebuffer = (uint8_t*)0xA0000;

    framebuffer += (y * gr_con.width + x) * gr_con.bpp;

	if(){
        
    }
}

void draw_rect(int x, int y, int w, int h, Color c){
	for(int i=y; i<y+h;i++){
		//memset((char*)0xA0000 + (int)3*(i*1280+x), c, w);
	}
}
