//[]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    int file;
    struct stat st = {0};

    //creates a directory within Commands and a file in said directory to store the history of the commands
    if (stat("./Commands/Logic", &st) == -1)
        mkdir("./Commands/Logic", 0777);

    //opens the file for writing
    if((file = open("Commands/Logic/History.txt", O_CREAT | O_WRONLY, 0666)) == -1)
    {
        perror("Error opening file");
        return 1;
    }

    //runs the Math_shell.c file
    execl("./Logic_shell", "./Logic_shell", NULL);

    close(file);
    return 0;
}