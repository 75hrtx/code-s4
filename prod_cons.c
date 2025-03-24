#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

sem_t empty, full;
pthread_mutex_t mutex;
int buffer[5], count = 0;

void* producer(void* arg) {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buffer[count++] = rand() % 10;
    printf("\nProducer %ld Produced: %d", (long)arg + 1, buffer[count - 1]);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    return NULL;
}

void* consumer(void* arg) {
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    printf("\nConsumer %ld Consumed: %d", (long)arg + 1, buffer[--count]);
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    return NULL;
}

int main() {
    int np, nc;
    printf("Enter number of producers and consumers: ");
    scanf("%d %d", &np, &nc);

    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_t p[np], c[nc];

    for (int i = 0; i < np; i++) pthread_create(&p[i], NULL, producer, (void*)(long)i);
    for (int i = 0; i < nc; i++) pthread_create(&c[i], NULL, consumer, (void*)(long)i);

    for (int i = 0; i < np; i++) pthread_join(p[i], NULL);
    for (int i = 0; i < nc; i++) pthread_join(c[i], NULL);

    return 0;
}
