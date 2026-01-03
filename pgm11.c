#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    char buf;
    int fd_one, fd_two;

    // Open the source file in read-only mode
    fd_one = open("f1", O_RDONLY);
    if (fd_one == -1)
    {
        printf("Error opening source file f1\n");
        return 1;
    }

    // Open/create the destination file with write permission
    fd_two = open("f2", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_two == -1)
    {
        printf("Error opening/creating destination file f2\n");
        close(fd_one);
        return 1;
    }

    // Copy file byte by byte
    while (read(fd_one, &buf, 1) == 1)
    {
        write(fd_two, &buf, 1);
    }

    printf("File successfully copied\n");

    // Close both files
    close(fd_one);
    close(fd_two);

    return 0;
}
