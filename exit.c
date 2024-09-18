//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    //delete the directory Commands
    printf("Goodbye\n");
    execlp("rm", "rm", "-r", "./Commands", NULL);

    return 0;
}