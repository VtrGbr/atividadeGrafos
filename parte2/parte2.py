import sys

def lerGrafo(nomeArquivo):
    with open(nomeArquivo, "r", encoding="utf-8") as arq:
        linhas = [linha.strip() for linha in arq if linha.strip()]

    n, m = map(int, linhas[0].split())
    vizinhos = [[] for _ in range(n)]

    for linha in linhas[1:]:
        u, v = map(int, linha.split())
        vizinhos[u].append(v)
        vizinhos[v].append(u)

    return n, vizinhos


def podeColorir(vertice, cor, cores, vizinhos):
    for vizinho in vizinhos[vertice]:
        if cores[vizinho] == cor:
            return False
    return True


def colorir(vertice, n, cores, vizinhos, qtdCores):
    if vertice == n:
        return True

    for cor in range(1, qtdCores + 1):
        if podeColorir(vertice, cor, cores, vizinhos):
            cores[vertice] = cor

            if colorir(vertice + 1, n, cores, vizinhos, qtdCores):
                return True

            cores[vertice] = 0

    return False


def resolver(n, vizinhos):
    for qtdCores in range(1, n + 1):
        cores = [0] * n

        if colorir(0, n, cores, vizinhos, qtdCores):
            return qtdCores, cores


def salvarSaida(nomeSaida, qtdCores, cores):
    textoCores = []

    for i in range(len(cores)):
        textoCores.append(f"{i}={cores[i]}")

    with open(nomeSaida, "w", encoding="utf-8") as arq:
        arq.write("ALGORITMO: Backtracking\n")
        arq.write("JUSTIFICATIVA: O algoritmo testa as coloracoes possiveis ate encontrar uma valida com o menor numero de cores.\n")
        arq.write(f"NUM_CORES: {qtdCores}\n")
        arq.write("COLORACAO: " + " ".join(textoCores) + "\n")


def main():
    entrada = sys.argv[1]
    saida = sys.argv[2]

    n, vizinhos = lerGrafo(entrada)
    qtdCores, cores = resolver(n, vizinhos)
    salvarSaida(saida, qtdCores, cores)


if __name__ == "__main__":
    main()