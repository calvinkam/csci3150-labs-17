#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NITERS 10000000

void *count (void *arg);
unsigned int cnt = 0;
int main () {
    pthread_t tid1, tid2;
    pthread_create (&tid1, NULL, count, NULL);
    pthread_create (&tid2, NULL, count, NULL);

    pthread_join (tid1, NULL);
    pthread_join (tid2, NULL);
    printf ("cnt:%d\n", cnt);
    exit (0);

}

void *count (void *arg) {
     int i = 0;
    for (; i < NITERS; i++) {
        cnt++;
    }
    return NULL;
}
