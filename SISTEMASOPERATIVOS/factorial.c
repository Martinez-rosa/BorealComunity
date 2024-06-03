#include <stdio.h>

int factorial(int);

int main (void)
{
	
	int  n1;

	printf("Escribe un numero: ");
	scanf("%d", &n1);
	printf("\n");
	
	printf("El factorial de este numero es %d \n", factorial(n1));
	
	return 0;
}
	
int factorial(int n1)
{
	if (n1 > 1){
		n1 = n1 * factorial(n1-1);
	}else{
		return 1;
	}	 
	
	}
	

