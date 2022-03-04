#pragma once
#include <stdint.h>
typedef struct __attribute__ ((packed)) {
	unsigned short di, si, bp, sp, bx, dx, cx, ax;
	unsigned short gs, fs, es, ds, eflagsm, cl;
} regs16_t;
