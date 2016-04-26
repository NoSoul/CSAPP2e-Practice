#include <stdio.h>
#include <string.h>

void JudgeSignedOrUnsigned(char *str, char *retIsSigned, unsigned *uVar32, int *var32)
{
    size_t len = strlen(str);
    if(str[0] == '(') {
        *retIsSigned  = str[1] != 'u';
        return;
    }
    *retIsSigned = str[len - 1] != 'U' && str[len - 1] != 'u';
    *var32 = 0;
    *uVar32 = 0;
    if(*retIsSigned) {
        int temp = 0;
        size_t start = 0;
        char opAdd = 1;
        while(start < len) {
            if(str[start] < '0' || str[start] >= '9') {
                if(opAdd) {
                    *var32 += temp;
                } else {
                    *var32 -= temp;
                }
                opAdd = str[start] == '+';
                temp = 0;
            } else {
                temp *= 10;
                temp += str[start] - '0';
            }
            ++start;
        }
        if(opAdd) {
            *var32 += temp;
        } else {
            *var32 -= temp;
        }
    } else {
        unsigned temp = 0;
        size_t start = 0;
        char opAdd = 1;
        while(start < len) {
            if(str[start] < '0' || str[start] >= '9') {
                if(opAdd) {
                    *uVar32 += temp;
                } else {
                    *uVar32 -= temp;
                }
                opAdd = str[start] == '+';
                temp = 0;
            } else {
                temp *= 10;
                temp += str[start] - '0';
            }
            ++start;
        }
        if(opAdd) {
            *uVar32 += temp;
        } else {
            *uVar32 -= temp;
        }
    }
}

int main()
{
    char testStr[5][29] = {"-2147483647-1 == 2147483648U",
                           "-2147483647-1 < 2147483647",
                           "-2147483647-1U < 2147483647",
                           "-2147483647-1 < -2147483647",
                           "-2147483647-1U < -2147483647"
                          };
    for(int i = 0; i < 5; ++i) {
        char *a = strtok(testStr[i], " ");
        char *op = strtok(NULL, " ");
        char *b = strtok(NULL, " ");
        char aIsSigned, bIsSigned;
        unsigned ua32, ub32;
        int a32, b32;
        char evaluation;
        JudgeSignedOrUnsigned(a, &aIsSigned, &ua32, &a32);
        JudgeSignedOrUnsigned(b, &bIsSigned, &ub32, &b32);
        //printf("A: %d %u B: %d %u\n", a32, ua32, b32, ub32);
        if(op[0] == '=') {
            if(aIsSigned && bIsSigned) {
                evaluation = a32 == b32;
            } else if(aIsSigned && !bIsSigned) {
                evaluation = (unsigned)a32 == ub32;
            } else if(!aIsSigned && bIsSigned) {
                evaluation = ua32 == (unsigned)b32;
            } else if(!aIsSigned && !bIsSigned) {
                evaluation = ua32 == ub32;
            }
        } else if(op[0] == '<') {
            if(aIsSigned && bIsSigned) {
                evaluation = a32 < b32;
            } else if(aIsSigned && !bIsSigned) {
                evaluation = (unsigned)a32 < ub32;
            } else if(!aIsSigned && bIsSigned) {
                evaluation = ua32 < (unsigned)b32;
            } else if(!aIsSigned && !bIsSigned) {
                evaluation = ua32 < ub32;
            }
        } else {
            if(aIsSigned && bIsSigned) {
                evaluation = a32 > b32;
            } else if(aIsSigned && !bIsSigned) {
                evaluation = (unsigned)a32 > ub32;
            } else if(!aIsSigned && bIsSigned) {
                evaluation = ua32 > (unsigned)b32;
            } else if(!aIsSigned && !bIsSigned) {
                evaluation = ua32 > ub32;
            }
        }
        printf("%s %s %s\t%s\t%d\n", a, op, b, !aIsSigned || !bIsSigned ? "unsigned" : "signed  ", evaluation);
    }
    return 0;
}
