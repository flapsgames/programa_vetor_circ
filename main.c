/* * * * * * * * * * * * * * * * * * * * *
 *                                       *
 *  Aluno : Lucas Carvalho               *
 *  Data : 28/06/2022                    *
 *  Curso : 1° Período EAI               *
 *  Aula : Laboratório de Programação    *
 *                                       *
 * * * * * * * * * * * * * * * * * * * * */

/************************************************************
*                                                           *
*   Este programa faz o calculo de 5 áreas e 5 perímetros   *
*   de sua respectiva circunferência, baseado nos 5 raios   *
*   informados pelo usuário. Além disso, o usuário escolhe  *
*   a ordem que o programa deve mostrar as 5 áreas e os     *
*   5 perímetros.                                           *
*                                                           *
*************************************************************/

// ------ DECLARAÇÕES ------
    // VARIÁVEIS:
    int numero_area, numero_perimetro;

    // DECLARAÇÃO DOS VETORES:
    float raio[5] = {0};
    float area[5] = {0};
    float perimetro[5] = {0};
    char escolha[10];

// ------------ FUNÇÕES --------------
    // FUNÇÃO QUE CRIA O MENU DE ESCOLHA ENTRE ÁREA E PERÍMETRO:
char menu(int i)
{
    // DEFINIÇÃO DE VARIÁVEIS
    printf("\n ------------------");
    printf("\n\t MENU \n Escolha uma opcao: ");
    printf("\n [A] area ");
    printf("\n [P] perimetro \n ");
    getchar();
    // captura a escolha do usuário e salva na respectiva posição do vetor escolha.
    escolha[i] = getchar();
    switch(escolha[i])
        {
            case 'a':
            case 'A':
            if (numero_area < 5)
            {
                numero_area = numero_area + 1;
            }
            else
            {
                printf("\n ERRO: Voce pode escolher esta opcao apenas 5 vezes. \n");
                menu(i);
            }
            break;
            case 'p':
            case 'P':
            if (numero_perimetro < 5)
            {
                numero_perimetro = numero_perimetro + 1;
            }
            else
            {
                printf("\n ERRO: Voce pode escolher esta opcao apenas 5 vezes. \n");
                menu(i);
            }
            break;
            default:
            printf("Por favor, use apenas os itens do menu. \n");
            menu(i);
        }
}

    // FUNÇÃO DE CALCULO DA ÁREA DE PERÍMETRO:
float calculo(float raio, char opcao)
{
    // define as variavéis que serão usadas para o cáculo.
    float pi, area, perim, a, p;
    pi = 3.1415;
    if (raio < 0)
    {
        raio = raio * -1;
    }
    // Interpreta a escolha do usuário
    switch(opcao)
    {
        case 'A':
        case 'a':
        // fórmula da área de uma circunferência.
        a = pi * (raio * raio);
        // mostra na tela o cálculo.
        return a;
        break;
        case 'P':
        case 'p':
        // fórmula do perímetro
        p = 2 * pi * raio;
        // mostra na tela o cálculo.
        //printf(" Perimetro: %.3f", p);
        return p;
        break;
    }
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // DECLARAÇÃO DAS VARIÁVEIS:
    int contagem_Area, contagem_Perimetro;
    contagem_Perimetro = contagem_Area = 0;

    // --- ADIÇÃO DE ACENTOS ---
    // Definindo regras de escrita, no CMD, para as regras do Português - BR
    // O código acima permite que o CMD leia e mostre palavras com acento "é", "à" "não"

    printf("\n\n\t==== Engenharia de Automação Industrial - 1 Per. ====\n");
    printf("\n\t============= CALCULO AREA E PERIMETRO ==============\n\n\n");
    printf(" Por favor, digite o valor de 5 raios: \n");

    printf("\n -------------------------------------");
    // Loop que roda o código abaixo para cada espaço do vetor.
    for (int a = 0; a < 5; a++)
    {
        printf("\n  raio %d: ", a + 1);
        scanf("%f", &raio[a]);

        // Verifica se o raio escolhido é igual à zero. Caso for, abre um loop até que o usuário escolha um raio diferente de zero.
        while (raio[a] == 0)
        {
            printf("  ERRO: O raio não pode ser igual à zero.\n");
            printf("\n  Digite novamente o raio %d: ", a + 1);
            scanf("%f", &raio[a]);
        }
        // Verifica se o raio é menor do que zero. Caso for, envia um alerta dizendo que não existe raio < 0.
        // Apesar de permitir que seja posto um raio < 0, a função "calculo" corrige este raio, o colocando em módulo.
        if (raio[a] < 0)
        {
            printf(" Alerta: O raio nao pode assumir valores negativos. Portanto, o programa ira calcular o modulo deste numero.\n");
        }
    }

    printf(" -------------------------------------");


    // Para cada posição do vetor Escolha, pede o usuário para inserir a opção (Área ou perímetro).
    for (int i = 0; i < 10; i++)
    {
        // chama a função que cria o menu.
        menu(i);
    }
    printf("\n ------------------\n");


    // Mostra na tela os resultados, para cada posição do vetor escolha.
    for (int n = 0; n < 10; n++)
    {
        // lê a posição atual do vetor Escolha e verifica se dentro desta posição está registrado Área ou Perimetro.
        switch (escolha[n])
        {
            case 'a':
            case 'A':
            // mostra na tela a área da respectiva circunferência.
            printf("\n A area da circunferencia %d e: %.3f", contagem_Area + 1, calculo(raio[contagem_Area], escolha[contagem_Area]));
            // Adiciona um a contagem da área, para mostrar que a área da circunferência X já foi calculada.
            contagem_Area++;
            break;
            case 'p':
            case 'P':
            printf("\n O Perimetro da circunferencia %d e: %.3f", contagem_Perimetro + 1, calculo(raio[contagem_Perimetro], escolha[contagem_Perimetro]));
            // Adiciona um a contagem do perímetro, para mostrar que o perímetro da circunferência X já foi calculado.
            contagem_Perimetro++;
            break;
        }
    }
}
