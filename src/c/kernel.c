#include "vga.h"

void kmain(void) {
    vga_clear();
    vga_write(0, 0, "Hello World!", VGA_MAGENTA | VGA_BRIGHT);
    vga_write(1, 0, "https://github.com/JacisNonsense/x86-Baseline", VGA_MAGENTA);
    return;
}