#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main (int argc, char* argv[]) 
{
    char* fileName = argv[1];
    int returnVal;
    char buffer[returnVal];
    
    returnVal = access(fileName, F_OK);
    if(returnVal == 0) 
    {
        // Open, Read, and then Write
        returnVal = open(fileName, O_RDONLY);
        read(returnVal, buffer, sizeof(buffer));
        write(returnVal, buffer, sizeof(buffer));
        close(returnVal);

        //print file content
        printf("%s\n", buffer);
    }
    else 
    {
        if(errno == ENOENT) 
            printf("%s No such file found in the directory.\n", fileName);
        else if(errno == EACCES) 
            printf ("%s Permissions denied.\n", fileName);
        return 0;
    }
    return 0;
}