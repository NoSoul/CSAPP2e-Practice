#include <stdio.h>

int fun1(unsigned word)
{
    return (int) ((word << 24) >> 24);
}

int fun2(unsigned word)
{
    return ((int) word << 24) >> 24;
}

int main()
{
    unsigned int list[] = {0x00000076, 0x87654321, 0x000000C9, 0xEDCBA987};
    unsigned int len = sizeof(list) / sizeof(list[0]);
    for(unsigned int i = 0; i < len; ++i) {
        printf("0x%08X\t%d\t%d\n", list[i], fun1(list[i]), fun2(list[i]));
    }
    return 0;
}
