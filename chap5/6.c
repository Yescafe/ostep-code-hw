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
        printf("(%d) hello world in child\n", (int) getpid());
    }
    else {                // parent process
        int wpc = waitpid(rc, NULL, 0);
        printf("(%d) wc in parent = %d\n", (int) getpid(), wpc);
    }

    return 0;
}
