#include <stdio.h>
#include <string.h>

int main() {
    char str[80], rev[80];
    int n,i,x;
    printf("introduce la cadena: ");
    scanf("%s",str);
    n= strlen(str);
    x=0;
    for(i=n-1;i >=0; i--){
		rev[x]=str[i];
		x++;
		}
		
	rev[x]='\0';
	if(strcmp(str,rev)==0)
		printf("%s es un palindromo", str);
	else
		printf("%s no es un palindromo", str);
		
	return 0;
}
