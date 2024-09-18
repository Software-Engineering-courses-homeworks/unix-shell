//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int file;
    struct stat st = {0};

    //creates a directory within Commands and a file in said directory to store the history of the commands
    if (stat("./Commands/String", &st) == -1)
        mkdir("./Commands/String", 0777);

    //opens the file for writing
    if((file = open("Commands/String/History.txt", O_CREAT | O_WRONLY, 0666)) == -1)
    {
        perror("Error opening file");
        return 1;
    }

    //runs the String_shell.c file
    execl("./String_shell", "./String_shell", NULL);

    close(file);
    return 0;
}