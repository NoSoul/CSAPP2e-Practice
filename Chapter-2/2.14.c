#include <stdio.h>

int main()
{
    int x = 0x66;
    int y = 0x39;
    printf("x & y = %d\tx && y = %d\n", x & y, x && y);
    printf("x | y = %d\tx || y = %d\n", x | y, x || y);
    printf("~x | ~y = %d\t!x || !y = %d\n", ~x | ~y, !x || !y);
    printf("x & !y = %d\tx && ~y = %d\n", x & !y, x && ~y);
    return 0;
}
