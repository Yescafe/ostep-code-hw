#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char* pathname = "/bin/ls";
char* const args[] = {"ls", ".", NULL};

int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {   // child process
        execl(pathname, args[0], args[1], NULL);
        execv(pathname, args);
    }
    else {                // parent process
        wait(NULL);
    }

    return 0;
}
