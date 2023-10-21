
#include <stdio.h>
void binary_print(unsigned int );
int main()
{
   
  binary_print(1);
  binary_print(2);
  binary_print(3);
  binary_print(4);
  binary_print(5);
  binary_print(6);
  binary_print(7);
  binary_print(8);
  binary_print(9);
  binary_print(10);
    return 0;
}
void binary_print(unsigned int value) {
 unsigned int mask = 0xff000000; //  A mask for the highest byte.
 unsigned int shift = 256*256*256; //   A shift for the highest byte.
 unsigned int byte, byte_iterator, bit_iterator;
 for(byte_iterator=0; byte_iterator < 4; byte_iterator++) {
 byte = (value & mask) / shift; // separate each byte.
 printf(" ");
 for(bit_iterator=0; bit_iterator < 8; bit_iterator++) { // Print the byte's bits.
 if(byte & 0x80) // If the highest bit in the byte isn't 0,
 printf("1"); // print a 1.
 else
 printf("0"); // Otherwise, print a 0.
 byte *= 2; // Move all the bits to the left by 1.
 }
 mask /= 256; // Move the bits in mask right by 8.
 shift /= 256; // Move the bits in shift right by 8.
 
 
 printf("\n");
 }
}


/* Output -  Tested on online gdb compiler
 00000000
 00000000
 00000000
 00000001
 00000000
 00000000
 00000000
 00000010
 00000000
 00000000
 00000000
 00000011
 00000000
 00000000
 00000000
 00000100
 00000000
 00000000
 00000000
 00000101
 00000000
 00000000
 00000000
 00000110
 00000000
 00000000
 00000000
 00000111
 00000000
 00000000
 00000000
 00001000
 00000000
 00000000
 00000000
 00001001
 00000000
 00000000
 00000000
 00001010
*/