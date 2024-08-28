#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        fprintf(2, "sleep: missing argument\n"); // stream 2 = error
        exit(1);
    }
    int pause = atoi(argv[1]);

    sleep(pause);

    exit(0);
}