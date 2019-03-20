// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int pid = fork();
    // creating a null terminated array of char pointers
    char *myargs[] = {"/bin/ls", NULL};
    // running `/bin/ls`
    execv(myargs[0], myargs);
    
    return 0;
}
