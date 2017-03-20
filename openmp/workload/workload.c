#include <omp.h>
#include <stdio.h>

int main() {
    int num_threads=4;
    int num_for_rounds=10;
    int step = num_for_rounds / num_threads + 1;
    int i;
    #pragma omp parallel for
    for(i=0; i<num_threads; i++) {
        int tid = omp_get_thread_num();
        if(tid == num_threads - 1) {
            int j;
            for(j=tid*step; j<num_for_rounds; j++) {
                printf("tid = %d, idx = %d\n", tid, j);
            }
        } else {
            int j;
            for(j=tid*step; j<(tid+1)*step; j++) {
                printf("tid = %d, idx = %d\n", tid, j);
            }
        }
    }

    return 0;
}
