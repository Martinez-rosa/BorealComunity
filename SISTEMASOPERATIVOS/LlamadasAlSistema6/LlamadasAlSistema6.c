#include <stdio.h>
#include <unistd.h>

int main(void) {

	int resultado;
	
	for (int i=0; i<10;i++){
		if((resultado = fork())==0){
			break;
		}
	}
	printf("hola mundo, mi PID es %d, soy un proceso %s\n", getpid(), resultado==0 ? "hijo" : "padre");
	return 0;
}
