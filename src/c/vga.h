#ifndef H_VGA
#define H_VGA

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

#define VGA_BRIGHT   0b1000      // Can combine this with any of the other color options
#define VGA_BG       4           // Shift a color value by this to use it as a background
                                    // e.g. (VGA_BLUE << VGA_BG) | (VGA_MAGENTA) is Blue on Magenta
                                    // Note: VGA_WHITE becomes Black for background colors.
#define VGA_WHITE    0b000
#define VGA_BLUE     0b001
#define VGA_GREEN    0b010
#define VGA_RED      0b100
#define VGA_MAGENTA  0b101
#define VGA_YELLOW   0b110
#define VGA_GRAY     0b111


#define VGA_DEFAULT  VGA_GRAY // Default Color (gray on black)

void vga_clear();
void vga_erase(int line_start, int line_end, int col_start, int col_end);
void vga_write(int line, int column, char *str, char color);
void vga_fill(int line_start, int line_end, int col_start, int col_end, char content, char color);
void vga_fill_color(int line_start, int line_end, int col_start, int col_end, char color);
void vga_set(int line, int column, char content, char color);
void vga_get(int line, int column, char *content, char *color);
char *vga_video_memory();

#endif