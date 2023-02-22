#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main (int argc, char* argv[]) 
{
    int source, dest;
    char buffer[BUFSIZ];

    if(argc != 3) 
    {
        printf("Usage: \n");
        return 1;
    }

    errno = 0;

    //Open both files
    source = open(argv[1], O_RDONLY); //source
    dest = open(argv[2], O_CREAT | O_RDWR, 00777); //destination

    if(source != -1) 
    {
        write(dest, buffer, read(source, buffer, sizeof(buffer)));

        //Close both files
        close(source); 
        close(dest);
    }

    else 
    {
        if(errno == ENOENT) 
            printf("There is no file(s) in directory.\n");
        else if(errno == EACCES) 
            printf ("Permissions denied.\n");
        return 0;
    }

    return 0;
}