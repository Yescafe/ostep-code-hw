#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char str[30];

int
main(void)
{
    printf("hello world, pid = %d\n", (int) getpid());

    int fd = open("2.txt", O_WRONLY | O_APPEND | O_CREAT);
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {   // child process
        write(fd, "hello world", 12);
    }
    else {                // parent process
        write(fd, "hello world", 12);
    }

    close(fd);

    if (rc > 0) {
        int wc = wait(NULL);
        FILE* fp = fopen("hello.txt", "r+");
        if (fp) {
            fgets(str, 30, fp);
            puts(str);
            fclose(fp);
        }
    }

    return 0;
}
