#include <stdio.h>

unsigned char B2U(unsigned char num, int w)
{
    int i;
    unsigned char ans = 0;
    for(i = 0; i < w; ++i) {
        ans += ((1 << i & num) >> i) * (1 << i);
    }
    return ans;
}

int main()
{
    int w = 4;
    unsigned i;
    char list[] = { -8, -3, -2, -1, 0, 5};
    for(i = 0; i < sizeof(list) / sizeof(list[0]); ++i) {
        printf("%u\n", B2U(list[i], w));
    }
    return 0;
}
