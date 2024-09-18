//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

unsigned int decimalToBinary(int n)
{
    unsigned int binaryNumber = 0;
    int remainder = 1, i = 1;

    if (n < 0) {
        binaryNumber = 1 << 31; // Set the most significant bit to 1 for negative numbers
        n = -n; // Convert the negative number to positive
    }

    while(n != 0)
    {
        int bit = n & 1;
        binaryNumber |= bit * i;
        i <<= 1;
        n >>= 1;
    }

    return binaryNumber;
}

int main(int argc, char* argv[])
{
    //checks for valid input
    if(argc != 2)
    {
        printf("invalid input\n");
        exit(1);
    }

    //parse the arguments
    unsigned int binnum = decimalToBinary(atoi(argv[1]));
    int counter = 0;

    //count the number of 1s in the binary representation
    for(int i = 0; i < 32; i++)
    {
        if(binnum & 1)
        {
            counter++;
        }
        binnum = binnum >> 1;
    }

    //if the number is negative, calculate the number of 1s in the one's complement
    if(atoi(argv[1]) < 0)
    {
        counter = 32 - counter + 1;
    }

    printf("%d\n", counter);

    return 0;
}