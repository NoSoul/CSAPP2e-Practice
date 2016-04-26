#include <stdio.h>
#include <string.h>

int B2T(const char *bin)
{
    size_t w = strlen(bin);
    int ans;
    ans = -((bin[0] - '0') * (1 << (w - 1)));
    for(size_t i = 1; i < w; ++i) {
        ans += (bin[i] - '0') * (1 << (w - i - 1));
    }
    return ans;
}

int main()
{
    char testStr[3][7] = {"1011", "11011", "111011"};
    for(int i = 0; i < 3; ++i) {
        printf("%d\n", B2T(testStr[i]));
    }
    return 0;
}
