#include "utils.h"

#include <stdio.h>

// Computes and prints the time elapsed with a custom label
void display_time(const char* label, struct timespec start, struct timespec end) {
  double duration = (end.tv_sec - start.tv_sec) +
                    (end.tv_nsec - start.tv_nsec) / 1e9;

  printf("[%s] Duration: %.6f seconds\n", label, duration);
}