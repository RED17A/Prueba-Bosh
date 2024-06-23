#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//FUNCION EN LA QUE SE OBTIENEN LOS NUMEROS PRIMOS DESDE EL 0 HASTA EL VALOR DEL LIMITE
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
//DEFINICION DE UN PUNTERO A FUNCION
typedef void (*primos_puntero)(int);



int main() {
    // RESERVA DE LA MEMORIA
    size_t mem = 1024;
    void *memoria = malloc(mem);
    if (memoria == NULL) {
        fprintf(stderr, "Error al reservar memoria\n");
        return 1;
    }

    //PUNTERO A LA FUNCION "PRIMOS"
    primos_puntero pun_prim = &primos;

    // Se utiliza "memcpy" para copiar la funcion "primos" al espacio de memoria reservado
    memcpy(memoria, &pun_prim, sizeof(pun_prim));

    //Puntero para recuperar la funcion "primos" copiada en la memoria
    primos_puntero ptr_prim;
    memcpy(&ptr_prim, memoria, sizeof(ptr_prim));

    //INTERACCION CON EL USUARIO
    int limite =0;
    printf("VALOR DEL LIMITE:\n");
    scanf("%d",&limite);

    // EJECUCION DESDE LA MEMORIA RAM
    ptr_prim(limite);



    // Liberar la memoria
    free(memoria);

    return 0;
}
