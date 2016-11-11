#ifndef H_SCREEN
#define H_SCREEN

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

#define SCREEN_BRIGHT   0b1000      // Can combine this with any of the other color options
#define SCREEN_BG       4           // Shift a color value by this to use it as a background
                                    // e.g. (SCREEN_BLUE << SCREEN_BG) | (SCREEN_MAGENTA) is Blue on Magenta
                                    // Note: SCREEN_WHITE becomes Black for background colors.
#define SCREEN_WHITE    0b000
#define SCREEN_BLUE     0b001
#define SCREEN_GREEN    0b010
#define SCREEN_RED      0b100
#define SCREEN_MAGENTA  0b101
#define SCREEN_YELLOW   0b110
#define SCREEN_GRAY     0b111


#define SCREEN_DEFAULT  SCREEN_GRAY // Default Color (gray on black)

void screen_clear();
void screen_erase(int line_start, int line_end, int col_start, int col_end);
void screen_write(int line, int column, char *str, char color);
void screen_fill(int line_start, int line_end, int col_start, int col_end, char content, char color);
void screen_fill_color(int line_start, int line_end, int col_start, int col_end, char color);
void screen_set(int line, int column, char content, char color);
void screen_get(int line, int column, char *content, char *color);
char *screen_video_memory();

#endif