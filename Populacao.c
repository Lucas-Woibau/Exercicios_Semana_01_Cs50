#include <stdio.h>
#include <cs50.h>

int main()
{
    int popInicial, popFinal; // Variáveis para armazenar o tamanho inicial e final da população.
    int n = 0; // Variável não utilizada neste código.
    int ano = 0; // Variável para contar os anos.

    do{
        popInicial = get_int("Start Size: "); // Solicita ao usuário o tamanho inicial da população.

    }while(popInicial < 9); // Continua pedindo até que o valor inserido seja maior ou igual a 9.

    do{
        popFinal = get_int("End Size: "); // Solicita ao usuário o tamanho final da população.

    }while(popFinal < popInicial); // Continua pedindo até que o valor inserido seja maior ou igual ao tamanho inicial.

    for(ano = 0; popInicial < popFinal; ano++)
    {
        int nasc = popInicial / 3; // Calcula o número de nascimentos como um terço da população atual.
        int morte = popInicial / 4; // Calcula o número de mortes como um quarto da população atual.

        popInicial += nasc; // Atualiza o tamanho da população adicionando o número de nascimentos.
        popInicial -= morte; // Atualiza o tamanho da população subtraindo o número de mortes.
    }

    printf("Years: %i\n", ano); // Imprime o número de anos calculados na tela.

    return 0; // Finaliza o programa com código de retorno 0 (indicando sucesso).
}
