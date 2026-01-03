#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define BUFFER_SIZE 3
#define NUM_ITEMS 3  // Number of items each producer produces

int buffer[BUFFER_SIZE];
int in = 0;    // Index for producer
int out = 0;   // Index for consumer

sem_t empty;   // Counts empty slots
sem_t full;    // Counts full slots
pthread_mutex_t mutex;

void *producer(void *pno) {
    int id = *((int *)pno);
    for(int i = 0; i < NUM_ITEMS; i++) {
        int item = rand() % 50;  // Produce a random item

        sem_wait(&empty);             // Wait for empty slot
        pthread_mutex_lock(&mutex);   // Lock buffer

        buffer[in] = item;
        printf("Producer %d: Insert item %d at %d\n", id, buffer[in], in);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex); // Unlock buffer
        sem_post(&full);              // Signal full slot

        sleep(1); // Optional: simulate production time
    }
    return NULL;
}

void *consumer(void *cno) {
    int id = *((int *)cno);
    for(int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&full);              // Wait for full slot
        pthread_mutex_lock(&mutex);   // Lock buffer

        int item = buffer[out];
        printf("Consumer %d: Remove item %d from %d\n", id, item, out);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex); // Unlock buffer
        sem_post(&empty);             // Signal empty slot

        sleep(1); // Optional: simulate consumption time
    }
    return NULL;
}

int main() {
    pthread_t p_threads[3], c_threads[3];
    int p_ids[3] = {1,2,3};
    int c_ids[3] = {1,2,3};

    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Create producer threads
    for(int i = 0; i < 3; i++)
        pthread_create(&p_threads[i], NULL, producer, &p_ids[i]);

    // Create consumer threads
    for(int i = 0; i < 3; i++)
        pthread_create(&c_threads[i], NULL, consumer, &c_ids[i]);

    // Join producer threads
    for(int i = 0; i < 3; i++)
        pthread_join(p_threads[i], NULL);

    // Join consumer threads
    for(int i = 0; i < 3; i++)
        pthread_join(c_threads[i], NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
