#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void abertura()
{

    printf("----------------------------------\n");
    printf("|Bem vindo a Lista de verificação|\n");
    printf("----------------------------------\n");

}

void inserir(int lista[], int* tamanho)
{

    printf("Digite qual o tamanho que você quer sua lista: ");
    scanf("%d", tamanho);

    for(int i = 0; i < *tamanho; i++)
    {

        printf("Número %d: ", i + 1);
        scanf("%d", &lista[i]);

    }

}

void verificar(int lista[], int* tamanho)
{
    int n, encontrado;

    printf("Digite um número para verificar se ele está na sua lista (ou -1 para sair): ");
    scanf("%d", &n);

    while (n != -1)
    {
        encontrado = 0;

        for(int i = 0; i < *tamanho; i++)
        {
            if(lista[i] == n)
            {
                printf("Sim, o número %d está na lista.\n", n);
                encontrado = 1;
                break;
            }
        }

        if(!encontrado)
        {
            printf("Não, o número %d não está na lista.\n", n);
        }

        printf("Digite outro número para verificar (ou -1 para sair): ");
        scanf("%d", &n);
    }

}

void exibir(int lista[], int* tamanho)
{
    printf("Lista atual:\n");
    for(int i = 0; i < *tamanho; i++)
    {
        printf("(%d) ", lista[i]);
    }
    printf("\n");
}

void opcoes(int lista[], int* tamanho)
{

    int escolha;
    int continuar = 1;

    while(continuar)
    {

        printf("Digite quais opções você quer fazer na sua nova lista \n");
        printf("1 - Inserir elementos na lista.\n");
        printf("2 - Verificar elementos na lista.\n");
        printf("3 - Verificar um valor especifico na lista.\n");
        printf("4 - Digite '0' para sair do programa\n\n");
        scanf("%d", &escolha);

        switch(escolha)
        {
            case 1:
                inserir(lista, tamanho);
                break;

            case 2:
                exibir(lista, tamanho);
                break;

            case 3:
                verificar(lista, tamanho);
                break;

            case 0:
                continuar = 0;
                break;
        }

    }
    system("cls");

}

void programa()
{

    setlocale(LC_ALL, "portuguese");

    int lista[50];
    int tamanho = 0;

    abertura();
    opcoes(lista, &tamanho);

}

int main()
{
    programa();
    return 0;
}