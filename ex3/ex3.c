// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int pid = fork();

    // if child process print hello, otherwise print goodbye
    if (pid == 0)
        printf("hello\n");
    else
    {
        // wait for child process to end before printing goodbye
        waitpid(pid, NULL, 0);
        printf("goodbye\n");
    }

    return 0;
}
