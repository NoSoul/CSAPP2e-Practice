#include <stdio.h>

void ShowBin(unsigned char num)
{
    if(num == 0) {
        putchar('0');
        return;
    }
    char str[32];
    int i = 0, j;
    while(num) {
        str[i++] = (num & 1) + '0';
        num >>= 1;
    }
    str[i] = '\0';
    for(j = i; j < 8; ++j) {
        putchar('0');
    }
    while(i) {
        --i;
        putchar(str[i]);
        if(!i) {
            return;
        }
    }
}

void Show(unsigned char num)
{
    printf("Hex: 0x%2X, Bin: ", num);
    ShowBin(num);
    putchar('\n');
}

int main()
{
    unsigned i;
    unsigned char list[] = {0xC3, 0x75, 0x87, 0x66};
    unsigned char newU;
    char newS;
    for(i = 0; i < sizeof(list) / sizeof(list[0]); ++i) {
        printf("origin x\t\t");
        Show(list[i]);
        printf("x << 3\t\t\t");
        newU = list[i] << 3;
        Show(newU);
        printf("Logical x >> 2\t\t");
        newU = list[i] >> 2;
        Show(newU);
        printf("Arithmetic x >> 2\t");
        newS = (char)list[i] >> 2;
        Show(newS);
        puts("");
    }
    return 0;
}
