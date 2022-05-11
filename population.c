# include <cs50.h>
# include <stdio.h>

int get_inicial(void);

int main(void)
{
    int ini = get_inicial();

//solicitar a população final
    int final = 0;
    while (final < ini)
    {
        printf("Insira o número da população final: \n");
        scanf("%i", &final);
    }

//calculo quantidade de anos
    int cont_anos = 0;
    while (ini < final)
    {
        ini = ini + (ini / 3) - (ini / 4);
        cont_anos++;
    }

    printf("Número de anos para chegar na população final indicada: %i\n", cont_anos);
}


//solicitar tamanho inicial da população
int get_inicial(void)
{
    int inicial;
    do
    {
        printf("Insira o número da população inicial: \n");
        scanf("%i", &inicial);
    }

    while (inicial < 9);
    return inicial;
}
