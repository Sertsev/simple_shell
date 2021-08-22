#include "simishell.h"

/**
 * lister - a function which excutes the /bin/ls program to list files
 * @line: an array of command and arguments
 *
 * Return: returns 1 in success and -1 if it fails
 */

int lister(char *line[])
{
        int status;
        pid_t waiter, child;
        
        child = fork();
        if (child == -1)
                perror("Forking");
        
        if (child == 0)
        {
                execve("/bin/ls", line, NULL);
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
 * cater - a function which excutes the /bin/cat program to show text files
 * @line: an array of command and arguments
 * 
 * Return: returns 1 in success and -1 if it fails
 */

int cater(char *line[])
{
        int status;
        pid_t waiter, child;
        
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

/**
 * 
 * 
 */

int builtincom(char **line)
{
        int status;
        pid_t waiter, child;
        
        child = fork();
        if (child == -1)
                perror("Forking");

        if (child == 0)
        {
                execve(line[0], line, NULL);
                if (errno != 0)
                {
                        return (errno);
                }
        }
        else
        {
                waiter = wait(&status);
                if (waiter == -1)
                        perror("Waiting");
        }

        free(line);
        return (0);
}

/**
 * powder - a function which excutes the /bin/ls program to list files
 * @line: an array of command and arguments
 * 
 * Return: returns 1 in success and -1 if it fails
 */

int pwder(char *line[])
{
        int status;
        pid_t waiter, child;
        
        child = fork();
        if (child == -1)
                perror("Forking");
        
        if (child == 0)
        {
                execve("/bin/pwd", line, NULL);
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


int echorr(char *line[])
{
        int status;
        pid_t waiter, child;
        
        child = fork();
        if (child == -1)
                perror("Forking");
        
        if (child == 0)
        {
                execve("/bin/echo", line, NULL);
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