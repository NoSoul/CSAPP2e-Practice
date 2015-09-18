#include <stdio.h>
#include <string.h>

void ShowBin(unsigned);
void ShowHex(char*);

void reverse(char *str)
{
    size_t i, j;
    for(i = 0, j = strlen(str) - 1; i < j; ++i, --j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void ShowBin(unsigned num)
{
    printf("0x%X\t", num);
    if(num == 0) {
        putchar('0');
        return;
    }
    char str[32];
    int i = 0;
    while(num) {
        str[i++] = (num & 1) + '0';
        num >>= 1;
    }
    str[i] = '\0';
    reverse(str);
    ShowHex(str);
    puts(str);
}

void ShowHex(char *str)
{
    puts(__func__);
    printf("%s\t0x", str);
    size_t i, len = strlen(str);
    int num = 0;
    for(i = 0; i < (len & 3); ++i) {
        num <<= 1;
        num |= str[i] - '0';
    }
    if(len & 3) {
        putchar(num > 9 ? 'A' + num - 10 : '0' + num);
    }
    for(i = len & 3; i + 4 <= len; i += 4) {
        num = ((str[i] - '0') << 3) | ((str[i + 1] - '0') << 2) | ((str[i + 2] - '0') << 1) | (str[i + 3] - '0');
        putchar(num > 9 ? 'A' + num - 10 : '0' + num);
    }
    putchar('\n');
}

int main()
{
    char num1[] = "1100100101111011";
    char num2[] = "1001101110011110110101";
    ShowBin(0x39A7F8);
    putchar('\n');
    ShowHex(num1);
    putchar('\n');
    ShowBin(0xD5E4C);
    putchar('\n');
    ShowHex(num2);
    return 0;
}
