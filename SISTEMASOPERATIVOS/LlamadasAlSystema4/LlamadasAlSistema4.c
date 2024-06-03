#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() {

	int  n;
	fork();
	fork();
	puts("introduce un numero");
	read (0, &n, sizeof(n));
	write(1,&n,sizeof(n));
	
	return 0;
}
