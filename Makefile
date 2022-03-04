CC=g++
LD=ld
ASM=nasm
CFLAGS=-Iinclude -m32 -fno-stack-protector -fstack-check=no
LDFLAGS=-m elf_i386 -T link.ld

kernel: kernel_asm.o kernel.o
	$(LD) -m elf_i386 -T link.ld -o kernel kasm.o kc.o
kernel_asm.o: src/kernel_asm.asm
	$(ASM) -f elf32 src/kernel_asm.asm -o kernel_asm.o
kernel.o: src/kernel.cpp
	$(CC) $(CFLAGS) -c src/kernel.cpp 

all: kernel
run: kernel
	qemu-system-i386 -kernel kernel
clean:
	rm *.o
	rm kernel

