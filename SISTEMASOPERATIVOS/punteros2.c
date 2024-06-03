#include <stdio.h>

int add(int, int);

int main (void){
	
	int (*addPtr)(int,int);  //declaro un puntero a una funcion add
	addPtr = &add; //le paso la direccion de memoria de la funcion
	int resultado = (*addPtr)(5,7);
	printf("resultado: %d \n", resultado);
	
	return 0;
	}
int add(int a, int b){
	
	return a+b;
	}
