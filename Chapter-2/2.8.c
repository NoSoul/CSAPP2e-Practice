#include <stdio.h>
#include <string.h>

void Not(char *str)
{
    size_t i, len = strlen(str);
    for(i = 0; i < len; ++i) {
        putchar(str[i] == '0' ? '1' : '0');
    }
    putchar('\n');
}

void And(char *strA, char *strB)
{
    size_t i, len = strlen(strA);
    for(i = 0; i < len; ++i) {
        putchar(strA[i] == '1' && strB[i] == '1' ? '1' : '0');
    }
    putchar('\n');
}

void Or(char *strA, char *strB)
{
    size_t i, len = strlen(strA);
    for(i = 0; i < len; ++i) {
        putchar(strA[i] == '1' || strB[i] == '1' ? '1' : '0');
    }
    putchar('\n');
}

void XOr(char *strA, char *strB)
{
    size_t i, len = strlen(strA);
    for(i = 0; i < len; ++i) {
        putchar(strA[i] != strB[i] ? '1' : '0');
    }
    putchar('\n');
}

int main()
{
    char StrA[] = "01101001";
    char StrB[] = "01010101";
    puts(StrA);
    puts(StrB);
    putchar('\n');
    Not(StrA);
    Not(StrB);
    And(StrA, StrB);
    Or(StrA, StrB);
    XOr(StrA, StrB);
    return 0;
}
