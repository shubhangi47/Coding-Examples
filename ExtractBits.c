#include <stdio.h>
#include <stdint.h>
/* Extracting bits from a byte */
uint32_t extractBits(uint8_t number, int startBit, int endBit) {
     startBit = (startBit < 0) ? 0 : (startBit > 8) ? 8 : startBit;
    endBit = (endBit < 0) ? 0 : (endBit > 8) ? 8 : endBit;

    
    if (startBit > endBit) {
        int temp = startBit;
        startBit = endBit;
        endBit = temp;
    }

    
    uint8_t bitmask = ((1U << (endBit - startBit + 1)) - 1) << startBit;

    
    uint8_t extractedBits = (number & bitmask) >> startBit;

    return extractedBits;
}

int main() {
    uint8_t number = 0b10010101; 

    int startBit = 7;
    int endBit = 7;

    uint8_t result = extractBits(number, startBit, endBit);

    printf("Original number: 0b%b\n", number);
    printf("Extracted bits  : 0b%b\n", result);

    return 0;
}
