#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>

int main (void){
    int tuberia[2];
    pid_t hijo;
    char mensajes[2][20]= {"Hola hijo", "Que tal hijo?"};
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
        write(tuberia[1], mensajes[0], sizeof(mensajes[0]));
        write(tuberia[1], mensajes[1], sizeof(mensajes[1]));
        close(tuberia[1]);
        wait(NULL);
    }
    else if (hijo == 0){ //Hijo
        char buffer[20];
        close(tuberia[1]);
        read(tuberia[0], buffer, sizeof(buffer));
        printf("Mensaje 1 recibido: %s\n", buffer);

        read(tuberia[0], buffer, sizeof(buffer));
        printf("Mensaje 2 recibido: %s\n", buffer);
        close(tuberia[0]);
        exit (0);
    }

    puts("El hijo ha muerto predicando la palabra del padre.... larga vida al hijo!");
    return 0;

}