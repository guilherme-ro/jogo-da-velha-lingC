#include <stdio.h>

#define SIZE 3  // Tamanho do tabuleiro

// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

// Função para verificar se alguém venceu
int verificarVitoria(char tabuleiro[SIZE][SIZE], char jogador) {
    // Verifica linhas e colunas
    for (int i = 0; i < SIZE; i++) {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) || 
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)) {
            return 1;
        }
    }

    // Verifica diagonais
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) || 
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return 1;
    }

    return 0;
}

// Função para verificar empate
int verificarEmpate(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;  // Se houver alguma posição vazia, não é empate
            }
        }
    }
    return 1;  // Se não houver mais espaços vazios, é empate
}

// Função principal
int main() {
    char tabuleiro[SIZE][SIZE];
    int linha, coluna;
    int jogadaValida;
    int rodada = 0;
    char jogadorAtual = 'X';

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Loop principal do jogo
    while (1) {
        exibirTabuleiro(tabuleiro);

        // Solicita a jogada do jogador atual
        do {
            printf("Jogador %c, digite a linha (0-2) e a coluna (0-2) para sua jogada: ", jogadorAtual);
            scanf("%d %d", &linha, &coluna);

            // Verifica se a jogada é válida
            jogadaValida = (linha >= 0 && linha < SIZE && coluna >= 0 && coluna < SIZE && tabuleiro[linha][coluna] == ' ');

            if (!jogadaValida) {
                printf("Jogada inválida. Tente novamente.\n");
            }

        } while (!jogadaValida);

        // Realiza a jogada
        tabuleiro[linha][coluna] = jogadorAtual;

        // Verifica se o jogador atual venceu
        if (verificarVitoria(tabuleiro, jogadorAtual)) {
            exibirTabuleiro(tabuleiro);
            printf("Parabéns! O jogador %c venceu!\n", jogadorAtual);
            break;
        }

        // Verifica se deu empate
        if (verificarEmpate(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("O jogo empatou!\n");
            break;
        }

        // Alterna o jogador
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
        rodada++;
    }

    return 0;
}
