#include "vga.h"

static char *vidptr = (char *)0xb8000;

void vga_clear() {
    unsigned int j = 0;
    while(j < VGA_WIDTH * VGA_HEIGHT * 2) {
        vidptr[j] = ' ';
        vidptr[j+1] = 0x07;
        j = j + 2;
    }
}

void vga_erase(int line_start, int line_end, int col_start, int col_end) {
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int p = 0;

    for (i = line_start; i < line_end; i++) {
        for (j = col_start; j < col_end; j++) {
            p = (i * VGA_WIDTH * 2) + (j * 2);
            vidptr[p] = ' ';
            vidptr[p+1] = 0x07;
        }
    }
}

void vga_write(int line, int column, char *str, char color) {
    unsigned int i = (line * VGA_WIDTH * 2) + column * 2;
    unsigned int j = 0;

    while(str[j] != '\0') {
        vidptr[i] = str[j];
        vidptr[i+1] = color;
        ++j;
        i = i + 2;
    }
}

void vga_fill(int line_start, int line_end, int col_start, int col_end, char content, char color) {
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int p = 0;

    for (i = line_start; i < line_end; i++) {
        for (j = col_start; j < col_end; j++) {
            p = (i * VGA_WIDTH * 2) + (j * 2);
            vidptr[p] = content;
            vidptr[p+1] = color;
        }
    }
}

void vga_fill_color(int line_start, int line_end, int col_start, int col_end, char color) {
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int p = 0;

    for (i = line_start; i < line_end; i++) {
        for (j = col_start; j < col_end; j++) {
            p = (i * VGA_WIDTH * 2) + (j * 2);
            vidptr[p+1] = color;
        }
    }
}

void vga_set(int line, int column, char content, char color) {
    unsigned int p = (line * VGA_WIDTH * 2) + (column * 2);
    vidptr[p] = content;
    vidptr[p+1] = color;
}

void vga_get(int line, int column, char *content, char *color) {
    unsigned int p = (line * VGA_WIDTH * 2) + (column * 2);
    *content = vidptr[p];
    *color = vidptr[p+1];
}

char *vga_video_memory() {
    return vidptr;
}