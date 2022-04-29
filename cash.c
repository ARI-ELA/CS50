//solicitar um valor ao usuario
//1.float troco = get_float("valor de troco:")

//converter o valor em em centena
// 2.int cents = round(reais * 100);

//3. printf("%i\n",  );

//não aceitar valor negativos, nem textos
//1.1 do { } while (ser positico e numero, pode ter casas decimais)

//calcular quantas moedas entre 25, 10, 5, 1 centavos serão necessárias para esse valor,
//(com menor numero possível de moedas)
//2.2 pegar o valor inteiro
//ver qual moeda usar
//      armazenar essa quantidade e somar
//      verificar o valor restante
//      repetir o primeiro passo até chegar a zero

//usar um algoritimo ganancioso


# include <cs50.h>
# include <stdio.h>
# include <math.h>

float get_troco(void);
//int moedas(void);


int main(void)
{
    int tr = get_troco(); //solicita o valor do troco ao usuario

    // contar as moedas que precisarão conforme o troco informado
    int moedas;
    moedas = tr;
    int v25 = 0;
    int d10 = 0;
    int c5 = 0;
    int u1 = 0;

    while (moedas >= 25)
    {
        moedas = moedas - 25;
        v25++;
    }

    while (moedas >= 10)
    {
        moedas = moedas - 10;
        d10++;
    }

    while (moedas >= 5)
    {
        moedas = moedas - 5;
        c5++;
    }

    while (moedas >= 1)
    {
        moedas = moedas - 1;
        u1++;
    }
    printf ("%i\n", v25 + d10 + c5 + u1);

}


// solicitar o troco
float get_troco(void)
{
    float troco;
    do
    {
        troco = round(get_float("troco: ") * 100); // função round para convertes dollar em cents
    }
    while (troco < 1);
    return troco;
}