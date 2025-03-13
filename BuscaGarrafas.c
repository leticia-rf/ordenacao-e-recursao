#include <stdio.h>

void swap(int* a, int* b);
void fixDown(int vetor[], int k, int n);
void heapsort(int vetor[], int n);

int buscaBinariaPiso(int imin, int imax, int vetor[], int chave);

int main() {

    int p, pocoes[1000000], g, garrafa;

    scanf("%d", &p);

    for (int i = 0; i < p; i++) {
        scanf("%d", &pocoes[i]);
    }

    heapsort(pocoes, p);

    scanf("%d", &g);

    for (int i = 0; i < g; i++) {
        scanf("%d", &garrafa);

        int resultado = buscaBinariaPiso(0, p - 1, pocoes, garrafa);
        
        if (resultado == -1) {
            printf("descartar\n");
        } else {
            printf("%d\n", resultado);
        }
    }

    return 0;

}

// busca o maior número menor ou igual a chave
int buscaBinariaPiso(int imin, int imax, int vetor[], int chave) {

    if (imax < imin) return -1;

    int imid = imin + ((imax - imin) / 2);

    if (vetor[imid] <= chave) {   // busca a direita
        int resultado = (buscaBinariaPiso (imid + 1, imax, vetor, chave));
        
        if (resultado == -1)     // quando imax passar imin, imid estara na posicao do elemento desejado
            return vetor[imid];
        else 
            return resultado;    // se nao, continua 
    } else { // busca a esquerda
        return buscaBinariaPiso(imin, imid - 1, vetor, chave);
    }

}

void heapsort(int vetor[], int n) {
	for (int k = n/2; k >= 0; k--)  // construcao da max heap, iniciando na metade
		fixDown(vetor, k, n);           // deixa os pais sempre maiores que os filhos

	while (n > 1) {                     
		swap(&vetor[0], &vetor[n-1]);   // coloca o primeiro (maior elemento) na ultima posicao
		n--;                            // descrementa a qntd de elementos
		fixDown(vetor, 0, n);           // deixa a heap novamente consistente
	}
}

// compara o elemento com seus filhos e desce ele trocando com o maior filho
void fixDown(int vetor[], int k, int n) {

    // enquanto houver pelo menos o filho da esquerda, ou seja, não for folha
    while (2*k + 1 < n) { 
        // calculo dos indices dos filhos da direita e esquerda
        int iFilhoEsq = 2*k + 1;
        int iFilhoDir = 2*k + 2;

        int iMaiorFilho = iFilhoEsq;    // comeca considerando que o filho da esquerda é maior

        // (se existir) atualiza o maior se o filho da direita for maior
        if (iFilhoDir < n && vetor[iFilhoDir] > vetor[iFilhoEsq]) {
            iMaiorFilho = iFilhoDir;
        }

        // se o pai (vetor[k]) for maior ou igual ao filho, ja esta na posicao certa
        if (vetor[k] >= vetor[iMaiorFilho]) break;
        
        // se não, faz a troca e atualiza k para a posicao em que o elemento que foi trocado estava
        swap(&vetor[k], &vetor[iMaiorFilho]);
        k = iMaiorFilho; 
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}