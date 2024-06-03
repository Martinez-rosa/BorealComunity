#include <stdio.h>
#include <string.h>

char repeatedChar(char *str) {
    int length = strlen(str);

    for (int i = 0; i < length - 1; i++) {
        char currentChar = str[i];
        
        for (int j = i + 1; j < length; j++) {
            if (currentChar == str[j]) {
                return currentChar;
            }
        }
    }

    return '\0'; 
}
	

int main() {
    char str[255];

    printf("Ingresa una cadena: ");
    scanf("%s", str);
    
    char repeated = repeatedChar(str);
    if (repeated != '\0') {
        printf("El primer carácter repetido es: %c\n", repeated);
    } else {
        printf("No se encontraron caracteres repetidos.\n");
    }
    return 0;
}
