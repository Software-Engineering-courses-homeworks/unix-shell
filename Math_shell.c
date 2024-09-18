//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

//writes the command to the history file
void write_to_history(int fd,char* line,int num_of_line)
{
    int wbytes;
    char* new_line = malloc(sizeof(line)+2);
    
    //adds the line number to the beginning of the line
    sprintf(new_line,"%d.%s \n",num_of_line,line);
    
    //writes the line to the history file
    wbytes = write(fd,new_line,strlen(new_line));
    free(new_line);
}

//reads the next line in the history file
int read_next_line(int fd)
{
    int rbytes,count = 1;
    char check[2];
    
    lseek(fd,SEEK_SET,0);
    
    while((rbytes=read(fd,check,1))>0)
    {
        if(strcmp(check,"\n")==0 )
            count++;
    }
    
    return count;
}

int main()
{
    char cmd[1024];
    char* args[5] = {NULL}, tempbuff[1024];
    int history, commandcounter, j = 0;

    //opens the history file for this shell with read and write permissions
    if((history = open("./Commands/Math/History.txt", O_RDWR, 0644)) == -1)
    {
        perror("Error opening file");
        exit(1);
    }

    commandcounter = read_next_line(history);

    //prompts the user to enter a command
    printf("MathShell> ");
    scanf("%[^\n]s", cmd);
    scanf("%*c");
    
    //writes the command to the history file
    write_to_history(history, cmd, commandcounter);
    commandcounter++;

    //splits the cmd line to its arguments
    args[0] = strtok(cmd, " ");

    while(strcmp("Cls", args[0]) != 0)
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
            //runs the custom shells and gives a prompt for unsupported ones
            if (strcmp(args[0], "Sqrt") == 0 || strcmp(args[0], "Power") == 0 || strcmp(args[0], "Solve") == 0)
            {
                //pre-proccessing for the command
                for(int i = 1; i < 4; i++)
                {
                    args[i] = strtok(NULL, " ");
                }

                tempbuff[0] = '.';
                tempbuff[1] = '/';
                tempbuff[2] = '\0';
                // Copy the first argument into cmd starting from the third position
                strcat(tempbuff, args[0]);
                
                // Execute the command with execv
                execv(tempbuff, args);
                
                // Print an error message if the command fails
                perror("Error running command");
                exit(1);
            }
            else if(strcmp(args[0], "History") == 0)
            {
                tempbuff[0] = '.';
                tempbuff[1] = '/';
                tempbuff[2] = '\0';
                // Copy the first argument into cmd starting from the third position
                strcat(tempbuff, args[0]);
                // Execute the command with execv
                execl(tempbuff, tempbuff, "./Commands/Math/History.txt", NULL);
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
        printf("MathShell> ");
        scanf("%[^\n]s", cmd);
        scanf("%*c");
    
        //writes the command to the history file
        write_to_history(history, cmd, commandcounter);
        commandcounter++;
            
        //splits the cmd line to its arguments
        args[0] = strtok(cmd, " ");
    }

    //closes the history file and exits the shell
    close(history);
    return 0;
}