#include "simishell.h"

/**
 * sigintHandler - a function to handle the ctrl-c signal
 * @sig_num: an integer signal indicator
 *
 * Return: void function
 */

void sigintHandler(int sig_num __attribute__((unused)))
{
signal(SIGINT, sigintHandler);
write(1, "\n", 2);
printprompt(0);
fflush(stdout);
}

/**
 * main - a the main function of the shell
 * @argc: the number of arguments given
 * @argv: an array of given argument strings
 *
 * Return: returns an integer
 */

int main(int argc __attribute__((unused)), char **argv)
{
char *line;

line = malloc(256);

description();
write(1, "\n", 2);

do {
if (getstr(line) == (-1))
{
write(1, "\n", 2);
exit(1);
}

if ((shellprocessor(strbrk(line, ' '), argv)) == -1)
{
perror("Error");
}
} while (1);

return (0);
}
