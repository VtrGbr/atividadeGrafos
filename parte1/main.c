#include "bellmandFord.h"

int main(){
    int numVertices, numArestas;
    int inicio, final, pesoTotal = 0, tamanhoCaminho = 0;
    int vertice1, vertice2, peso;
    char nomeCidadeA[50], nomeCidadeB[50];   
    
    printf("Quantidade de cidades (vertices): ");
    scanf("%d", &numVertices);

    // Cria o grafo com o tamanho exato
    Grafo* grafo = criarGrafo(numVertices);
    

    lerCidade(citys, numVertices);

    //Perguntar quantas estradas existem separadamente
    scanf("%d", &numArestas);

    for( int i = 0; i < numArestas; i++){
        printf("\n--- Conexão %d ---\n", i+1);
        printf("Cidade de Origem: ");
        scanf(" %[^\n]", nomeCidadeA);
        
        printf("Cidade de Destino: ");
        scanf(" %[^\n]", nomeCidadeB);
        
        printf("Distância (Peso em Km): ");
        scanf("%d", &peso);

        vertice1 = verticeCidade(citys, nomeCidadeA, numVertices);
        vertice2 = verticeCidade(citys, nomeCidadeB, numVertices);

        if( vertice1 == -1 || vertice2 == -1){
            printf("Erro: Uma das cidades não foi encontrada. Tente novamente.\n");
            i--; // Decrementa para repetir a iteração
        } else {
            adicionarAresta(grafo, vertice1, vertice2, peso, 0);
        }
    }

    int *caminho;

    // CORREÇÃO 2: Ler nomes em vez de índices numéricos
    printf("\n--- Calcular Rota ---\n");
    printf("Digite o nome da cidade de INICIO: ");
    scanf(" %[^\n]", nomeCidadeA);
    
    printf("Digite o nome da cidade de DESTINO: ");
    scanf(" %[^\n]", nomeCidadeB);

    inicio = verticeCidade(citys, nomeCidadeA, numVertices);
    final = verticeCidade(citys, nomeCidadeB, numVertices);

    if (inicio == -1 || final == -1) {
        printf("Erro: Cidades de início ou fim inválidas.\n");
    } else {
        caminho = menorCaminho(grafo, inicio, final, &pesoTotal, &tamanhoCaminho);

        if (caminho != NULL) {
            printf("\n=== Rota Otimizada ===\n");
            
            for (int i = 0; i < tamanhoCaminho; i++) {
                int idVertice = caminho[i];
                
                printf("%s (Pop: %d)", citys[idVertice].nome, citys[idVertice].populacao);
                
                if (i < tamanhoCaminho - 1) printf(" -> ");
            }
            printf("\n\nDistância total: %d km\n", pesoTotal);
            free(caminho);
        } else {
            printf("\nNão existe caminho possível entre %s e %s.\n", nomeCidadeA, nomeCidadeB);
        }
    }

    liberarGrafo(grafo);
    return 0;
}