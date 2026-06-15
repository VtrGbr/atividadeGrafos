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

# Parte 2 – Alocação de Canais Wi-Fi

## Descrição

Esta parte da atividade resolve o problema de coloração de grafos aplicado à alocação de canais Wi-Fi. Cada vértice representa um ponto de acesso (AP) e cada aresta indica interferência entre dois APs. Assim, vértices adjacentes não podem receber a mesma cor (canal).

O objetivo é encontrar uma coloração válida utilizando o menor número possível de cores.

## Algoritmo utilizado

Foi utilizado o algoritmo **Backtracking**.

O algoritmo testa inicialmente se é possível colorir o grafo utilizando apenas uma cor. Caso não seja possível, tenta com duas cores, depois três, e assim sucessivamente até encontrar uma solução válida. Dessa forma, garante que a coloração encontrada utiliza o menor número de cores possível.

## Compilação e execução

O programa foi desenvolvido em Python.

Para executar, utilize o comando:

```bash
python3 parte2.py <arquivo_entrada> <arquivo_saida>
```

### Exemplos

Grafo pequeno:

```bash
python3 parte2.py grafo_wifi_p.txt saida_parte2_p.txt
```

Grafo médio:

```bash
python3 parte2.py grafo_wifi_m.txt saida_parte2_m.txt
```

## Formato da entrada

O arquivo de entrada deve seguir o formato:

```
<num_vertices> <num_arestas>
<vertice_u> <vertice_v>
<vertice_u> <vertice_v>
...
```

Cada linha após a primeira representa uma aresta entre dois vértices do grafo.

## Formato da saída

O programa gera um arquivo de saída contendo:

```
ALGORITMO: Backtracking
JUSTIFICATIVA: ...
NUM_CORES: <k>
COLORACAO: <vertice>=<cor> ...
```

onde:

* `NUM_CORES` representa a quantidade mínima de cores utilizadas;
* `COLORACAO` informa a cor atribuída a cada vértice;
* as cores são representadas por números inteiros iniciando em 1.



## Observações:

1. A equipe é composta pelos integrantes :
    - José Cristovão
    - Vítor Gabriel
O aluno Vítor Gabriel conversou com o professor perguntando se o trabalho pode ser em dupla, e o professor permitiu.

2. O código da parte1 foi reaproveitado do projeto que o aluno Vítor Gabriel fez nas férias, o link do repositório é
[Estudando Grafos](https://github.com/VtrGbr/EstudandoGrafos.git)



