# Prática 1: Roteamento em Rede de Backbone (Parte 1)

Esta seção do repositório contém a solução para o problema de roteamento na rede de backbone. O objetivo é encontrar o caminho de menor custo entre um roteador de origem (S) e um de destino (T) em um grafo direcionado onde as arestas possuem pesos que representam a latência. Alguns enlaces possuem Acordos de Nível de Serviço (SLA), resultando em **pesos negativos**.

## Estrutura de Arquivos

* `main.c`: Arquivo principal contendo a leitura dos dados e a formatação exata da saída.
* `grafo.c` e `grafo.h`: Implementação da estrutura do grafo direcionado utilizando listas de adjacência.
* `bellmanFord.c` e `bellmandFord.h`: Implementação do algoritmo de Bellman-Ford, incluindo a lógica para detecção de ciclos negativos.

---

## Como Compilar

Para compilar o código fonte, certifique-se de estar dentro do diretório `parte1` no seu terminal e utilize o compilador `gcc`:

```bash
gcc main.c grafo.c bellmanFord.c -o roteamento_parte1
```

Isso irá gerar um executável chamado roteamento_parte1 (ou roteamento_parte1.exe no Windows).

## Como Executar e Testar
O programa foi projetado para ler as entradas diretamente do terminal (entrada padrão). Para realizar os testes com os arquivos de texto fornecidos (ex: grafo_rede_p.txt e grafo_rede_m.txt), utilize o operador de redirecionamento < para inserir o arquivo e > para gerar o arquivo de saída.

- No Linux ou Mac:

```bash
./roteamento_parte1 < grafo_rede_m.txt > saida_parte1_m.txt
```
- No Windows (CMD ou PowerShell):
```bash
roteamento_parte1.exe < grafo_rede_m.txt > saida_parte1_m.txt
```

O arquivo gerado (saida_parte1_m.txt) conterá as informações no formato exato exigido na especificação:

ALGORITMO: Bellman-Ford 

JUSTIFICATIVA: O grafo possui enlaces com SLA que geram custos negativos. O algoritmo de Dijkstra falha com pesos negativos, por isso o Bellman-Ford eh o aplicavel e mais adequado.

ROTA: sequência de vértices

CUSTO: valor

Justificativa do Algoritmo: Bellman-Ford vs. Dijkstra


### Para resolver este problema, o algoritmo escolhido foi o Bellman-Ford, e não o Dijkstra, pelas seguintes razões técnicas:

1. Tratamento de Pesos Negativos: O algoritmo de Dijkstra utiliza uma abordagem gulosa, assumindo que uma vez que a menor distância para um vértice é encontrada, ela nunca poderá ser reduzida. Se o grafo possuir arestas com pesos negativos (o que ocorre neste cenário devido aos ganhos de SLA), o Dijkstra pode falhar em encontrar a rota verdadeiramente ótima, pois não revisita vértices já "fechados".

2. Relaxamento Exaustivo: O Bellman-Ford contorna esse problema relaxando todas as arestas V−1 vezes (onde V é o número de vértices). Isso garante que o custo mínimo seja propagado corretamente por toda a rede, independentemente de enlaces negativos.

3. Detecção de Anomalias (Ciclos Negativos): Em redes, uma configuração errônea pode criar um loop onde o custo continua diminuindo infinitamente. O Bellman-Ford possui uma etapa final nativa que percorre as arestas mais uma vez para detectar a presença de ciclos negativos. Caso exista um, nosso programa o identifica e aborta o roteamento de forma segura, informando "Ciclo negativo detectado".