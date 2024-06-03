#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>


int main(void) {

	pid_t hijo; //Declara una varable tipo identificador de proceso

	hijo=fork();

	if(hijo>0){
		printf("soy el proceso padre, PID %d. He creado un hijo con PID %d\n", getpid(),(int)hijo);
		while(wait(NULL)>0);// Espera a todos los procesos hijos, mientras haya alguien a quien esperar espera
	}else if(hijo==0){
		sleep(1);
		int num1, num2;
		printf("Ingresa un numero soy el hijo: ");
		scanf("%d", &num1);
		printf("Ingresa otro numero soy el hijo: ");
		scanf("%d", &num2);
		printf("la suma de estos dos numeros es %d\n", num1+num2);
		exit(0);// Sale del proceso hijo
	}else{
		perror("Se ha producido un error al usar el fork\n");
	}
	puts ("Soy el padre y aqui termina esto\n");
	
	return 0;
}