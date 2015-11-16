#include <stdio.h>

int main()
{
    long num = 0x87654321;
    printf("0x%08lX\n", num & 0x0ff);
    printf("0x%08lX\n", num ^ ~0x0ff);
    printf("0x%08lX\n", num | 0x0ff);
    return 0;
}
