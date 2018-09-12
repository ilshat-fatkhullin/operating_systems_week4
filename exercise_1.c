#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    if (pid == 0)
        printf("Hello from child %d\n", pid);
    else
        printf("Hello from parent %d\n", pid);
    return 0;
}