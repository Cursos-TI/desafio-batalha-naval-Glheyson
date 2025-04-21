#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int colunaInicio) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][colunaInicio + i] = 3;
    }
}

void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linhaInicio, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaInicio + i][coluna] = 3;
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    inicializarTabuleiro(tabuleiro);

    // Posições de exemplo (evitar sobreposição e sair do tabuleiro)
    int linhaHorizontal = 2;
    int colunaInicioHorizontal = 4;

    int linhaInicioVertical = 5;
    int colunaVertical = 1;

    // Verificações básicas (dentro dos limites)
    if (colunaInicioHorizontal + TAM_NAVIO <= TAM &&
        linhaInicioVertical + TAM_NAVIO <= TAM) {

        posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaInicioHorizontal);
        posicionarNavioVertical(tabuleiro, linhaInicioVertical, colunaVertical);

        printf("Tabuleiro com navios posicionados:\n");
        exibirTabuleiro(tabuleiro);
    } else {
        printf("Erro: posições dos navios estão fora do tabuleiro.\n");
    }

    return 0;
}