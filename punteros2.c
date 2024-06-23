#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void primos(int limite) {
    bool num_prim(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    printf("Numeros primos hasta %d:\n", limite);
    for (int i = 2; i <= limite; i++) {
        if (num_prim(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

typedef void (*primos_puntero)(int);



int main() {
    // Reservar 1KB de memoria
    size_t mem = 1024;
    void *memoria = malloc(mem);
    if (memoria == NULL) {
        fprintf(stderr, "Error al reservar memoria\n");
        return 1;
    }

    // Obtener el puntero a la función primos
    primos_puntero pun_prim = &primos;

    // Copiar la función primos al espacio de memoria reservado
    memcpy(memoria, &pun_prim, sizeof(pun_prim));

    // Obtener un puntero a la función copiada
    primos_puntero ptr_prim;
    memcpy(&ptr_prim, memoria, sizeof(ptr_prim));


    int limite =0; // Ejemplo de límite para imprimir los números primos
    printf("VALOR DEL LIMITE:\n");
    scanf("%d",&limite);

    // Llamar la función primos desde el espacio de memoria reservado
    ptr_prim(limite);



    // Liberar la memoria reservada
    free(memoria);

    return 0;
}
