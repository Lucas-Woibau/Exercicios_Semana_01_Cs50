#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
    // Declaração de variáveis para armazenar os valores individuais dos dígitos
    int valor1, valor2, valor3, valor4, valor5, valor6, valor7, valor8,
    valor9, valor10, valor11, valor12, valor13, valor14, valor15, valor16;

    long numero = 0;

    // Solicita um número longo até que seja inserido um valor maior ou igual a 1
    do {
        numero = get_long("Numero: ");
    } while (numero < 1);

    // Pegando do último ao primeiro dígito, pulando um por um e multiplicando por 2
    valor15 = ((numero / 10) % 10) * 2;
    valor13 = (((numero / 10) / 100) % 10) * 2;
    valor11 = ((((numero / 10) / 100) / 100) % 10) * 2;
    valor9 = (((((numero / 10) / 100) / 100) / 100) % 10) * 2;
    valor7 = ((((((numero / 10) / 100) / 100) / 100) / 100) % 10) * 2;
    valor5 = (((((((numero / 10) / 100) / 100) / 100) / 100) / 100) % 10) * 2;
    valor3 = ((((((((numero / 10) / 100) / 100) / 100) / 100) / 100) / 100) % 10) * 2;
    valor1 = (((((((((numero / 10) / 100) / 100) / 100) / 100) / 100) / 100) / 100) % 10) * 2;

    // Pegar os valores e somar (transformando os decimais em unidades)
    valor15 = ((valor15 / 10) % 10) + (valor15 % 10);
    valor13 = ((valor13 / 10) % 10) + (valor13 % 10);
    valor11 = ((valor11 / 10) % 10) + (valor11 % 10);
    valor9 = ((valor9 / 10) % 10) + (valor9 % 10);
    valor7 = ((valor7 / 10) % 10) + (valor7 % 10);
    valor5 = ((valor5 / 10) % 10) + (valor5 % 10);
    valor3 = ((valor3 / 10) % 10) + (valor3 % 10);
    valor1 = ((valor1 / 10) % 10) + (valor1 % 10);

    int primeiraSoma = valor1 + valor3 + valor5 + valor7 + valor9 + valor11 + valor13 + valor15;

    // Pegando os números que não foram somados
    valor2 = numero % 10;
    valor4 = (numero / 10000) % 10;
    valor6 = (numero / 1000000) % 10;
    valor8 = (numero / 100000000) % 10;
    valor10 = (numero / 10000000000) % 10;
    valor12 = (numero / 1000000000000) % 10;
    valor14 = (numero / 100000000000000) % 10;
    valor16 = (numero / 10000000000000000) % 10;

    int segundaSoma = valor2 + valor4 + valor6 + valor8 + valor10 + valor12 + valor14 + valor16;

    int somaTotal = primeiraSoma + segundaSoma;

    // Verificar se o cartão tem resto 0 após a soma
    if (somaTotal % 10 != 0) {
        printf("INVALIDO\n");
        printf("%d", somaTotal);
        return 0;
    }

    // Contador de dígitos do número
    int contador = 0;

    while (numero != 0) {
        numero /= 10; // dividindo o valor da variável numero por 10 e, em seguida,
        contador++;    // atribuindo o resultado de volta à variável numero
    }

    // Verificando a marca do cartão com base no número de dígitos e no primeiro dígito
    if (contador == 16 && ((valor1 + valor2) >= 6 && (valor1 + valor2) <= 10)) {
        printf("MASTERCARD\n");
    }
    else if (contador == 15 && ((valor1 + valor2) >= 7 && (valor1 + valor2) <= 10)) {
        printf("AMERICAN EXPRESS\n");
    }
    else if ((contador == 13 || contador == 16) && (valor1 == 4)) {
        printf("VISA\n");
    }

    return 0;
}
