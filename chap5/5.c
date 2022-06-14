#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    printf("(%d) hello world in parent\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {   // child process
        int wc = wait(NULL);
        printf("(%d) wc in child is %d\n", (int) getpid(), wc);
        printf("(%d) hello world in child\n", (int) getpid());
    }
    else {                // parent process
        int wc = wait(NULL);
        printf("(%d) wc in parent = %d\n", (int) getpid(), wc);
    }

    return 0;
}
