#include <stdio.h>
#include <omp.h>

int main() {
    omp_set_num_threads(2);
    int a=0;
    int i;
    omp_lock_t lock;
    omp_init_lock(&lock);
    #pragma omp parallel for
    for(i=0; i<20000000; i++) {
        omp_set_lock(&lock);
        a++;
        omp_unset_lock(&lock);
    }
    printf("a = %d\n", a);
    return 0;
}
