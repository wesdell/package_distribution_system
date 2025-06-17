#ifndef UTILS_TIME_H
#define UTILS_TIME_H

#include <time.h>

// Displays the elapsed time between two timestamps with a label
void display_time(const char* label, struct timespec start, struct timespec end);

#endif