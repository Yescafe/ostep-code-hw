#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid %d)\n", (int) getpid());

    int n = 0;

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {   // child process
        printf("child process: before modifying n: %d\n", n);
        n = 2;
        printf("child process: after modifying n: %d\n", n);
    }
    else {                // parent process
        printf("parent process: before modifying n: %d\n", n);
        n = 1;
        printf("parent process: after modifying n: %d\n", n);
    }

    return 0;
}
