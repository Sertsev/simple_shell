#include "simishell.h"

/**
 * _getchar - a function that reads a character from the standard input
 * 
 * Return: returns the read character
 */

char _getchar()
{
    char *buf;
    char c;
    int i = 0;
    
    buf = malloc(2);
    if (!buf)
        return (-1);

    fflush(stdout);
    
    i = read(1, buf, 1);
    if (i == -1)
    {
        perror("Reading Char");
        return (-1);
    }
    
    c = *buf;
    
    return c;
}

/**
 * _getline - a function to read a line from the standard input
 * @line: a pointer to a pointer of location to save the string
 * @len: the size of the characters read
 * 
 * Return: returns the size of the read string
 */

int _getline(char **restrict line, size_t *restrict len)
{
    int limit = 25;
    char *tmp;

    line[0] = malloc(25);
    if (!line[0])
        return (-1);
    *len = 0;
    
    while (line[0][*len - 1] != '\n')
    {
        line[0][*len] = _getchar();
        *len += 1;

        if (*len > (limit - 3))
        {
            tmp = realloc(line[0], limit + 10);
            if (tmp)
                line[0] = tmp;
            else
                perror("Reallocation");
            limit += 10;
        }
    }

    return (*len);
}