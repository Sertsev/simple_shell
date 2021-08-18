#ifndef SIMISHELL_H
#define SIMISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

extern int errno;

typedef struct selectfunction {
        char *command;
        int (*funcptr)(char **line);
} selecte;

void printprompt(int i);
int exitor(char *line[]);
int cater(char *line[]);
int getstr (char *str);
int shellprocessor(char **line);
char **strbrk(char *line);
void farewell();
void description();
void printstar();
void printstr(char *s);
int strleng(char *s);
void strcopy(char *src, char *dest);
int strcomp(char *str, char *equ);
void strmix(char *src, char *dest);
int lister(char **line);
int (*getfunc(char *str))(char **line);
int echoer(char *line[]);

#endif