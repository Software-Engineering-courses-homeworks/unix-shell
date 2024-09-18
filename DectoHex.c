//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    //checks for valid input
    if(argc != 2)
    {
        printf("invalid input\n");
        exit(1);
    }
    
    printf("%X\n", atoi(argv[1]));

    return 0;
}