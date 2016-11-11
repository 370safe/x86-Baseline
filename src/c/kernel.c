#include "screen.h"

void kmain(void) {
    screen_clear();
    screen_write(0, 0, "Hello World!", SCREEN_MAGENTA | SCREEN_BRIGHT);
    screen_write(1, 0, "https://github.com/JacisNonsense/x86-Baseline", SCREEN_MAGENTA);
    return;
}