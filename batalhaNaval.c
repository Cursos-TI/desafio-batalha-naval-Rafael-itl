#include <stdio.h>

// Tamanho fixo do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Verifica se a posição está livre
int posicao_livre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna){
    return tabuleiro[linha][coluna] == 0;
}
    int posicionar_horizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna){
        if(coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

        for (int i = 0; i < TAMANHO_NAVIO; i++)
        if(!posicao_livre(tabuleiro, linha, coluna + i)) return 0;

        for(int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[linha][coluna + i] = 3;
    return 1;
    }

    int posicionar_vertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna){
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
        if (!posicao_livre(tabuleiro, linha + i, coluna)) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[linha + i][coluna] = 3;

    return 1;
}

int posicionar_diagonal_principal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        if (!posicao_livre(tabuleiro, linha + i, coluna + i)) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[linha + i][coluna + i] = 3;

    return 1;
}

int posicionar_diagonal_secundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - (TAMANHO_NAVIO - 1) < 0) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        if (!posicao_livre(tabuleiro, linha + i, coluna - i)) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[linha + i][coluna - i] = 3;

    return 1;

}
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posiciona 4 navios
    if (!posicionar_horizontal(tabuleiro, 1, 1)) {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }

    if (!posicionar_vertical(tabuleiro, 4, 3)) {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }

    if (!posicionar_diagonal_principal(tabuleiro, 0, 7)) {
        printf("Erro ao posicionar navio diagonal principal!\n");
        return 1;
    }

    if (!posicionar_diagonal_secundaria(tabuleiro, 6, 9)) {
        printf("Erro ao posicionar navio diagonal secundária!\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}