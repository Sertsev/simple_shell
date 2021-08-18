#include "simishell.h"

/**
 * echoer - a function to echo back any text you gave it
 * @line: an array of command and arguments
 * 
 * Return: returns 1 in success and -1 if it fails
 */

int echoer(char *line[])
{
        int i = 1;

        if (line[i] == NULL)
        {
                write(1, "\n", 2);
                return (1);
        }

        while (line[i] != NULL)
        {
                write(1, line[i], strleng(line[i]));
                i++;
                if (line[i] != NULL)
                        write(1, " ", 2);
        }
        write(1, "\n", 2);
        return (1);
}

/**
 * lister - a function which excutes the /bin/ls program to list files
 * @line: an array of command and arguments
 * 
 * Return: returns 1 in success and -1 if it fails
 */

int cater(char *line[])
{
        int status;
        pid_t waiter, child;
        int i = 0;
        
        child = fork();
        if (child == -1)
                perror("Forking");
        
        if (child == 0)
        {
                execve("/bin/cat", line, NULL);
        }
        else
        {
                waiter = wait(&status);
                if (waiter == -1)
                        perror("Waiting");
        }
        free(line);
        return (1);
}