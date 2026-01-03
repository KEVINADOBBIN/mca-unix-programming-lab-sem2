#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>  // Required for wait()

int main()
{
    int n, i;
    pid_t pid;

    printf("Enter the number of child processes to be created: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        pid = fork();

        if (pid < 0)
        {
            perror("Fork failed");
            exit(1);
        }
        else if (pid == 0) // Child process
        {
            printf("This is child process with PID %d, Parent PID %d\n", getpid(), getppid());
            exit(0);
        }
        else // Parent process
        {
            printf("This is parent process with PID %d\n", getpid());
        }
    }

    // Parent waits for all children to finish
    for (i = 0; i < n; i++)
        wait(NULL);

    return 0;
}