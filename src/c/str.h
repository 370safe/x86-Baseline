#ifndef H_STR
#define H_STR

#include <stddef.h>

char *itoa(int i, char *buf, int base);
void strrev(char *str, int length);
size_t strlen(const char* str);

#endif