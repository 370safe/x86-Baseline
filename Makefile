OBJECTS = kernel.o vga.o str.o
ASM = kernel.ao
CFLAGS = -m32 -ffreestanding

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
	-mkdir -p build/bin
	ld -m elf_i386 -T src/ld/link.ld -o build/bin/kernel.bin $(OBJECTS:%.o=build/c/%.o) $(ASM:%.ao=build/asm/%.ao)

kernel_grub:
	-mkdir -p build/iso/grub/boot/grub
	cp src/grub.cfg build/iso/grub/boot/grub/grub.cfg
	cp build/bin/kernel.bin build/iso/grub/boot/x86_baseline.bin
	grub-mkrescue -o build/iso/x86_baseline_grub.iso build/iso/grub

iso: kernel_grub

run: all
	qemu-system-x86_64 -curses -kernel build/bin/kernel.bin

clean:
	rm -r build/