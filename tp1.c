/* Arquivo MAIN que usa o TAD racionais */

#include "aux.h"

int main()
{
    srand(0); // Semente para gerar números aleatórios
    int num, max;
    struct racional r1, r2;

    num = limitaVariavel(100);
    max = limitaVariavel(30);

    for (int i = 1; i <= num; i++)
    {
        printf("%d: ", i);

        r1 = sorteia_r(max);
        r2 = sorteia_r(max);

        imprime_r(r1);
        imprime_r(r2);

        if (!r1.valido || !r2.valido) {
            printf("NUMERO INVALIDO\n");
            continue;
        };

        imprime_r(soma_r(r1, r2));
        imprime_r(subtrai_r(r1, r2));
        imprime_r(multiplica_r(r1, r2));
        imprime_r(divide_r(r1, r2));

        printf("\n");
    }

    return 0;
}
