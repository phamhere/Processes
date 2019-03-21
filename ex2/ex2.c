// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // opening text.txt with write permissions and saving it to a file_pointer variable
    FILE *file_pointer = fopen("text.txt", "w");
    int pid = fork();

    // if child process write something, if parent process write another thing
    if (pid == 0)
        fprintf(file_pointer, "%s", "Child process wrote this.\n");
    else
        fprintf(file_pointer, "%s", "Parent process wrote this.\n");
    // close file
    fclose(file_pointer);
    
    return 0;
}
