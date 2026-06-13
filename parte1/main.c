#include "bellmandFord.h"

int main(){
    int numVertices, numArestas;
    int inicio, final, pesoTotal = 0, tamanhoCaminho = 0;
    
    // 1. Lê a primeira linha (número de vértices e arestas)
    if (scanf("%d %d", &numVertices, &numArestas) != 2) {
        printf("Erro ao ler vértices e arestas.\n");
        return 1;
    }

    // 2. Lê a segunda linha (roteador de origem S e destino T)
    if (scanf("%d %d", &inicio, &final) != 2) {
        printf("Erro ao ler origem e destino.\n");
        return 1;
    }

    // Cria o grafo
    Grafo* grafo = criarGrafo(numVertices);

    // 3. Lê as arestas dinamicamente
    for(int i = 0; i < numArestas; i++){
        int u, v, custo;
        if (scanf("%d %d %d", &u, &v, &custo) == 3) {
            // A parte 1 pede um GRAFO DIRECIONADO, logo enviamos '1' no final.
            adicionarAresta(grafo, u, v, custo, 1);
        }
    }

    // 4. Executa o algoritmo de Bellman-Ford
    int *caminho = menorCaminho(grafo, inicio, final, &pesoTotal, &tamanhoCaminho);

    // 5. Saída no formato EXATO exigido pela atividade
    printf("ALGORITMO: Bellman-Ford\n");
    printf("JUSTIFICATIVA: O grafo possui enlaces com SLA que geram custos negativos. O algoritmo de Dijkstra falha com pesos negativos, por isso o Bellman-Ford eh o aplicavel e mais adequado.\n");
    
    if (caminho != NULL) {
        printf("ROTA:");
        for (int i = 0; i < tamanhoCaminho; i++) {
            printf(" %d", caminho[i]);
        }
        printf("\n");
        printf("CUSTO: %d\n", pesoTotal);
        free(caminho);
    } else {
        if (pesoTotal == INT_MIN) {
            printf("ROTA: Ciclo negativo detectado.\n");
            printf("CUSTO: Indefinido\n");
        } else {
            printf("ROTA: Caminho inexistente\n");
            printf("CUSTO: Infinito\n");
        }
    }

    liberarGrafo(grafo);
    return 0;
}