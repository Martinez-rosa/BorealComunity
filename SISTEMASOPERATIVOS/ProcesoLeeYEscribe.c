
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define LIMITE 1000000

static int *shared_num;
static int *global_flag;

int main() {
   pid_t lee, escribe;
   shared_num = mmap(NULL, sizeof*shared_num, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
   global_flag = mmap(NULL, sizeof*global_flag, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
   *global_flag = -1;
   lee = fork();
    if (lee > 0) {
       escribe = fork();
    }
    if(lee = 0) {
        printf("introduce un numero: ");
        scanf("%d", shared_num);
        *global_flag = 1;
        exit(1);
    }
    if(escribe = 0) {
        while(*global_flag == -1){
            usleep(5);
        }
        printf("El numero introducido es: %d\n", *shared_num);
        exit(1);
    }
    else{
        while((wait(NULL) > 0) );
        return 0;
    }

}