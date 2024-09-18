//[x]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <math.h>

int main(int argc, char* argv[])
{
    //checks for valid input
    if(argc != 4)
    {
        perror("Invalid input\n");
        exit(1);
    }

    //parse the arguments
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    //calculate the discriminant
    double discriminant = b * b - 4 * a * c;

    //check if the discriminant is negative
    if (discriminant < 0)
    {
        printf("No real solutions\n");
    }
    else if (discriminant == 0)
    {
        //calculate the single solution
        double solution = -b / (2 * a);
        printf("%g\n", solution);
    }
    else
    {
        //calculate the two solutions
        double solution1 = (-b + sqrt(discriminant)) / (2 * a);
        double solution2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("%g, %g\n", solution1, solution2);
    }

    //exits the program
    return 0;
}