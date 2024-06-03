#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(void) {

	pid_t hijo;
	
	printf("hola mundo, soy el proceso padre, PID %d\n", getpid());
	hijo=fork();
	if(hijo>0){
		printf("soy el proceso padre, PID %d. He creado un hijo con PID %d\n", getpid(),(int)hijo);
		wait(NULL);// Espera a un unico proceso, si le paso un PID espera a ese proceso
	}else if(hijo==0){
		printf("soy el proceso hijo, PID %d. Mi padre es el proceso con PID %d\n", getpid(),getppid());
	}else{
	perror("Se ha producido un error al usar el fork\n");
	}
	puts ("No tengo niidea de quien soy, esta linea la sacamos todos los procesos");
	
	return 0;
}
