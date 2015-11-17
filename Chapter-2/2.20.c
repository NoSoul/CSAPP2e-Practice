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

unsigned char T2U(char num, int w)
{
    if(num < 0) {
        return (1u << w) + num;
    }
    return num;
}

int main()
{
    int w = 4;
    unsigned i;
    char list[] = { -8, -3, -2, -1, 0, 5};
    for(i = 0; i < sizeof(list) / sizeof(list[0]); ++i) {
        if(B2U(list[i], w) != T2U(list[i], w)) {
            printf("error %d\n", list[i]);
        }
    }
    return 0;
}

