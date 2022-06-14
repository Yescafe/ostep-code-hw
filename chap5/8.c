#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int
main(void) {
    int fd[2];
    pid_t child1, child2;

    if (pipe(fd) < 0) {
        fprintf(stderr, "pipe create failed\n");
        exit(1);
    }

    if ((child1 = fork()) < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (child1 == 0) {
        close(fd[0]);
        write(fd[1], "hello world\n", 13);
    }
    else {
        if ((child2 = fork()) < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if (child2 == 0) {
            char buffer[BUFSIZ];
            close(fd[1]);
            read(fd[0], buffer, BUFSIZ - 1);
            printf("child1 said: %s", buffer);
        }
    }

    close(fd[0]);
    close(fd[1]);
    if (child1 > 0) {
        wait(NULL);
        if (child2 > 0) {
            wait(NULL);
        }
    }

    return 0;
}
