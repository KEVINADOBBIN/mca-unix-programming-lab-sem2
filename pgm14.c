#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>  // Needed for pid_t

int main()
{
    pid_t procid;

    procid = fork();  // Create a child process

    if (procid < 0)
    {
        perror("Fork failed");
        exit(1);
    }
    else if (procid == 0)  // Child process
    {
        printf("Child process with PID %d is exiting\n", getpid());
        exit(0);
    }
    else  // Parent process
    {
        printf("Parent process with PID %d is sleeping\n", getpid());
        printf("The child process %d has become a zombie\n", procid);
        sleep(35);  // Keep child as zombie
        printf("Parent process exiting, zombie child will be reaped automatically\n");
    }

    return 0;
}
