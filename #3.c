#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) 
{
    int src_fd, dst_fd, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];
    
    if (argc != 3) 
    {
        printf("Usage: %s SourceFile DestinationFile\n", argv[0]);
        return 1;
    }

    src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) 
    {
        perror("Error opening source file");
        return errno;
    }

    dst_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) 
    {
        perror("Error opening destination file");
        return errno;
    }

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) 
    {
        bytes_written = write(dst_fd, buffer, bytes_read);
        if (bytes_written == -1) 
        {
            perror("Error writing to destination file");
            return errno;
        }
    }

    if (bytes_read == -1) 
    {
        perror("Error reading source file");
        return errno;
    }

    if (close(src_fd) == -1) 
    {
        perror("Error closing source file");
        return errno;
    }

    if (close(dst_fd) == -1) 
    {
        perror("Error closing destination file");
        return errno;
    }

    return 0;
}