#include <stdio.h>

void ShowBin(unsigned char num, int w)
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
    for(j = i; j < w; ++j) {
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

unsigned char B2U(unsigned char num, int w)
{
    int i;
    unsigned char ans = 0;
    for(i = 0; i < w; ++i) {
        ans += ((1 << i & num) >> i) * (1 << i);
    }
    return ans;
}

char B2T(unsigned char num, int w)
{
    int i;
    char ans = -((1 << (w - 1)&num) >> (w - 1)) * (1 << (w - 1));
    for(i = 0; i < w - 1; ++i) {
        ans += ((1 << i & num) >> i) * (1 << i);
    }
    return ans;
}

int main()
{
    int w = 4;
    unsigned i;
    unsigned char list[] = {0xE, 0x0, 0x5, 0x8, 0xD, 0xF};
    for(i = 0; i < sizeof(list) / sizeof(list[0]); ++i) {
        printf("Hex: 0x%1X, Bin: ", list[i]);
        ShowBin(list[i], w);
        printf("\tB2U: %hhu\tB2T: %hhd\n", B2U(list[i], w), B2T(list[i], w));
    }
    return 0;
}
