#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() {

	char mensaje[]= "Hola mundo";
	syscall(SYS_write,1, mensaje, sizeof(mensaje));
	
	return 0;
}
