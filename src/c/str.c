#include <str.h>

char *itoa(int i, char *buf) {
    if (i == 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return buf;
    }
    int digs = (i / 10) + 1;
    int neg = i < 0 ? 1 : 0;
    int j = neg;
    if (neg == 1) {
        buf[0] = '-';
        i = -i;
    }
    
    j += digs;
    int k;
    for (k = 0; k < digs; k++) {
        buf[j - k - 1] = '0' + (i % 10);
        i /= 10;
    }
    buf[j] = '\0';
    return buf;
}

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}