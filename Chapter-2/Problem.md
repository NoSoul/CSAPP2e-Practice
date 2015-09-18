2.1 Perform the following number conversions

    A. 0x39A7F8 to binary
    B. Binary 1100100101111011 to hexadecimal
    C. 0xD5E4C to binary
    D. Binary 1001101110011110110101 to hexadecimal

2.2 Fill in the blank entries in the following table, giving the decimal and hexadecimal representations of different powers of 2:

    n       2^n (Decimal)   2^n (Hexadecimal)
    9       512             0x200
    19      ___             ___
    ___     16384           ___
    ___     ___             0x10000
    17      ___             ___
    ___     32              ___
    ___     ___             0x80

2.3 A single byte can be represented by two hexadecimal digits. Fill in the missing entries in the following table, giving the decimal, binary, and hexadecimal values of different byte patterns:

    Decimal Binary      Hexadecimal
    0       00000000    0x00
    167     ___         ___
    62      ___         ___
    188     ___         ___
    ___     00110111    ___
    ___     10001000    ___
    ___     11110011    ___
    ___     ___         0x52
    ___     ___         0xAC
    ___     ___         0xE7

2.4 Without converting the numbers to decimal or binary, try to solve the follow-ing arithmetic problems, giving the answers in hexadecimal. Hint: Just modify the methods you use for performing decimal addition and subtraction to use base 16.

    A. 0x503c + 0x8 = ___
    B. 0x503c − 0x40 = ___
    C. 0x503c + 64 = ___
    D. 0x50ea − 0x503c = ___

2.5 Consider the following three calls to show_bytes:
    
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp, 1); /* A. */
    show_bytes(valp, 2); /* B. */
    show_bytes(valp, 3); /* C. */
Indicate which of the following values will be printed by each call on a little-endian machine and on a big-endian machine:
    
    A. Little endian:___    Big endian:___
    B. Little endian:___    Big endian:___
    C. Little endian:___    Big endian:___
