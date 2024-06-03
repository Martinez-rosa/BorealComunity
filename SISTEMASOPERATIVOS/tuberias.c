#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>

int main (void){
    int tuberia[2];
    pid_t hijo;
    if (pipe(tuberia) <0){
        perror("Error al crear la tuberia");
        return(-1);
    }
    if ((hijo = fork()) < 0){
        perror("Error al crear el proceso hijo");
        return(-1);
    }
    else if (hijo>0){ //Padre
        close(tuberia[0]);
        char mensaje[] = "Hola hijo";
        char mensaje2[] = "Que tal hijo?";
        write(tuberia[1], mensaje, sizeof(mensaje));
        wait(NULL);
    }
    else{ //Hijo
        close(tuberia[1]);
        char buffer[100];
        read(tuberia[0], buffer, sizeof(buffer));
        printf("Mensaje recibido: %s\n", buffer);
        exit (0);
    }

    puts("El hijo ha muerto predicando la palabra del padre.... larga vida al hijo!");
    return 0;

}