#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y; /* Step 1 a, a^b */
    *x = *x ^ *y; /* Step 2 b, a^b */
    *y = *x ^ *y; /* Step 3 b, a */
}

void reverse_array(int a[], int cnt)
{
    int first, last;
    for(first = 0, last = cnt - 1; first < last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }
}

int main()
{
    int i;
    int A[4] = {1, 2, 3, 4};
    int B[5] = {1, 2, 3, 4, 5};
    reverse_array(A, 4);
    for(i = 0; i < 4; ++i) {
        printf("%d ", A[i]);
    }
    puts("");
    reverse_array(B, 5);
    for(i = 0; i < 5; ++i) {
        printf("%d ", B[i]);
    }
    puts("");
    return 0;
}
