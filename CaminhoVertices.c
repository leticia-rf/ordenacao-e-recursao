#include <stdio.h>

int haCaminho(int vertices, int origem, int destino, int grafo[100][100]);

int main () {

    int vertices, arestas, u, v;
    int grafo[100][100] = {0};

    scanf ("%d %d", &vertices, &arestas);

    for (int i = 0; i < arestas; i++) {
        scanf("%d %d", &u, &v);
        grafo[u][v] = 1;
    }

    int comparaveis = 1;

    // percorre verificando apenas a vertical "de cima" da matriz
    for (int i = 0; i < vertices; i++) {
        for (int j = i+1; j < vertices; j++) {
            if (!haCaminho(vertices, i, j, grafo) && !haCaminho(vertices, j, i, grafo)) {
                printf ("%d %d\n", i, j);
                comparaveis = 0;
            }
        }
    }

    if (comparaveis) printf ("Todos comparaveis.");
    printf("\n");

    return 0;
}

typedef enum {nao_visitado = 0, visitado, explorado} estado;

int haCaminho(int vertices, int origem, int destino, int grafo[100][100]) {

    int estado[100] = {nao_visitado};
    int fila[100] = {origem};             // fila de vertices a serem explorados
    int inicio = 0, fim = 1;

    // percorre cada vertice da fila
    while (inicio < fim) {
        int atual = fila[inicio++];       // atualiza o atual e incrementa inicio 
        if (atual == destino) return 1;

        // verifica os vizinhos do atual
        for (int i = 0; i < vertices; i++) {            
            if (grafo[atual][i] == 1 && estado[i] == nao_visitado) {
                estado[i] = visitado;
                fila[fim++] = i;          // acrescenta o vértice na fila de exploração e incrementa fim
            }    
        }
        estado[atual] = explorado;
    }
    return 0;
}