#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned dec;
    char str[9];
    unsigned hex;
} Node_t;

void ShowBin(unsigned num)
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

unsigned ShowHex(char *str)
{
    size_t i, len = strlen(str);
    unsigned num = 0;
    for(i = 0; i < len; ++i) {
        num <<= 1;
        num |= str[i] - '0';
    }
    return num;
}

int main()
{
    Node_t A[9] = {
        {167, "", -1},
        {62, "", -1},
        {188, "", -1},
        { -1, "00110111", -1},
        { -1, "10001000", -1},
        { -1, "11110011", -1},
        { -1, "", 0x52},
        { -1, "", 0xAC},
        { -1, "", 0xE7},
    };
    int i;
    for(i = 0; i < 9; ++i) {
        if(~A[i].dec || ~A[i].hex) {
            unsigned num ;
            if(~A[i].dec) {
                num = A[i].dec;
            } else {
                num = A[i].hex;
            }
            printf("%d\t", num);
            ShowBin(num);
            printf("\t0x%X\n", num);

        } else {
            printf("%d\t%s\t0x%X\n", ShowHex(A[i].str), A[i].str, ShowHex(A[i].str));
        }
    }
    return 0;
}
