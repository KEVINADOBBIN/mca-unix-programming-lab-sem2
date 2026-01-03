#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    char msg[80], buf[80];
    int p[2];        // pipe file descriptors
    pid_t pid;
    ssize_t byread;

    // Create pipe
    if (pipe(p) == -1) {
        perror("pipe failed");
        exit(1);
    }

    printf("Reading fd is %d\n", p[0]);
    printf("Writing fd is %d\n", p[1]);

    // Fork a child process
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid > 0)  // Parent process
    {
        close(p[0]);  // Close read end

        printf("Enter the message: ");
        fflush(stdout);  // Ensure prompt is displayed

        // Read from standard input
        byread = read(0, msg, sizeof(msg));
        if (byread == -1) {
            perror("read failed");
            exit(1);
        }

        // Write to pipe
        write(p[1], msg, byread);

        close(p[1]); // Close write end
        wait(NULL);  // Wait for child
    }
    else  // Child process
    {
        close(p[1]);  // Close write end

        // Read from pipe
        byread = read(p[0], buf, sizeof(buf));
        if (byread == -1) {
            perror("read from pipe failed");
            exit(1);
        }

        buf[byread] = '\0';  // Null-terminate string
        printf("The message read is: %s\n", buf);

        close(p[0]); // Close read end
        exit(0);
    }

    return 0;
}
