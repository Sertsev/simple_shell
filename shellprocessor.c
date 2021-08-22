#include "simishell.h"

/**
 * exitor - a function to exit from the program
 * @line: an array of command and arguments
 * 
 * Return: no return
 */

int exitor(char *line[])
{
        int i = 0;
        if (line[1] == NULL)
                exit(EXIT_SUCCESS);
        else if (atoi(line[1]) > 0)
                i = atoi(line[1]);
        free(line);
        exit(i);
}

/**
 * changedir - a function to change a directory
 * @line: an array of commands and arguments
 * 
 * Return: returns 0 in success and -1 if it fails
 */

int changedire(char **line)
{
        if (line[1] == NULL)
                chdir(getenv("HOME"));
        else if (chdir(line[1]) == -1)
        {
                write(1, line[0], strleng(line[0]));
                write(1, ": ", 3);
                write(1, ": cd", strleng(": cd"));
                write(1, ": can't cd to ", strleng(": can't cd to "));
                write(1, line[1], strleng(line[1]));
                write(1, "\n", 2);
                return (-1);
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
            {"ll", lister},
            {"exit", exitor},
            {"echo", echorr},
            {"cd", changedire},
            {"cat", cater},
            {"pwd", pwder},
            {"env", envir},
            {"printenv", envir},
            {"/bin/printenv", envir},
            {"/bin/env", envir},
            {"mkdir", maker},
            {NULL, NULL}};
        while (!strcomp(selector[i].command, str) && (selector[i].command != NULL))
                i++;

        if (selector[i].command == NULL)
        {
                return (NULL);
        }

        return selector[i].funcptr;
}

/**
 * shellexcuter - a function which excutes the given commands
 * @line: a pointer 
 * 
 * Return: returns 1 in success and -1 if it fails
 */

int shellprocessor(char **line, char **argv)
{
        int check;
        int i = 0;

        if (!line)
                return (1);

        if (getfunc(line[0]) == NULL)
        {
                i = builtincom(line);
                if (i != 0)
                {
                        for (i = 0; line[0][i] != '\0'; i++)
                        {
                                if (line[0][i] == '/')
                                {
                                        check = 1;
                                        break;
                                }
                        }
                        if (check == 1)
                        {
                                write(1, argv[0], strleng(argv[0]));
                                write(1, ": ", 3);
                                write(1, line[0], strleng(line[0]));
                                write(1, ": No such file or directory\n", strleng(": No such file or directory\n"));
                                exit(EXIT_FAILURE);
                        }
                        else
                        {
                                write(1, line[0], strleng(line[0]));
                                write(1, ": not found\n", strleng(": not found\n"));
                                exit(EXIT_FAILURE);
                        }
                }
        }
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
                write(1, "USH$ ", strleng("USH$ "));
        else if (i == 1)
                write(1, "ush> ", strleng("ush> "));
}
