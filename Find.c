//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Error with num of arguments");
        exit(1);
    }
    int fd,rbytes;
    char buff[1024];

    fd= open(argv[1],O_RDWR,0644);
    if(fd<0)
    {
        printf("Error at opening file\n");
        exit(1);
    }
    rbytes = read(fd,buff,strlen(argv[2]));
    if(rbytes<0)
    {
        printf("Error at reading from file\n");
        exit(1);
    }
    while(rbytes>0)
    {
        //printf("String: %s\n", buff);
        if(strstr(buff,argv[2])!=NULL)
        {
            printf("WIN\n");
            return 0;
        }
        rbytes = read(fd,buff,1024);
        if(rbytes<0)
        {
            printf("Error at reading from file\n");
            exit(1);
        }
    }
    //printf("String: %s\n", argv[2]);
    printf("Try again\n");
    return 0;
}