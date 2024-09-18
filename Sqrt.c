//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double res;
    //checks for valid input
    if(argc != 2)
    {
        perror("Invalid input");
        exit(1);
    }
    if(atoi(argv[1]) < 0)
    {
        perror("Math Error!");
        exit(1);
    }

    res = sqrt(atoi(argv[1]));
    //prints the square root of the given number
    printf("%g\n", res);

    //exits the program
    return 0;
}