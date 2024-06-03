#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    int tuberia1[2], tuberia2[2];
    int num1, num2, suma;

    if (pipe(tuberia1) < 0  || pipe(tuberia2) <0) {
        perror("Error al crear la tuberia");
        exit(1);
    }

    pid_t hijo = fork();

    if (hijo < 0) {
        perror("Error al crear el proceso hijo");
        exit(1);
    }

    if (hijo > 0) { //Padre
        close(tuberia1[0]); //Cierra la lectura
        close(tuberia2[1]); //Cierra la escritura

        do {
            printf("Introduce dos numeros: ");
            scanf("%d %d", &num1, &num2);

            write(tuberia1[1], &num1, sizeof(num1));
            write(tuberia1[1], &num2, sizeof(num2));

            read(tuberia2[0], &suma, sizeof(suma)); //Lee la suma mandada por el hijo

            printf("Suma: %d\n", suma);
        } while (num1 != -1);

        kill(hijo, SIGKILL);

        close(tuberia1[1]);
        close(tuberia2[0]);
    } else {//Hijo
        close(tuberia1[1]); // Cierra la escritura 
        close(tuberia2[0]); // Cierra la lectura 

        do {
            read(tuberia1[0], &num1, sizeof(num1)); // Lee el primer numero de la tuberia1
            read(tuberia1[0], &num2, sizeof(num2)); // Lee el segundo numero de la tuberia1

            suma = num1 + num2;

            write(tuberia2[1], &suma, sizeof(suma));
        } while (num1 != -1);

        close(tuberia1[0]);
        close(tuberia2[1]);
    }

    return 0;
}
