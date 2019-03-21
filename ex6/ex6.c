/*
Write a program that will find the average time it takes for your computer
to make a system call an empty write to stdout. Your program should use the 
`clock_gettime` procedure to time how long a single system call takes. It'll 
do this for one million iterations, and then find the average of all of those 
iterations in nanoseconds.
For some helpful documentation and examples of using time-related system calls,
visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
While the linked site does say that `clock_gettime()` does not work on OSX, this 
turns out to only be the case for OSX versions < 10.12. Anything later than that 
and `clock_gettime()` should work just fine. 
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    // initiating variables to hold later data
    struct timespec start, end;
    long sum = 0;
    double avg;

    // iterating number_iter times
    for (int i = 0; i < number_iter; i++) {
        // getting start time and saving to &start; using CLOCK_MONOTONIC since figuring out elapsed time
        clock_gettime(CLOCK_MONOTONIC, &start);
        // making an empty write to stdout
        write(fileno(stdout), NULL, 0);
        // getting end time
        clock_gettime(CLOCK_MONOTONIC, &end);
        // adding the to sum time difference; multiplying by a billion since converting sec to nanosec
        sum += BILLION * (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec);
    }
    // averaging sum in nanoseconds
    avg = sum / (float) number_iter;

    printf("Average time to make a system call an empty write to stdout is: %f ns.\n", avg);
    
    return 0;
}
