#include <stdio.h>
#include <omp.h>

int main() {
    omp_set_num_threads(2);
    int a=0;
    int i;
    #pragma omp parallel for
    for(i=0; i<20000000; i++) {
        #pragma omp critical
        {
            a++;
        }
    }
    printf("a = %d\n", a);
    return 0;
}
