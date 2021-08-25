#include <stdio.h>
#include <unistd.h>
#include <errno.h>

extern int errno;

int main()
{
        char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
        char *err = "Excuting ";

        if (execve(argv[0], argv, NULL) == -1)
        {
                perror("Error: ");
        }

        return (0);
}