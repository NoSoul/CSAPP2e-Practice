#include <stdio.h>
#include <stdlib.h>

int equal(int x, int y)
{
    return !(x ^ y);
}

int main()
{
    int i;
    for(i = 0; i < 100; ++i) {
        int a = rand() & 7;
        int b = rand() & 7;
        if((a == b) != equal(a, b)) {
            printf("error %d %d\n", a, b);
        }
    }
    return 0;
}
