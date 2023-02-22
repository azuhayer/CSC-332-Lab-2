#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char* argv[]) 
{
    int returnVal;
    returnVal = open("destination.txt", O_CREAT | O_RDWR, 00777);

    if(returnVal == -1) 
    {
        printf("\n Error: %d\n", errno);
    }
    else 
    {
        printf("\n File successfully opened!\n");
    }
    return 0;
}