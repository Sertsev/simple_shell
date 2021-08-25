#include <stdio.h>
#include <stdlib.h>

/********************
 * main - a function to print any argument you gave it
 * Return: return 0 on success
 ********************/

int main(int argc, char *argv[])
{
        int i = 0;

        while(argv[++i] != NULL)
        {
                printf(" %s \n", argv[i]);
        }

        return (0);
}