#include <stdio.h>

void suma(int a, int b){
	printf("la suma es %d \n", a+b);
	}
	
void resta(int a, int b){
	printf("la resta es %d \n", a-b);
	}	

void multiplicacion(int a, int b){
	printf("la multiplicacion es %d \n", a*b);
	}
	
void division(int a, int b){
	printf("la division es %d \n", a/b);
	}
	

int main (void){
	
	void (*puntero_funcion_array[])(int,int) = {suma, resta, multiplicacion, division};
	unsigned int opcion, a=3, b=10;
	printf("introduce opcion:0 para sumar, 1 para restar , 2 para multiplicar y 3 para dividir \n");
	scanf("%d",&opcion);
	if (opcion>3) perror("mete bien el numero");
	(*puntero_funcion_array[opcion])(a,b);
	return 0;
	}
