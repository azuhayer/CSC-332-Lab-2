#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

//replace character function
void replaceChar(char *s, char x, char y) 
{
    int i = 0;
    for(i = 0; s[i]; i++) 
    {
        if(s[i] == x) 
        {
            s[i] = y;
        }
    }
}

int main (int argc, char* argv[]) 
{
    int source, dest;
    char buffer[BUFSIZ];
    int readval;

    if(argc != 3) 
    {
        printf("Usage: \n");
        return 1;
    }

    errno = 0;

    source = open(argv[1], O_RDONLY);   //source.txt
    dest = open(argv[2], O_WRONLY);     //destination.txt

    if(source != -1) 
    {
        
        char *c = (char *) calloc(100,sizeof(char));
        int size = 0;

        while(size = read(source, c ,100)) 
        {
            replaceChar(c, '1', 'L');
            write(dest, c, size);
            write(dest, "XYZ", 3);
        }
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