#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //check if the num of arguments is correct
    if(argc != 4)
    {
        perror("Error with num of arguments\n");
        exit(1);
    }
    
    //check if the starting point is in the string
    if(atoi(argv[3])>strlen(argv[1]))
    {
        perror("starting point not in string\n");
        exit(1);
    }
    
    char* str = malloc(strlen(argv[1]));
    
    //copy the string
    strcpy(str,argv[1]);
    
    //replace the string
    for (int i=0;i<strlen(argv[2]);i++)
    {
        if(atoi(argv[3])+i-1<strlen(argv[1]))
            str[atoi(argv[3])+i-1] = argv[2][i];
    }
    
    //print the string
    printf("%s\n",str);
    
    //free the memory
    free(str);
    return 0;
}