#include <stdio.h>

void displayBitPattern(int num) {
    int bit;
    int numBits = sizeof(num) * 4; // Number of bits in an integer (assuming 8 bits per byte)

    for (int i = numBits - 1; i >= 0; i--) {
        bit = (num >> i) & 1; // Get the i-th bit
        printf("%d", bit);
        
        if (i % 4 == 0) {
            printf(" "); // Add a space every 4 bits
        }
    }

    printf("\n");
}

int main() {
    int num = 27; // Replace this with the integer you want to display
    displayBitPattern(num);
    return 0;
}
