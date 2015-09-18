#include <stdio.h>
#include <string.h>

void reverse(char *str)
{
    size_t i, j;
    for(i = 0, j = strlen(str) - 1; i < j; ++i, --j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void GetBin(char *str, unsigned char *base)
{
    int i, j = 0;
    for(i = 0; i < 4; ++i, ++base) {
        unsigned char num = *base;
        while(num) {
            str[j++] = (num & 1) + '0';
            num >>= 1;
        }
        while(j < (i + 1) * 8) {
            str[j++] = '0';
        }
    }
    str[j] = '\0';
    reverse(str);
}

void GetMax(char *strA, char *strB)
{
    int i, j, max = -1, maxid, offset;
    for(i = 0; i < 32; ++i) {
        int cur = 0;
        for(j = i; j < 32; ++j) {
            if(strA[j] == strB[j - i]) {
                ++cur;
            } else {
                if(cur > max) {
                    max = cur;
                    maxid = j;
                    offset = i;
                }
                cur = 0;
            }
        }
        if(cur > max) {
            max = cur;
            maxid = 32;
            offset = i;
        }
    }
    printf("B offset %d, A %d~%d\t", offset, maxid - max, maxid - 1);
    for(i = maxid - max; i < maxid; ++i) {
        putchar(strA[i]);
    }
    printf("\tmatch %d\n", max);
}

int main()
{
    int A = 3510593;
    float B = 3510593.0;
    char StrA[33], StrB[33];
    unsigned char *p;
    p = (unsigned char*)&A;
    GetBin(StrA, p);
    p = (unsigned char*)&B;
    GetBin(StrB, p);
    puts(StrA);
    puts(StrB);
    GetMax(StrA, StrB);
    return 0;
}
