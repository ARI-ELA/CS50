// solicitar ao usuario o numero de cartão de crédito(long, inteiro, sem pontos e hífens)

// Algoritimo de LUHN

// verificar:
// AMEX com 15 digitos, inicia em 34 ou 37
// MASTERCARD  16 digitos, inicia em 51, 52, 53, 54 ou 55
// VISA 13 ou 16 digitos, inicia em 4

// imprimir se o cartão é VISA, MASTERCARD, AMEX válidos.
// linha de saída do seu programa seja AMEX\n ou MASTERCARD\n ou VISA\n ou INVALID\n


#include <stdio.h>
#include <cs50.h>


long get_n_cartao(void);

int main (void)
{
    long n_c;

    long num_c = get_n_cartao();

    //passo 1 : somar dig não multiplicados
    n_c = num_c;
    int soma1 = 0;

    while (n_c > 0)
    {
        int ultimoDig = n_c % 10; // pega o ultimo digito
        soma1 = soma1 + ultimoDig;
        n_c = n_c / 100;
    }

    //passo 2 : somar dig multiplicados por 2
    n_c = num_c / 10; //para poder pegar penultimo digito
    int soma2 = 0;

    while (n_c > 0)
    {
        int segundoDig = n_c % 10; //pegou o penultimo digito
        int mult = segundoDig * 2;
        soma2 = soma2 + (mult % 10) + (mult / 10); // esses mult para somar qnd a multiplicação der mais de 2 dig
        n_c = n_c / 100;
    }

// passo 3 : verificar validação

    int validacao = soma1 + soma2;
    validacao = validacao % 10;

// passo 4: contar numero de digitados
    n_c = num_c;
    int cont = 0;

    while(n_c != 0) // cc é diferente de zero
     {
         n_c /=10;
         cont++;
     }

// passo 5 : verificar bandeiras
    long div = 10;
    for (int i = 0; i < cont - 2; i++) // for para conseguir o divisor para pegar os primeiros digitos do cartão
    {
        div = div * 10;
    }

    int primeiroDig = num_c / div;
    int doisPrimeiros = num_c / (div / 10);

    if((cont == 13 || cont == 16) && primeiroDig == 4 && validacao == 0)
        printf("VISA\n");

    else if(cont == 16 && validacao == 0 && doisPrimeiros > 50 && doisPrimeiros < 56)
        printf("MASTERCARD\n");

    else if(cont == 15 && (doisPrimeiros == 34 || doisPrimeiros == 37) && validacao == 0)
        printf("AMEX\n");

    else
        printf("INVALID\n");

}


// solicitar numerdo do cartão
long get_n_cartao(void)
{
    long cartao;
    do
    {
        printf("Insira o número do cartão: \n");
        scanf("%li", &cartao);
    }

    while (cartao <= 0);
    return cartao;
}