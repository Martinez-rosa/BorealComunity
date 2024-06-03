#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    char command[100];

    while (1)
    {
        printf("Enter a command (pwd, ls, ps, exit): ");
        scanf("%s", command);

        if (strcmp(command, "pwd") == 0)
        {
            execlp("/bin/pwd", "pwd", NULL);
        }
        else if (strcmp(command, "ls") == 0)
        {
            execlp("/bin/ls", "ls", "-l", NULL);
        }
        else if (strcmp(command, "ps") == 0)
        {
            execlp("/bin/ps", "ps", "-e", NULL);
        }
        else if (strcmp(command, "exit") == 0)
        {
            exit(0);
        }
        else
        {
            printf("Invalid command\n");
        }

        wait(NULL);
    }

    return 0;
}