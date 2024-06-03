#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() {

	int  n =7;
	if (fork()==0){
		
	n++;
	}
	printf("el valor es %d\n",n);
	printf("hola\n");
	
	
	return 0;
}
