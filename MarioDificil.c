#include <stdio.h>
#include <cs50.h>

//Validar a entrada de apenas numeros de 1 a 8
int main(void)
{
    int n;
    do
    {
        n = get_int("Digite um numero de 1 a 8: ");

    }while(n < 1 || n > 8);

    for(int i = 0; i < n; i++)      //Constroi as linhas
    {
        for(int j = 0; j < n; j++)  //Constroi as colunas
        {
            if(n - i - 2 < j)       //Verifica a partir de qual posição devemos desenhar as '#'
            {
                printf("#");        //Se j(pos atual) for maior ou igual a esse numero, desenhamos uma '#'
            }
            else
            {
                printf(" ");        //Caso contrário desenhamos um 'espaço'.
            }
        }

        printf("  ");

        for(int k = n; k > 0; k--)  //Lê o laço ao contrário e reverte a segunda pirâmide
        {
            if(n - k - 1 < i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

}