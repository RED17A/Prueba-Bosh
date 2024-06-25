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

int main(){
void (*funcion)(int);
funcion=&primos;
int valor=0;
printf("valor del limite:\n");
scanf("%d",&valor);
(*funcion)(valor);
return 0;
}
