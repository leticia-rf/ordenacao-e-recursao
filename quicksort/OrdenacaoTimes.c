#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 10000
#define MAX_TIMES 1000

typedef struct {
    char nome[101];
    int habilidade;
} Alunos;

void swap (Alunos v[], int a, int b);
void quicksort (Alunos vetor[], int imin, int imax, int (*cmp)(Alunos, Alunos));
int partition (Alunos vetor[], int imin, int imax, int (*cmp)(Alunos, Alunos));
int cmpHabilidade (Alunos a, Alunos b);
int cmpNome (Alunos a, Alunos b);

int main() {

    int n_jogadores, n_times;
    Alunos jogadores[MAX_ALUNOS];

    //leitura dos dados
    scanf("%d %d", &n_jogadores,  &n_times);

    for (int i = 0; i < n_jogadores; i++) {
        scanf("%s %d", jogadores[i].nome, &jogadores[i].habilidade);
    }

    //ordenação por habilidades
    quicksort(jogadores, 0, n_jogadores-1, cmpHabilidade);

    //separação dos times em uma matriz (cada time em uma linha)
    Alunos times[n_times][n_jogadores/n_times + 1];
    int tamanho_time[MAX_TIMES] = {0};

    for (int i = 0; i < n_jogadores; i++) {

        int indice_time = i % n_times;

        times[indice_time][i / n_times] = jogadores[i];
        tamanho_time[indice_time]++;
    }

    //ordenação por nome, para cada time
    for (int i = 0; i < n_times; i++) {
        
        quicksort(times[i], 0, tamanho_time[i]-1, cmpNome);

        printf("Time %d\n", i+1);
        for (int j = 0; j < tamanho_time[i]; j++) {
            printf("%s\n", times[i][j].nome);
        }
        printf("\n");

    }

    return 0;
}


//ordem decrescente
int cmpHabilidade (Alunos a, Alunos b) {
    return a.habilidade - b.habilidade;     // quando a for menor que b, dará (-)
}

//ordem crescente
int cmpNome (Alunos a, Alunos b) {
    return strcmp(b.nome, a.nome);          // quando b for maior que a, dará (+)
}

void quicksort(Alunos vetor[], int imin, int imax, int (*cmp)(Alunos, Alunos)) {
	if (imax <= imin)	return;
	
	int i = partition(vetor, imin, imax, cmp);             //i: posição do pivô
	
	quicksort(vetor, imin, i-1, cmp);                      //elementos menores que o pivô
	quicksort(vetor, i+1, imax, cmp);                      //elementos maiores que o pivô
}

int partition(Alunos vetor[], int imin, int imax, int (*cmp)(Alunos, Alunos)) {

	Alunos pivo = vetor[imin];
    int i = imin, j = imax + 1;
	
	while (1) {
		while (cmp(vetor[++i], pivo) > 0) //sairá do loop quando return de cmp for (-)
			if(i == imax) break;
		
		while (cmp(vetor[--j], pivo) < 0) //sairá do loop quando return de cmp for (+)
			if (j == imin) break;

		if (i >= j) break;
		
		swap(vetor, i, j); 
	}
	
	swap(vetor, imin, j);
	
	return j;
}

void swap(Alunos v[], int a, int b) {
    Alunos temp = v[a]; 
    v[a] = v[b];   
    v[b] = temp;  
}