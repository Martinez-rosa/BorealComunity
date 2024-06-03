#include <stdio.h>
#include <unistd.h>
int main() {

	write(1, "Hola Mundo\n", sizeof("Hola Mundo\n")); //Llamada al sistema quasidirecta al SO 
	return 0;
}
