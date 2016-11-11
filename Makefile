OBJECTS = kernel.o screen.o
ASM = kernel.ao
CFLAGS = -m32 -fno-stack-protector

all: kernel_asm kernel_c kernel_ld

$(ASM): %.ao : src/asm/%.asm
	-mkdir -p build/asm
	nasm -f elf32 $< -o build/asm/$@

kernel_asm: $(ASM)

$(OBJECTS): %.o : src/c/%.c
	-mkdir -p build/c
	gcc $(CFLAGS) -Isrc/c -c $< -o build/c/$@ 

kernel_c: $(OBJECTS)

kernel_ld:
	ld -m elf_i386 -T src/ld/link.ld -o kernel $(OBJECTS:%.o=build/c/%.o) $(ASM:%.ao=build/asm/%.ao)

run: all
	qemu-system-x86_64 -curses -kernel kernel

clean:
	rm -r build/