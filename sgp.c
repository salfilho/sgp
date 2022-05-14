#include <stdio.h>
#include <stdlib.h>

int main (){
    
    int opcao;

    printf("--------------------------------------------------\n");
    printf("|     Sistema de Gerenciamento de Pessoal - SGP  |\n");
    printf("--------------------------------------------------\n");
    printf("|                                                |\n");
    printf("|  1 - Funcionários;                             |\n");   
    printf("|  2 - Folha de pagamento;                       |\n"); 
    printf("|  3 - Análise geral;                            |\n"); 
    printf("|  4 - Encerrar o sistema;                       |\n"); 
    printf("|                                                |\n");
    printf("--------------------------------------------------\n");
    
    printf("Digite sua opção:\n");
    scanf("%d",&opcao);

    switch (opcao){
        case 1:
            printf("--------------------------------------------------\n");
            printf("|      Módulo Funcionário                        |\n");
            printf("--------------------------------------------------\n");
            printf("|                                                |\n");
            printf("|  1 - Registro;                                 |\n");
            printf("|  2 - Consulta;                                 |\n"); 
            printf("|  3 - Exclusão;                                 |\n"); 
            printf("|  4 - Cálculo de contracheque;                  |\n");
            printf("|  5 - Encerrar o módulo;                        |\n");  
            printf("|                                                |\n");
            printf("--------------------------------------------------\n");
            break;
        case 2:
            printf("Escolhida a segunda opção !\n");
            break;
        case 3:
            printf("Escolhida a terceira opção !\n");
            break;
        case 4:
            printf("Escolhida a quarta opção !\n");
            break;
        default:
            printf("Opção inválida !!!\n");
    }


    return 0;
}