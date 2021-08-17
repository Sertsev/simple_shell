#include "simishell.h"

/**
 * shellexcuter - a function which excutes the given commands
 * @line: a pointer 
 * 
 * Return: returns 1 in success and -1 if it fails
 */

int shellprocessor(char **line)
{
        int i = 0;

        if (!line)
                return (1);

        while(line[i] != NULL && line[i][0] != '\n')
        {
                printf("-> %s\n", line[i++]);
        }

        
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
                printf("$ ");
        else if(i == 1)
                printf("> ");
}
