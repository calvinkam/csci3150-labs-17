#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <semaphore.h>

int main(int argc, char * argv[]) {
    int fd;
    int value = 1;
    sem_t * mutex;
    mutex = sem_open("mutex", O_CREAT, 0666, value);

    printf("A arrive toilet.\n");
    sem_wait(mutex);
    printf("A checks the toilet.\n");
    fd=open("toilet", O_CREAT|O_RDWR|O_APPEND, 0777);
    if(lseek(fd,0,SEEK_END)==0){
        printf("A goes back and grab a laptop...\n");
        sleep(2);
    write(fd,"lock ",5);
        printf("A enters the toilet.\n");
        if(lseek(fd,0,SEEK_END)>5)
            printf("Oops! We have two persons in toilet\n");
    }else{
        printf("Toilet Occupied, A leaves the toilet\n"); 
    }
    close(fd);
    sem_post(mutex);
    sem_close(mutex);
    sem_unlink("mutex");	
    return 0;
}
