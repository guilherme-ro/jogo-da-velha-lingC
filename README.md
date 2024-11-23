# jogo-da-velha-lingC
Jogo da Velha em Linguagem C

## Game com Suporte da Ferramenta ChatGPT

Jogo da velha desenvolvido em Linguagem C com suporte do ChatGPT. Projeto relacionado ao curso Formação C/C++ Developer da DIO - https://www.dio.me/

O jogo permite dois jogadores, em que um joga com 'X' e o outro com 'O'. O código verifica as condições de vitória e empate.

**Explicação do código:**

  1 **Inicialização do Tabuleiro:** A função inicializarTabuleiro preenche todas as posições do tabuleiro com o caractere ' ' (espaço em branco), indicando que estão vazias.
  
  2 **Exibição do Tabuleiro:** A função exibirTabuleiro imprime o tabuleiro no formato de uma matriz 3x3 com as divisões entre as células.
  
  3 **Verificação de Vitória:** A função verificarVitoria checa se o jogador atual conseguiu preencher uma linha, uma coluna ou uma diagonal com seu símbolo.
  
  4 **Verificação de Empate:** A função verificarEmpate verifica se não há mais espaços vazios no tabuleiro e, ao mesmo tempo, nenhum jogador venceu, resultando em um empate.
  
  5 **Lógica de Jogo:** No loop principal, os jogadores alternam entre as jogadas, e o programa verifica se houve vitória ou empate após cada jogada. Caso haja uma vitória ou empate, o jogo termina.
  
  6 **Jogada Inválida:** O programa só permite que o jogador faça uma jogada válida, ou seja, ele precisa escolher uma posição que não tenha sido ocupada previamente.

**Como jogar:**

  1 O jogador 'X' começa, e os jogadores se alternam entre as jogadas.
  2 Para fazer uma jogada, o jogador deve digitar as coordenadas da linha e da coluna (ambas entre 0 e 2). Exemplo: "1 1" para a posição central.
  3 O jogo termina quando um jogador vence ou quando o tabuleiro está cheio e não houve vitória (empate).
