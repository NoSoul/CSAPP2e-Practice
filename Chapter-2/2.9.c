#include <stdio.h>

int main()
{
    unsigned int i;
    char Color[8][8] = {"Black", "Blue", "Green", "Cyan", "Red", "Magenta", "Yellow", "White"};
    for(i = 0; i < 8; ++i) {
        printf("The complement of %s is %s\n", Color[i], Color[~i & 0x07]);
    }
    puts("");
    printf("%s | %s = %s\n", Color[1], Color[2], Color[1 | 2]);
    printf("%s & %s = %s\n", Color[6], Color[3], Color[6 & 3]);
    printf("%s ^ %s = %s\n", Color[4], Color[5], Color[4 ^ 5]);
    return 0;
}
