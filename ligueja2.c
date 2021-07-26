#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char tabuleiro[6][12], vazio = 0;
    int linha1, coluna1, linha2, coluna2, i = 0, j = 0, a = 0, b = 0, n = 97, cont = 0, randlin, randcol, jogadas = 0, valido = 0, verificacao = 0, k = 5, l = 11;
    srand(time(NULL));
    while (i < 6) //define toda o tabuleiro como NUL
    {
        while (j < 12)
        {
            tabuleiro[i][j] = vazio;
            j++;
        }
        j = 0;
        i++;
    } //fim da definicao do tabuleiro como NUL
    i = 0;
    while (cont < 4) //define letras aleatorias para as posicoes da matriz tabuleiro
    {

        while (n <= 114) //numero para letra pela tabela ascii
        {
            randlin = rand() % 6;
            randcol = rand() % 12;
            if (tabuleiro[randlin][randcol] == vazio)
            {
                tabuleiro[randlin][randcol] = n;
                n++;
            }
        }
        n = 97;
        cont++;
    } //fim da definicao de letras para a matriz tabuleiro
    printf("== BEM VINDO AO JOGO DO LIGUE JA, O FAVORITO DO DOMINGAO DO FAUSTAO! ==\n");
    printf("Regras: \n -Deve-se escolher duas letras iguais que estejam na mesma coluna ou linha.\n -O par de letras escolhido sera removido do tabuleiro.\n");
    printf(" -As letras acima das removidas caem preenchendo o espaco vazio.\n -Nao se pode combinar uma letra com ela mesma.\n");
    printf("==================== BOA SORTE BICHO! ====================\n");

    while (jogadas < 36)
    {
        while (i < 6) //teste da existencia de jogadas possiveis
        {

            while (j < 12)
            {
                if (tabuleiro[i][j] != 0)
                {
                    a = 0;
                    b = 0;
                    while (a < 6)
                    {
                        if (a == i)
                            a++;
                        else
                        {
                            if (tabuleiro[i][j] == tabuleiro[a][j])
                            {
                                b = 12;
                                i = 7;
                                j = 12;
                                break;
                            }
                            else
                                a++;
                        }
                    }
                    while (b < 12)
                    {
                        if (b == j)
                            b++;
                        else
                        {
                            if (tabuleiro[i][j] == tabuleiro[i][b])
                            {
                                i = 7;
                                j = 12;
                                break;
                            }
                            else
                                b++;
                        }
                    }
                    j++;
                }
                else
                    j++;
            }
            j = 0;
            i++;
        }
        if (i == 6)
        {
            jogadas = 84;
            break;
        } //fim teste da existencia de jogadas possiveis
        i = 0;
        j = 0;

        printf("   0    1    2    3    4    5    6    7    8    9   10   11 \n"); //impressao da matriz tabuleiro
        while (i <= 5)
        {
            printf("%d", i);
            while (j <= 11)
            {
                if (tabuleiro[i][j] == 0)
                {
                    printf(" [ ] ");
                    j++;
                }
                else
                {
                    printf(" [%c] ", tabuleiro[i][j]);
                    j++;
                }
            }
            j = 0;
            printf("\n");
            i++;
        }
        i = 0;              //fim impressao da matriz tabuleiro
        while (valido == 0) //escolha das linhas e colunas
        {
            printf("\n");
            printf("Digite a linha da primeira letra: ");
            scanf("%d", &linha1);
            if (linha1 == 1234)
            {
                jogadas = 36;
                break;
            } //valvula de escape para vitoria
            else if (linha1 == 666)
            {
                jogadas = 85;
                break;
            } //valvula de escape para derrota
            else if ((linha1 > 5) || (linha1 < 0))
                printf("\nLinha invalida.\n");
            else
                valido++;
        }
        if (valido == 0)
            break;
        while (valido == 1)
        {
            printf("Digite a coluna da primeira letra: ");
            scanf("%d", &coluna1);
            if ((coluna1 > 11) || (coluna1 < 0))
                printf("\nColuna invalida.\n");
            else
                valido++;
        }
        while (valido == 2)
        {
            printf("Digite a linha da segunda letra: ");
            scanf("%d", &linha2);
            if ((linha2 > 5) || (linha2 < 0))
                printf("\nLinha invalida.\n");
            else
                valido++;
        }
        while (valido == 3)
        {
            printf("Digite a coluna da segunda letra: ");
            scanf("%d", &coluna2);
            if ((coluna2 > 11) || (coluna2 < 0))
                printf("\nColuna invalida.\n");
            else
                valido++;
        } //fim da escolha das linhas e colunas
        valido = 0;

        if ((linha1 != linha2) && (coluna1 != coluna2)) //verificacao do alinhamento das coordenadas
            printf("\nAs letras nao estao na mesma linha ou coluna. \n\n");
        else if ((linha1 == linha2) && (coluna1 == coluna2))
            printf("\nNao se pode combinar uma letra com ela mesma. \n\n");
        else if (tabuleiro[linha1][coluna1] == tabuleiro[linha2][coluna2]) //fim da verificacao das coordenadas
        {                                                                  //sumindo com o par de letras
            tabuleiro[linha1][coluna1] = 0;
            tabuleiro[linha2][coluna2] = 0;
            jogadas++;              //letras sumiram
            printf("\nJogadas = %d\n", jogadas);
            while (verificacao < 2) //arrumando as matriz em relacao as letras que caem
            {
                while (k > 0)
                {
                    while (l >= 0)
                    {
                        if (tabuleiro[k][l] == 0)
                        {
                            tabuleiro[k][l] = tabuleiro[k - 1][l];
                            tabuleiro[k - 1][l] = 0;
                        }
                        l--;
                    }
                    l = 11;
                    k--;
                }
                verificacao++;
                k = 5;
            }
            verificacao = 0; //fim da arrumacao da matriz
        }
        else
            printf("\nAs letras nao sao iguais.\n");
    }
    if (jogadas == 36)
    {
        printf("PARABENS, VOCE GANHOU UM UNO 4 PORTAS!\n");
        printf("     ___________              \n");
        printf("    //   |||   \\\\           \n");
        printf(" __//____|||____\\\\____      \n");
        printf("| _|      |       _  ||       \n");
        printf("|/ \\______|______/ \\_||     \n");
        printf("_\\_/_____________\\_/_______ \n");
    }
    else
    {
        printf("PARABENS, VOCE PERDEU O JOGO E GANHOU UM JANTAR COM A SOGRA!\n");
        printf("  _____  \n");
        printf(" /     \\ \n");
        printf("| () () |\n");
        printf(" \\  ^  / \n");
        printf("  |||||  \n");
        printf("  |||||  \n");
    }
    return 0;
}