#include <stdio.h>

void swap(int *a, int *b);
int partition(int array[], int low, int high);
void quicksort(int array[], int low, int high);
int buscaBinariaTeto(int inicio, int fim, int vetor[], int chave);
void elementosFaltantes(int n, int vetor[], int menor, int maior);

int main() {
    int vetor[] = {10, 12, 11, 15, 16};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int menor = 10;
    int maior = 15;

    elementosFaltantes(n, vetor, menor, maior);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high]; // escolhe o último elemento como pivô
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quicksort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

int buscaBinariaTeto(int inicio, int fim, int vetor[], int chave) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == chave) {
            return meio;
        } else if (vetor[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return inicio; // retorna o índice onde o elemento deveria ser inserido
}

void elementosFaltantes(int n, int vetor[], int menor, int maior) {
    quicksort(vetor, 0, n - 1); // ordena o vetor inteiro

    int indice = buscaBinariaTeto(0, n - 1, vetor, menor); // encontra o índice do menor elemento maior ou igual a 'menor'

    for (int i = menor; i <= maior; i++) {
        if (indice >= n || vetor[indice] > i) { // elemento não encontrado no vetor
            printf("%d ", i);
        } else {
            // avança para o próximo elemento no vetor
            indice++;
        }
    }
}