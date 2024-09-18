//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <math.h>

int main(int argc, char* argv[])
{
    //checks for valid input
    if(argc != 3)
    {
        perror("Invalid input");
        exit(1);
    }

    //checks if the given numbers are valid
    if(atoi(argv[1]) == 0 && atoi(argv[2]) <= 0)
    {
        perror("Invalid input");
        exit(1);
    }

    //prints the square root of the given number
    printf("%g\n", pow(atoi(argv[1]), atoi(argv[2])));

    //exits the program
    return 0;
}