#include <stdio.h>

// Tamanho fixo do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração da matriz 10x10 representando o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais dos navios
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 6;

    // Validação para garantir que os navios estão dentro dos limites e não se sobrepõem

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaNavioHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;

        // Verifica se há sobreposição com o navio vertical
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] == 3) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio horizontal no tabuleiro
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
            }
        } else {
            printf("Erro: Sobreposição detectada para o navio horizontal.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaNavioVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;

        // Verifica se há sobreposição com o navio horizontal já colocado
        for (int i = 0; i < TAMANHO_NAVIO; i++){
            if(tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3){
                sobreposicao = 1;
                break;
            }
        }
    if (!sobreposicao){
          // Posiciona o navio vertical no tabuleiro
          for(int i = 0; i < TAMANHO_NAVIO; i++){
            tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
          }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibição do tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
};
