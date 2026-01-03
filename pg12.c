#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 512

int main()
{
    char buf[BUFSIZE];
    struct stat buf3;
    int fd_src, fd_dest, fd, status;
    ssize_t n;

    // Create destination file f2
    fd_dest = creat("f2", 0666);
    if (fd_dest == -1) {
        perror("Error creating f2");
        exit(1);
    }

    // Open source file f1
    fd_src = open("f1", O_RDONLY);
    if (fd_src == -1) {
        perror("Error opening f1");
        exit(1);
    }

    // Copy content from f1 to f2 using read/write
    while ((n = read(fd_src, buf, BUFSIZE)) > 0) {
        if (write(fd_dest, buf, n) != n) {
            perror("Write error");
            exit(1);
        }
    }
    printf("Successfully written\n");

    // Demonstrate lseek
    off_t offset = lseek(fd_src, -2, SEEK_END);
    if (offset == -1) {
        perror("lseek error");
    } else {
        printf("Offset from beginning: %ld\n", offset);
    }

    // Demonstrate fstat
    fd = open("f1", O_RDONLY);
    if (fd == -1) {
        perror("Error opening f1 for fstat");
        exit(1);
    }

    status = fstat(fd, &buf3);
    if (status == -1) {
        perror("fstat error");
        exit(1);
    }

    printf("\nInformation for file f1:\n");
    printf("-------------------------\n");
    printf("File size: \t\t%ld bytes\n", buf3.st_size);
    printf("Number of links: \t%ld\n", buf3.st_nlink);
    printf("File inode: \t\t%ld\n", buf3.st_ino);

    // Close files
    close(fd_src);
    close(fd_dest);
    close(fd);

    return 0;
}
