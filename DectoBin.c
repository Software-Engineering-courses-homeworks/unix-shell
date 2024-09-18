//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

unsigned int decimalToBinary(int n)
{
    int binaryNumber = 0;
    int remainder, i = 1;

    while(n != 0)
    {
        remainder = n % 2;
        n = n / 2;
        binaryNumber += remainder * i;
        i = i * 10;
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

    unsigned int binnum = decimalToBinary(atoi(argv[1]));
    printf("%d\n", binnum);


    return 0;
}