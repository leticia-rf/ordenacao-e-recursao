#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct {
    char nome[101];
    int peso;
    int idade;
    float altura;
} Renas;

int cmp (Renas a, Renas b);
void swap (Renas v[], int a, int b);
void quicksort (Renas vetor[], int imin, int imax, int (*cmp)(Renas, Renas));
int partition (Renas vetor[], int imin, int imax, int (*cmp)(Renas, Renas));

int main() {

    int n_total, n_renas;
    Renas rena[MAX];

    //leitura dos dados
    scanf("%d %d", &n_total,  &n_renas);

    for (int i = 0; i < n_total; i++) {
        scanf("%s %d %d %f", rena[i].nome, &rena[i].peso, &rena[i].idade, &rena[i].altura);
    }

    //ordenação
    quicksort(rena, 0, n_total-1, cmp);

    printf("CENARIO\n");
    for (int i = 0; i < n_renas; i++) {
        printf("%d - %s\n", i+1, rena[i].nome);
    }

    return 0;
}

// ordenação por: peso (decrescente) - idade (crescente) - altura (crescente) - nome
int cmp (Renas a, Renas b) {
    
    if (a.peso != b.peso) return b.peso - a.peso;
    if (a.idade != b.idade) return a.idade - b.idade;
    if (a.altura != b.altura) return (a.altura > b.altura) ? 1 : -1;
    return strcmp(a.nome, b.nome);
    
}

void quicksort(Renas vetor[], int imin, int imax, int (*cmp)(Renas, Renas)) {
	if (imax <= imin)	return;
	
	int i = partition(vetor, imin, imax, cmp);             

	quicksort(vetor, imin, i-1, cmp);                      
	quicksort(vetor, i+1, imax, cmp);                     
}

int partition(Renas vetor[], int imin, int imax, int (*cmp)(Renas, Renas)) {

	Renas pivo = vetor[imin];
    int i = imin, j = imax + 1;
	
	while (1) {
		while (cmp(vetor[++i], pivo) < 0) 
			if(i == imax) break;
		
		while (cmp(vetor[--j], pivo) > 0) 
			if (j == imin) break;

		if (i >= j) break;
		
		swap(vetor, i, j); 
	}
	
	swap(vetor, imin, j);
	
	return j;
}

void swap(Renas v[], int a, int b) {
    Renas temp = v[a]; 
    v[a] = v[b];   
    v[b] = temp;  
}