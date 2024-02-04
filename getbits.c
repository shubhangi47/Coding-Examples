#include <stdio.h>
/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main() {
    unsigned x = 170;  // Binary: 10101010
    int p = 4;
    int n = 3;

    unsigned result = getbits(x, p, n);

    printf("Result: %u\n", result);  // Output: 5 (Binary: 101)
    return 0;
}
