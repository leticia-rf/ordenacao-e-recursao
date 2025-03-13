#include <stdio.h>

void DesenharTracos (int n);
void DesenharRegua (int tam_regua, int qntd_tracos);

int main() {

    int tam_regua, qntd_tracos;

    scanf("%d %d", &tam_regua, &qntd_tracos);

    DesenharRegua(tam_regua, qntd_tracos);    

    return 0;
}


// desenha as divisões com numeros
void DesenharRegua (int tam_regua, int qntd_tracos) {

    for (int i = 0; i <= tam_regua; i++) {       // de 0 até tam_regua

        for (int j = 0; j < qntd_tracos; j++) {
            printf ("-");
        }
        printf(" %d\n", i);
        
        if (i < tam_regua)                   // desenha as subdivisões, tam_regua-1 vezes
            DesenharTracos (qntd_tracos - 1);   
    }
}


// desenha o intervalo entre os traços com números
void DesenharTracos (int n) {          // n = traços-1
    if (n <= 0) return;

    DesenharTracos(n - 1);             // (1° chamada) empilha e vai printando na "volta"

    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");

    DesenharTracos(n - 1);             // [2° chamada]
}

/*  exemplo: 1 5

----- 0    
-         (1) -print-> [1] 
--        (2) -print-> [2] 
-                       -> (1) -print-> [1]                       // último da pilha: até 2-1
---       (3) -print-> [3]
-                       -> (1) -print-> [1]
--                         (2) -print-> [2]                       // último da pilha: até 3-1
-                                        -> (1) -print-> [1]
----      (4) -print-> [4]
-                       -> (1) -print-> [1]
--                         (2) -print-> [2]
-                                        -> (1) -print-> [1]
---                        (3) -print-> [3]                       // último da pilha: até 4-1
-                                        -> (1) -print-> [1]
--                                          (2) -print-> [2] 
-                                                         -> (1) -print-> [1]
----- 1

*/