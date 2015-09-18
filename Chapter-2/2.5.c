#include <stdio.h>

unsigned char g_LittleEndian;

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, int len)
{
    int i;
    printf("%s: ", g_LittleEndian ? "Little endian" : "Big endian");
    for(i = 0; i < len; i++) {
        if(i) {
            putchar(' ');
        }
        printf("%.2x", start[i]);
    }
    printf("\t%s: ", !g_LittleEndian ? "Little endian" : "Big endian");
    for(i = 0; i < len; i++) {
        if(i) {
            putchar(' ');
        }
        printf("%.2x", start[3 - i]);
    }
    printf("\n");
}

int main()
{
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer) &val;
    g_LittleEndian = *valp == 0x21;
    show_bytes(valp, 1); /* A. */
    show_bytes(valp, 2); /* B. */
    show_bytes(valp, 3); /* C. */
    return 0;
}
