#include <stdio.h>

#define MAX 1000

void swap (int v[], int a, int b);
void InsertionRecursivo (int vetor[], int indice);

int main() {

    int n;
    int vetor[MAX];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    InsertionRecursivo (vetor, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}

void swap (int v[], int a, int b) {
    int t=v[a]; v[a]=v[b]; v[b]=t;
}

void InsertionRecursivo (int vetor[], int indice) {

    if (indice <= 0) {
        return;
    } 
    
    InsertionRecursivo (vetor, indice - 1);

    int j = indice;
		
    while (vetor[j-1] > vetor[j]) {
        swap (vetor, j-1, j);
        j--;
    }  
}