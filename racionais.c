// Arquivo de funções

#include "aux.h"

/* Controla o input do usuário */
int limitaVariavel(int max)
{
    int num; scanf("%d", &num);
    while ( num < 0 || num > max)
    {
        printf("Valor inválido. Digite um valor entre 0 e %d\n", max);
        scanf("%d", &num);
    }
    return num; 
}

/* retorna um numero aleatorio entre min e max. */
int aleat(int min, int max)
{
    return min + (rand() % (max + 1));
}

int mdc(int a, int b)
{
    if (a % b == 0)
        return b;
    return mdc(b, a % b);
};

/* Minimo Multiplo Comum entre a e b */
int mmc(int a, int b)
{
    return ((a * b) / mdc(a, b));
};

/* Retorna 1 se o racional r eh valido ou 0 caso contrario
 * Um racional eh invalido se o denominador for nulo */
int valido_r(struct racional r)
{
    return (r.den != 0);
};

/* Recebe um numero racional e o simplifica.
 * Por exemplo, ao receber 10/8 devera retornar 5/4
 * Se ambos numerador e denominador forem negativos, devera retornar um positivo
 * Se o denominador for negativo, o sinal deve migrar para o numerador
 * Quem chama esta funcao deve garantir que o racional r eh valido */
struct racional simplifica_r(struct racional r)
{
    int divisor;

    if (!valido_r(r))
        return r;

    divisor = mdc(r.num, r.den);
    r.num = r.num / divisor;
    r.den = r.den / divisor;

    if (r.den < 0)
    {
        r.num = r.num * -1;
        r.den = r.den * -1;
    }
    return r;
};

/* Cria um numero racional com base nas informacoes dos parametros. */
struct racional cria_r(int numerador, int denominador)
{
    struct racional r;
    r.num = numerador;
    r.den = denominador;

    r.valido = valido_r(r);
    r = simplifica_r(r);

    return r;
};

/* Retorna um numero racional aleatorio na forma simplificada.
 * O numerador e o denominador devem ser inteiros entre 0 e n.
 * O racional deve conter a informacao se ele eh valido ou nao */
struct racional sorteia_r(int n)
{
    int numerador, denominador;
    numerador = aleat(0, n);
    denominador = aleat(0, n);
    return cria_r(numerador, denominador);
};

/* Imprime um racional r */
void imprime_r(struct racional r)
{
    if (r.valido == 0)
        printf("INVALIDO");

    else if (r.num == r.den)
        printf("1");
    else if (r.den == 1)
        printf("%d", r.num);
    else if (r.num == 0)
        printf("0");

    else
        printf("%d/%d", r.num, r.den);
    printf(" ");
};

/* Retorna a soma dos racionais r1 e r2.
 * Quem chama esta funcao deve garantir que os racionais r1 e r2 sao validos */
struct racional soma_r(struct racional r1, struct racional r2)
{
    struct racional r;
    int mmc_resultado;

    mmc_resultado = mmc(r1.den, r2.den);
    r1.num = r1.num * (mmc_resultado / r1.den);
    r2.num = r2.num * (mmc_resultado / r2.den);

    r = cria_r(r1.num + r2.num, mmc_resultado) ;

    return r;
};

/* Retorna a subtracao dos racionais r1 e r2.
 * Quem chama esta funcao deve garantir que os racionais r1 e r2 sao validos */
struct racional subtrai_r (struct racional r1, struct racional r2)
{
    struct racional r;
    int mmc_resultado;

    mmc_resultado = mmc(r1.den, r2.den);
    r1.num = r1.num * (mmc_resultado / r1.den);
    r2.num = r2.num * (mmc_resultado / r2.den);

    r = cria_r(r1.num - r2.num, mmc_resultado); 

    return r;
};

/* Retorna a multiplicacao dos racionais r1 e r2.
 * Quem chama esta funcao deve garantir que os racionais r1 e r2 sao validos */
struct racional multiplica_r(struct racional r1, struct racional r2)
{
    return cria_r(r1.num * r2.num, r1.den * r2.den);
};

/* Retorna a divisao dos racionais r1 e r2.
 * Quem chama esta funcao deve:
     - garantir que os racionais r1 e r2 sao validos
     - em seguida deve garantir que o racional retornado tambem seja valido */
struct racional divide_r(struct racional r1, struct racional r2)
{
    struct racional r;
    r = cria_r(r1.num * r2.den, r1.den * r2.num);

    r.valido = valido_r(r);

    return r;
};
