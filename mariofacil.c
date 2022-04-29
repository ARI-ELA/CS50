#include <stdio.h>
#include <cs50.h>

int get_altura_positiva(void);
void tijolos(int n);


int main(void)
{
    int al = get_altura_positiva();
    tijolos(al);
}

// condição para imprimir # de acordo com o numero escolhido pelo usuário
void tijolos(int n)
{
    for (int i = 0; i < n; i++)
    {
        //imprimir espaço por linha
       for (int j = n - i; j > 1; j--)
       {
            printf(" ");
       }
         // imprimir # por linha
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}

// loop Do While para aceitar somente numeros inteiros entre 1 e 8
int get_altura_positiva(void)
{
    int h;
    do
    {
        h = get_int("altura: ");
    }
    while(h < 1 || h > 8);
    return h;
}