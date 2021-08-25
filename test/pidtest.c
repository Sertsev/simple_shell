#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>

struct stat st;

int main(int argc, char *argv[])
{
    pid_t pidaddr, ppidaddr;
    int pidf;
    int fsize;
    char pidmax[25];

    pidf = open("/proc/sys/kernel/pid_max", O_RDONLY);
    
    stat("text.txt", &st);
    fsize = st.st_size;

    read(pidf, pidmax, (char)fsize);


    pidaddr = getpid();
    ppidaddr = getppid();

    printf("child process ID: %d \nParent process ID: %d\nPID Max: %s\n", pidaddr, ppidaddr, pidmax);

    close(pidf);
    return (0);
}