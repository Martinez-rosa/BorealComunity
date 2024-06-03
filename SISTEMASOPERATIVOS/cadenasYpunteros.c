#include <stdio.h>

void reverseString(char *str) {
    if (str == NULL)
        return;

    char *start = str;
    char *end = str;


    while (*end != '\0') {
        end++;
    }
    end--; 

    char temp;


    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(void) {
    char str[255];

    printf("Ingresa una cadena: ");
    scanf("%s", str);

    reverseString(str);

    printf("La cadena invertida es: %s\n", str);

    return 0;
}
