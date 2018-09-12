#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <wait.h>

int main() {

    char input[256];
    char *path = "/bin/";
    char program[256];
    char cmd[256];

    while (1) {
        if (!fgets(input, 256, stdin))
            break;

        memset(cmd, 0, sizeof(cmd));

        strncpy(cmd, input, (strlen(input) - 1));

        strcpy(program, path);

        strcat(program, cmd);

        int pid = fork();

        if (pid == 0) {
            execl(program, cmd, NULL);
            exit(0);
        } else {
            wait(NULL);
        }
    }
}