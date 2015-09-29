#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y; /* Step 1 a, a^b */
    *x = *x ^ *y; /* Step 2 b, a^b */
    *y = *x ^ *y; /* Step 3 b, a */
}

int main()
{
    int a, b;
    a = 0;
    b = 1;
    inplace_swap(&a, &b);
    return 0;
}
