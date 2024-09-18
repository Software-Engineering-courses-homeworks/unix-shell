//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    //checks for valid input
    if(argc != 2)
    {
        perror("invalid input\n");
        exit(1);
    }
    int f;
    char buffer[128];

    if((f = open(argv[1], O_RDONLY, 0644)) == -1)
    {
        printf("File not found\n");
        exit(1);
    }

    //reads the file and calculates it's size
    while(read(f, buffer, 128) > 0)
    {
        printf("%s", buffer);
    }

    //closes the file and frees the buffer
    close(f);
    return 0;
}