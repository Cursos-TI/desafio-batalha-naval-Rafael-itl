#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define NAVIO 3
#define HABILIDADE 5

// Funções para criar as matrizes das habilidades
void criar_matriz_cone(int matriz[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = 0;
            if (i == 0 && j == 2) matriz[i][j] = 1;
            else if (i == 1 && j >= 1 && j <= 3) matriz[i][j] = 1;
            else if (i == 2) matriz[i][j] = 1;
        }
}

void criar_matriz_cruz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = (i == 2 || j == 2) ? 1 : 0;
}

void criar_matriz_octaedro(int matriz[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = (abs(i - 2) + abs(j - 2) <= 2) ? 1 : 0;
}

// Função para aplicar habilidade ao tabuleiro
void aplicar_habilidade(int tabuleiro[TAM][TAM], int habilidade[5][5], int origem_linha, int origem_coluna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = origem_linha + i - 2;
            int coluna = origem_coluna + j - 2;

            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Função para imprimir o tabuleiro com símbolos
void imprimir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   ");
    for (int i = 0; i < TAM; i++) printf("%2d", i);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) printf("~ ");
            else if (tabuleiro[i][j] == NAVIO) printf("N ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posicionar navios horizontais e verticais
    int linha_h = 2, coluna_h = 1;
    for (int i = 0; i < 3; i++) tabuleiro[linha_h][coluna_h + i] = NAVIO;

    int linha_v = 5, coluna_v = 6;
    for (int i = 0; i < 3; i++) tabuleiro[linha_v + i][coluna_v] = NAVIO;

    // Posicionar navios diagonais
    int linha_d1 = 7, coluna_d1 = 0;
    for (int i = 0; i < 3; i++) tabuleiro[linha_d1 + i][coluna_d1 + i] = NAVIO;

    int linha_d2 = 3, coluna_d2 = 7;
    for (int i = 0; i < 3; i++) tabuleiro[linha_d2 + i][coluna_d2 - i] = NAVIO;

    // Criar e aplicar habilidades
    int cone[5][5], cruz[5][5], octaedro[5][5];

    criar_matriz_cone(cone);
    criar_matriz_cruz(cruz);
    criar_matriz_octaedro(octaedro);

    aplicar_habilidade(tabuleiro, cone, 1, 2);
    aplicar_habilidade(tabuleiro, cruz, 5, 5);
    aplicar_habilidade(tabuleiro, octaedro, 8, 2);

    // Exibir tabuleiro final
    imprimir_tabuleiro(tabuleiro);

    return 0;
}