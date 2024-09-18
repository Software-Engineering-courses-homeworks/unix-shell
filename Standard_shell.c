//[x]
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main()
{
    char cmd[1024], *args[5], tempbuff[1024];

    //creates a directory to store the history of the commands
    if(mkdir("./Commands", 0777) == -1)
    {
        perror("Error creating directory");
        exit(1);
    }

    //prompts the user to enter a command
    printf("StandShell> ");
    scanf("%[^\n]s", cmd);
    scanf("%*c");

    //splits the cmd line to its arguments
    args[0] = strtok(cmd, " ");
    
    for(int i = 1; i < 4; i++)
    {
        args[i] = strtok(NULL, " ");
    }

    while(strcmp("exit", args[0]) != 0 && strcmp("Exit", args[0]) != 0)
    {
        //forks a child process
        int pid = fork();

        //checks if the fork failed
        if(pid < 0)
        {
            printf("Fork failed\n");
            exit(1);
        }
        //excutes the command with the given arguments
        else if(pid == 0)
        {
            //tries to execute the system commands and upon failure, runs the custom commands
            execvp(args[0], args);
            
            //runs the custom shells and gives a prompt for unsupported ones
            if (strcmp(args[0], "String") == 0 || strcmp(args[0], "Math") == 0 || strcmp(args[0], "Logic") == 0)
            {
                //pre-proccessing for the command
                tempbuff[0] = '.';
                tempbuff[1] = '/';
                tempbuff[2] = '\0';
                // Copy the first argument into cmd starting from the third position
                strcat(tempbuff, args[0]);
                
                // Execute the command with execv
                execv(tempbuff, args);
                exit(1);
            }
            else
            {
                //handle unrecognized commands
                printf("Not Supported\n");
                exit(1);
            } 
        }
        //waits for the child process to finish
        wait(NULL);
        //prompts the user to enter a command
        printf("StandShell> ");
        scanf("%[^\n]s", cmd);
        scanf("%*c");

        if(strlen(cmd) == 0)
        {
            continue;
        }

        //splits the cmd line to its arguments
        args[0] = strtok(cmd, " ");
        
        for(int i = 1; i < 4; i++)
        {
            args[i] = strtok(NULL, " ");
        }
    }

    //exits the shell with the file exit.c
    execl("exit", "exit", NULL);

    return 0;
}