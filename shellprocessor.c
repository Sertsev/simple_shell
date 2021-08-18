#include "simishell.h"

int cater(char *line[]);

/**
 * exitor - a function to exit from the program
 * @line: an array of command and arguments
 * 
 * Return: no return
 */

int exitor(char *line[])
{
        free(line);
        exit(EXIT_SUCCESS);
}

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
        int i = 0;
        
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
 * getfunc - a function which selects a function based on the commands
 * @str: a command string pointer
 * @line: an array of command and arguments
 * 
 * Return: returns 1 in success and -1 if it fails.
 */

int (*getfunc(char *str))(char **line)
{
        int i = 0;
        selecte selector[] = {
                {"ls", lister},
                {"l", lister},
                {"/bin/ls", lister},
                {"exit", exitor},
                {"echo", echoer},
                {"/bin/echo", echoer},
                {"cat", cater},
                {"/bin/cat", cater},
                {NULL, NULL}
        };
       //printf("get [%s] [%s] %d\n", str, selector[i].command, i);

        while (!strcomp(selector[i].command, str) && (selector[i].command != NULL))
                i++;

        //printf("get %s %d\n", selector[i].command, i);

        if (selector[i].command == NULL)
                return NULL;

        return selector[i].funcptr;
}

/**
 * shellexcuter - a function which excutes the given commands
 * @line: a pointer 
 * 
 * Return: returns 1 in success and -1 if it fails
 */

int shellprocessor(char **line)
{
        int check;
        int i = 0;

        if (!line)
                return (1);
        // while(line[i] != NULL)
        //         printf("shell %s\n", line[i++]);

        if (getfunc(line[0]) == NULL)
                printf("%s: command not found\n", line[0]);
        else
                getfunc(line[0])(line);

        
        return (1);
}

/**
 * printprompt - a function to display the enter command character
 * @i: an integer value to indicate which icon to display
 * 
 * Return: void
 */

void printprompt(int i)
{
        if (i == 0)
                printf("USH$ ");
        else if(i == 1)
                printf("ush> ");
}
