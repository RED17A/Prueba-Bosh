#include <stdio.h>
#include <stdlib.h>

int main() {
    //FUNCION PARA RESERVAR MEMORIA CON LA FUNCION MALLOC
    char *array = (char *)malloc(1024 * sizeof(char));

    if (array == NULL) {
        printf("No se pudo asignar memoria\n");
        return 1;
    }

    printf("HOLA MUNDO");
    printf("Memoria usada=%c\n ",array);

    return 0;
}

