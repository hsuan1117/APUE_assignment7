#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // child process
        pid_t sid = setsid();
        if (sid < 0) {
            printf("Error: cannot create a new session\n");
            return -1;
        }

        printf("child process pid: %d, pgid: %d, sid: %d\n", getpid(), getpgid(getpid()), sid);

        FILE *fp;
        char str[1024];
        char real_cmd[1024];
        char *cmd = "ps -x -o pid,pgid,tpgid";
        sprintf(real_cmd, cmd, getpgid(getpid()));

        fp = popen(real_cmd, "r");
        if (fp == NULL) {
            printf("popen failed\n");
            return -1;
        }
        while (fgets(str, sizeof(str), fp) != NULL) {
            printf("%s", str);
        }
        pclose(fp);
    } else if (pid > 0) {
        // parent process
        // semaphore wait
        wait(NULL);
    } else {
        perror("Error: cannot fork a new process\n");
        return -1;
    }
    return 0;
}
