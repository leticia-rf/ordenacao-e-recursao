#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Soma (int vetor[], int n);
int Maior (int vetor[], int n, int indice, int maior);
int Menor (int vetor[], int n, int indice, int menor);
int Crescente (int vetor[], int n);
int Decrescente (int vetor[], int n);
int Espelhada (int vetor[], int n, int indice);

int main() {

    int n, sequencia[500];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &sequencia[i]);
    }

    printf("Soma: %d\n", Soma (sequencia, n - 1));
    printf("Maior: %d\n", Maior (sequencia, n, 0, sequencia[0]));
    printf("Menor: %d\n", Menor (sequencia, n, 0, sequencia[0]));
    printf("Crescente: %s\n", Crescente (sequencia, n) ? "sim" : "nao");
    printf("Decrescente: %s\n", Decrescente (sequencia, n) ? "sim" : "nao");
    printf("Espelhada: %s\n", Espelhada (sequencia, n, 0) ? "sim" : "nao");

    return 0;
}

// funções recursivas

int Soma (int vetor[], int n) {
    if (n == 0) { // caso base: primeiro elemento
        return vetor[0]; 
    }
    return vetor[n] + Soma (vetor, n-1); // vetor[n] + vetor[n-1] ...
}

int Maior (int vetor[], int n, int indice, int maior) {
    if (indice == n) { // condição de parada: último elemento
        return maior;
    }

    if (vetor[indice] > maior) {
        maior = vetor[indice];    // atualiza o maior
    } 
    return Maior (vetor, n , indice + 1, maior);
}

int Menor (int vetor[], int n, int indice, int menor) {
    if (indice == n) { // condição de parada: último elemento
        return menor;
    }

    if (vetor[indice] < menor) {
        menor = vetor[indice];    // atualiza o maior
    } 
    return Menor (vetor, n , indice + 1, menor);
}


int Crescente (int vetor[], int n) {

    if (n == 1) {   // caso base: quando só sobrar o primeiro elemento
        return 1;   // então será crescente
    }

    if (vetor[n-1] <= vetor [n-2]) {  
        return 0;                   // será falso (e termina a pilha de execução daquela chamada)
    } 

    return Crescente (vetor, n - 1);
}

int Decrescente (int vetor[], int n) {
    
    if (n == 1) {   // caso base: quando só sobrar o primeiro elemento
        return 1;   // então será decrescente
    }

    if (vetor[n-1] >= vetor [n-2]) {  
        return 0;                 
    } 
    
    return Decrescente (vetor, n - 1);
}

int Espelhada (int vetor[], int n, int indice) {
    if (indice == n/2) {  // atingiu o meio (se for ímpar) ou "passou" do meio (se for par)
        return 1;        // será verdadeira
    }

    if (vetor[indice] != vetor[(n-1) - indice]) {
        return 0; // se os elementos das "pontas" forem diferentes, retorna falso
    }

    return Espelhada (vetor, n, indice + 1);
}