#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() {

	int cpu,node;
	syscall(SYS_getcpu,&cpu, &node, NULL);
	printf("Este programa se ejecuta en el core %u de la CPU y en modo NUMA %u \n",cpu,node);
	
	return 0;
}
