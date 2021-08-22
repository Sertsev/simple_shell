#include "simishell.h"

void sigintHandler(int sig_num __attribute__((unused)))
{
    signal(SIGINT, sigintHandler);
    write(1, "\n", 2);
    printprompt(0);
    fflush(stdout);
}

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

               if ((shellprocessor(strbrk(line), argv)) == -1)
                {
                        perror("Error");
                }
        } while(1);       

        return (0);
}