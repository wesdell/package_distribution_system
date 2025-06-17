#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Returns the current timestamp in milliseconds
long long current_timestamp_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts); // Gets current time
    return (long long)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

// Logs an informational message to standard output
void log_info(const char *msg) {
    printf("[INFO] %s\n", msg);
}

// Logs an error message to standard error
void log_error(const char *msg) {
    fprintf(stderr, "[ERROR] %s\n", msg);
}

// Logs an error and exits the program with code 1
void die(const char *msg) {
    log_error(msg);  // Print the error
    exit(1);         // Exit the program with failure
}