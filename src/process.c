#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#include "transactions.h"
#include "utils.h"

// Child process logic: execute transactions and exit with the number of transactions processed
void execute_process(const char *group)
{
    int processed = execute_transactions(group);
    exit(processed); // Return value used by parent via wait
}

int main()
{
    // Define 16 groups labeled A to P
    char *groups[] = {
        "A", "B", "C", "D", "E", "F", "G", "H",
        "I", "J", "K", "L", "M", "N", "O", "P"};
    struct timespec start_time, end_time;
    pid_t pids[16];
    srand(time(NULL));

    // Record start time for performance measurement
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Create a child process for each group
    for (int i = 0; i < 16; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            // In child: process group and exit
            execute_process(groups[i]);
        }
        // In parent: store child PID to wait later
        pids[i] = pid;
    }

    // Wait for all child processes to finish
    for (int i = 0; i < 16; i++)
    {
        int status;
        waitpid(pids[i], &status, 0);
    }

    // Record end time and display total execution time for process-based version
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    display_time("TOTAL PROCESSES", start_time, end_time);

    return 0;
}