#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

// pair of pipes

// parent should send a byte to the child
// child prints "<pid>: recieved"
// child writes byte onto same fd and closes the pipe
// parent then reads the byte the child sent back

int main(int argc, char *argv[])
{
    int p[2];
    int pid;
    char buf[10];

    pipe(p);

    pid = fork();

    if (pid < 0) {
        fprintf(2, "error f\n");
        exit(1);
    }
    else if (pid == 0) {
        read(p[0], buf, sizeof(buf));
        printf("%d: recieved %s\n", getpid(), buf); // should put in "ping" for buff
        write(p[1], "pong", 5); 
        close(p[0]);
        close(p[1]);
        exit(0);

    } else {
        write(p[1], "ping", 5);
        wait(0);
        read(p[0], buf, sizeof(buf));
        printf("%d: recieved %s\n", getpid(), buf);

        close(p[0]);
        close(p[1]);
    }
    exit(0);

}