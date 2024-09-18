//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    char buffer[80];

    //check the argument number
    if (argc != 2) {
        printf("Error! cant get argument\n");
        return 1;
    }

    execl("PrintFile", "PrintFile", argv[1], NULL);
    
    perror("Error exceuting command");
    return 1;   
}