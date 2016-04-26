#include <stdio.h>

int main()
{
    unsigned char list[] = {0x0, 0x2, 0x9, 0xB, 0xF};
    unsigned len = sizeof(list) / sizeof(list[0]);
    for(unsigned i = 0; i < len; ++i) {
        printf("%hhX %hhX %hhu %hhu %hhd %hhd\n", list[i], list[i] & 0x7, list[i], list[i] & 0x7, ((char)(list[i] << 4)) >> 4, ((char)(list[i] << 5)) >> 5);
    }
    return 0;
}
