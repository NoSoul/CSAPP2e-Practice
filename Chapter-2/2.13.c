#include <stdio.h>
#include <stdlib.h>
/* Declarations of functions implementing operations bis and bic */
int bis(int x, int m)
{
    int num = 0;
    while(m) {
        if(m & 1) {
            x |= 1 << num;
        }
        m >>= 1;
        ++num;
    }
    return x;
}
int bic(int x, int m)
{
    int num = 0;
    while(m) {
        if(m & 1) {
            x &= ~(1 << num);
        }
        m >>= 1;
        ++num;
    }
    return x;
}
/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, int y)
{
    int result = bis(x, y);
    return result;
}
/* Compute x^y using only calls to functions bis and bic */
int bool_xor(int x, int y)
{
    int result = bis(bic(x, y), bic(y, x));
    return result;
}
/* Compute x&y using only calls to functions bis and bic */
int bool_and(int x, int y)
{
    int result = bic(bis(x, y), bis(bic(x, y), bic(y, x)));
    return result;
}

int main()
{
    int i;
    for(i = 0; i < 100; ++i) {
        int x, y;
        x = rand();
        y = rand();
        if((x | y) != bool_or(x, y)) {
            printf("bool_or error %d %d\n", x, y);
        }
        if((x ^ y) != bool_xor(x, y)) {
            printf("bool_xor error %d %d\n", x, y);
        }
        if((x & y) != bool_and(x, y)) {
            printf("bool_and error %d %d\n", x, y);
        }
    }
    return 0;
}
