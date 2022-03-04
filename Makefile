CC=gcc
CXX=g++
LD=ld
ASM=nasm
CFLAGS=-Iinclude/graphics -Iinclude/C -m32 -fno-stack-protector -fstack-check=no
LDFLAGS=-m elf_i386 -T link.ld

all: kernel

kernel_asm.o: src/kernel_asm.asm
	$(ASM) -f elf32 src/kernel_asm.asm -o kernel_asm.o
kernel.o: src/kernel.cpp
	$(CXX) $(CFLAGS) -c src/kernel.cpp 
color.o: src/color.c
	$(CC) $(CFLAGS) -c src/color.c
kernel: kernel_asm.o kernel.o color.o
	$(LD) -m elf_i386 -T link.ld -o kernel *.o

run: kernel
	qemu-system-i386 -kernel kernel
clean:
	rm *.o
	rm kernel
