// Letícia Ramos Fernandes - Atividade 8 - Porcas e Parafusos

#include <stdio.h>

void swap(int vetor[], int i, int j);
int partition(int vetor[], int imin, int imax, int pivo);
void encontrarEncaixes(int porcas[], int parafusos[], int imin, int imax);

int main() {

    int n;
    scanf ("%d", &n);
    int porcas[n], parafusos[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &porcas[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &parafusos[i]);

    // variação do quick sort para ordenar os vetores "ao mesmo tempo" sem comparar elementos do mesmo tipo
    encontrarEncaixes(porcas, parafusos, 0, n - 1);

    for(int i = 0; i < n; i++)
        printf("%d - %d\n", porcas[i], parafusos[i]);
    return 0;
}


void encontrarEncaixes(int porcas[], int parafusos[], int imin, int imax) {
    if (imax <= imin) return;

	int iPivo = partition(parafusos, imin, imax, porcas[imin]);  
    // 2° partition: pivo é o elemento do indice retornado no partition anterior
    partition(porcas, imin, imax, parafusos[iPivo]); 
    
	encontrarEncaixes(porcas, parafusos, imin, iPivo-1);
	encontrarEncaixes(porcas, parafusos, iPivo+1, imax);  
}

int partition(int vetor[], int imin, int imax, int pivo) {
	int iPivo = imin, i = imin, j = imax;
	
	while (1) {
		// percorre da esquerda pra direita procurando um maior que o pivô
		while (vetor[i] < pivo) {
            i++; 
			if(i == imax) break;
        }
        if (vetor[i] == pivo) iPivo = i; // salva o indice do pivô (pode não ser exatamente o imin)

		// percorre da direita pra esquerda procurando um menor que o pivô
		while (pivo < vetor[j]) {
            j--;
			if (j == imin) break;    
        }
        if (vetor[j] == pivo) iPivo = j;

        if (i >= j) break;
		
		swap(vetor, i, j);  // faz a troca do elemento i (maior que o pivô) com o elemento j (menor)
	}
	
    swap(vetor, iPivo, j);  // troca o pivô com o último elemento dos menores que ele
    
    return j;
	
}

void swap(int vetor[], int i, int j) {
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}