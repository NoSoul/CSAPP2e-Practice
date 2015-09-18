#include <stdio.h>
#include <math.h>

int main()
{
    int A[6][3] = {
        {19, -1, -1},
        { -1, 16384, -1},
        { -1, -1, 0x10000},
        {17, -1, -1},
        { -1, 32, -1},
        { -1, -1, 0x80},
    };
    int i, j;
    for(i = 0; i < 6; ++i) {
        for(j = 0; j < 3; ++j) {
            if(~A[i][j]) {
                break;
            }
        }
        if(j == 0) {
            printf("%d\t%d\t0x%x\n", A[i][j], 1 << A[i][j], 1 << A[i][j]);
        } else {
            printf("%d\t%d\t0x%x\n", (int)log2(A[i][j]), A[i][j], A[i][j]);
        }
    }
    return 0;
}
