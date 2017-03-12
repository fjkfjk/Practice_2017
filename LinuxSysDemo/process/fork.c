//This an example of fork() usage

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = fork();
    switch(pid)
    {
        case 0:
            printf("Child process is running,pid is %d\n",getpid());
            break;
        case -1:
            printf("create process failed!\n");
            exit(1);
            break;
        default:
            printf("Parent process is running,pid is %d\n",getpid());
    }
    exit(0);
}