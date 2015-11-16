#include <stdio.h>

int main()
{
    int x = 0x66;
    int y = 0x39;
    printf("x & y = 0x%02x\tx && y = 0x%02x\n", x & y, x && y);
    printf("x | y = 0x%02x\tx || y = 0x%02x\n", x | y, x || y);
    printf("~x | ~y = 0x%02x\t!x || !y = 0x%02x\n", ~x | ~y, !x || !y);
    printf("x & !y = 0x%02x\tx && ~y = 0x%02x\n", x & !y, x && ~y);
    return 0;
}
