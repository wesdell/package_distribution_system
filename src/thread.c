#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "transactions.h"
#include "utils.h"

// Mutex to protect shared resources among threads
pthread_mutex_t lock;

// Thread function to process transactions for a given group
void* process_group(void* arg) {
  char* group = (char*)arg;

  // Simulate transaction processing for this group
  execute_transactions(group);

  // Mutex region for shared resource protection (optional in this context)
  pthread_mutex_lock(&lock);
  // In a real application, shared state updates would happen here
  pthread_mutex_unlock(&lock);

  pthread_exit(NULL);
}

int main() {
  // Define 16 groups labeled A to P.
  char* groups[] = {
      "A", "B", "C", "D", "E", "F", "G", "H",
      "I", "J", "K", "L", "M", "N", "O", "P"};
  pthread_t threads[16];
  struct timespec start_time, end_time;

  srand(time(NULL));

  // Initialize the mutex for synchronizing shared resource access
  pthread_mutex_init(&lock, NULL);

  // Record start time for performance measurement
  clock_gettime(CLOCK_MONOTONIC, &start_time);

  // Create one thread per group to process transactions concurrently
  for (int i = 0; i < 16; i++) {
    pthread_create(&threads[i], NULL, process_group, groups[i]);
  }

  // Wait for all threads to complete before measuring end time
  for (int i = 0; i < 16; i++) {
    pthread_join(threads[i], NULL);
  }

  // Record end time and display total execution time for thread-based version
  clock_gettime(CLOCK_MONOTONIC, &end_time);
  display_time("TOTAL THREADS", start_time, end_time);

  // Clean up mutex resources
  pthread_mutex_destroy(&lock);

  return 0;
}