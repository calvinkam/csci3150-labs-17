#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char * argv[]) {
    int fd;
    printf("A arrive toilet.\n");
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
    return 0;
}
