//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    int file;
    struct stat st = {0};

    //creates a directory within Commands and a file in said directory to store the history of the commands
    if (stat("./Commands/Math", &st) == -1)
        mkdir("./Commands/Math", 0777);

    //opens the file for writing
    if((file = open("./Commands/Math/History.txt", O_CREAT | O_RDWR, 0666)) == -1)
    {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    close(file);
    //runs the Math_shell.c file
    if(execl("./Math_shell", "Math_shell", NULL) == -1)
    {
        perror("Error running Math_shell");
        return 1;
    }

    return 0;
}