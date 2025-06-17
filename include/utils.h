#ifndef UTILS_H
#define UTILS_H

// Returns the current system time in milliseconds
long long current_timestamp_ms(void);

// Prints an informational message to standard output
void log_info(const char *msg);

// Prints an error message to standard error
void log_error(const char *msg);

// Prints an error and exits the program with status 1
void die(const char *msg);

#endif