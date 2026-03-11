#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int tipodeveiculo;
    int tipodeseguro;
    int idade;
    int eixos;

    double valorbase  = 0.00;
    double adicionalC  = 0.00;
    double adicionalIdade  = 0.00;
    double valorCobertura  = 0.00;
    double valorTotal  = 0.00;


    printf("-============================================\n");
    printf("   SISTEMA DE CALCULO DE SEGURO VEICULAR   \n");
    printf("-============================================-\n\n");

    printf("Selecione o tipo de veiculo:\n");
    printf("  1 - Passeio\n");
    printf("  2 - Carga Pesada\n");
    printf("  3 - Caminhonete\n");
    printf("  4 - Motocicleta (ate 999cc)\n");
    printf("  5 - Motocicleta (1000cc ou mais)\n");
    printf("Opcao: ");
    scanf("%d", &tipodeveiculo);


    printf("Selecione o tipo de seguro:\n");
    printf("1- SEGURO BASICO\n");
    printf("2- SEGURO PARCIAL\n");
    printf("3- SEGURO COMPLETO\n");
    printf("OPCAO:");
    scanf("%d", &tipodeseguro);


    printf("\nInforme a idade do condutor principal: ");
    scanf("%d", &idade);


    if (tipodeveiculo == 2 || tipodeveiculo == 3) {
        printf("Informe o numero de eixos do veiculo: ");
        scanf("%d", &eixos);
    }

    if (tipodeveiculo == 4 || tipodeveiculo == 5) {
        valorbase = 1200.0;
    } else {
        valorbase = 1000.0;
    }


    if (tipodeveiculo == 1) {
        adicionalC = valorbase * 0.10;
    } else if (tipodeveiculo == 2) {
        adicionalC = valorbase * 0.20;
    } else if (tipodeveiculo == 3) {
        adicionalC = valorbase * 0.33;
    } else if (tipodeveiculo == 4) {
        adicionalC = valorbase * 0.80;
    } else if (tipodeveiculo == 5) {
        adicionalC = valorbase * 0.90;
    }


    if (idade < 25) {
        adicionalIdade = valorbase * 0.15;
    } else if (idade <= 29) {
        adicionalIdade = valorbase * 0.10;
    } else {
        adicionalIdade = valorbase * 0.05;
    }


    if (tipodeveiculo == 1) {

        if (tipodeseguro == 1)      valorCobertura = 2.0;
        else if (tipodeseguro == 2) valorCobertura = 2.0;
        else                      valorCobertura = 10.0;

    } else if (tipodeveiculo == 2 || tipodeveiculo == 3) {

        if (tipodeseguro == 1)      valorCobertura = valorbase * (0.03 * eixos);
        else if (tipodeseguro == 2) valorCobertura = valorbase * (0.05 * eixos);
        else                      valorCobertura = valorbase * (0.10 * eixos);

    } else if (tipodeveiculo == 4) {

        if (tipodeseguro == 1)      valorCobertura = -5.0;
        else if (tipodeseguro == 2) valorCobertura = 15.0;
        else                      valorCobertura = 80.0;

    } else if (tipodeveiculo == 5) {

        if (tipodeseguro == 1)      valorCobertura = 10.0;
        else if (tipodeseguro == 2) valorCobertura = 20.0;
        else                      valorCobertura = 100.0;
    }


    valorTotal = valorbase + adicionalC + adicionalIdade + valorCobertura;


    printf("\n============================================\n");
    printf("              RELATORIO DO SEGURO           \n");
    printf("============================================\n");
    printf("Valor Base:              R$ %8.2f\n", valorbase);
    printf("Adicional de Categoria:  R$ %8.2f\n", adicionalC);
    printf("Adicional de Idade:      R$ %8.2f\n", adicionalIdade);
    printf("Valor da Cobertura:      R$ %8.2f\n", valorCobertura);
    printf("--------------------------------------------\n");
    printf("VALOR TOTAL FINAL:       R$ %8.2f\n", valorTotal);
    printf("============================================\n\n");

    return 0;
}

