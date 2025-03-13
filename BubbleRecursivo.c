#include <stdio.h>

#define MAX 1000

void swap (int v[], int a, int b) {
    int t=v[a]; v[a]=v[b]; v[b]=t;
}

void BubbleRecursivo (int vetor[], int n) {

    int trocou = 0;

    if (n <= 1) {
        return;
    }
    
    for (int j = 0; j < n - 1; j++) {

        if (vetor[j] > vetor[j+1]) {
            swap (vetor, j, j+1);
            trocou = 1;
        }

    }
    
    if (!trocou) {
        return;
    }
    
    BubbleRecursivo (vetor, n - 1);

}

int main() {

    int n;
    int vetor[MAX];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    BubbleRecursivo (vetor, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}