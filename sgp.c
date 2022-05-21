#include <stdio.h>
#include <stdlib.h>
// Struct da Data de Nascimento
typedef 
struct nascimento{
int dia;
int mes;
int ano;
}tipoNasci;
//Struct da quantidade de filhos e a idades deles
typedef 
struct filho{
int filho ;
int idade;
}tipoFilho;
// Struct do Funcionario
typedef  

struct pessoa{
  int matri;
  char nomeF[40];
  tipoNasci nasci;
  char EsCivil[40];
  tipoFilho filhos;
  int cpf;
  char genero[40];
  int setorFun;
  float salarioBruto;
}tipoFuncionario;
//Declaração de uma variavel do tipo Struct
tipoFuncionario funcionario[4];
//Struct de Setores
typedef 

struct setores{
int codSetor;
int matriGerente;
int quantidadeFun;
}tipoSetores;
tipoSetores setor[2];



void cadastroSetor(){
  int s=0;
  printf("\nDigite o Código do Setor ou '0' para Encerrar:  ");
      scanf("%d",&setor[s].codSetor);
   while (setor[s].codSetor != 0){
     
      
     if (setor[s].codSetor != 0){
    printf("\nDigite a Matricula do Gerente deste Setor:  ");
      scanf("%d",&setor[s].matriGerente);
       
     }
  s++;
  printf("\nDigite o Código do Setor ou '0' para Encerrar:  ");
      scanf("%d",&setor[s].codSetor);

    }
  }
tipoFuncionario pessoa;
int f;
int cadastrei;
int registrarFuncionario(tipoFuncionario func){
  
   
  int s;
  int valor;
  
  //repetir ate que o codigo digitado seja igual que o cadastrado  
  //OBS: Essa validação só pegara com um limite de setor.
  ///////
  
    do{  
        printf("\nDigite o Código do Setor do Funcionario:  ");
          scanf("%d",&pessoa.setorFun);
        s = 0;
     
        if (pessoa.setorFun != setor[s].codSetor){
          while (pessoa.setorFun != setor[s].codSetor && s < 3){
            s++;
             valor =-1;
          }//fim do while
        } 
      for (s=0;s<3;s++){
        if (pessoa.setorFun == setor[s].codSetor){ 
          valor = 1;
          }
        }
        if (valor ==-1){
            printf("Setor Não Cadastrado!");
        }//fim do if
        /////////
        
    }while (valor == -1);

  printf("\nDigite o Nome do Funcionario:  ");
    fflush(stdin);
    scanf("%s",pessoa.nomeF);
  printf("\nDigite a Matricula do funcionario:  ");
    scanf("%d",&pessoa.matri);
  printf("\nDigite o CPF:  ");
    scanf("%d",&pessoa.cpf);
  printf("\nDigite a Data de Nascimento:  ");
    scanf("%d/%d/%d",&pessoa.nasci.dia,&pessoa.nasci.mes,&pessoa.nasci.ano);
  printf("\nDigite o Estado Civil:  ");
  fflush(stdin);
    scanf("%s",pessoa.EsCivil);
  printf("\nDigite o Gênero: ");
  fflush(stdin);
    scanf("%s",pessoa.genero);
  printf("\nDigite quantidade de filhos Menor de idade:  ");
    scanf("%d",&pessoa.filhos.filho);
  printf("\nDigite o Salário Bruto:  ");
    scanf("%f",&pessoa.salarioBruto);
  funcionario[f] = pessoa;
  f++;
  
 return  cadastrei = 1; 
}

int consultaFuncionario(){
 




  
  return  0;  
}

void exclusaoFuncionario(){
  
}
int calcularChequeFunc(){
  
  return  0;
}



int main (){
    int voltarModulo;
    int opcao;
  do{  
        printf ("--------------------------------------------------\n");
        printf ("| Sistema de Gestão de Pessoal - | \n");
        printf ("--------------------------------------------------\n");
        printf ("| | \n");
        printf ("| 1 - Funcionários; | \n");   
        printf ("| 2 - Folha de pagamento; | \n"); 
        printf ("| 3 - Análise geral; | \n"); 
        printf ("| 4 - Encerrar o sistema; | \n"); 
        printf ("| | \n");
        printf ("--------------------------------------------------\n");
        
        printf ("Digite sua opção:\n");
        scanf ("%d",&opcao);
        
        switch (opcao)
        {
          int opcaoFuncionario;
           
            case  1:
             
            // "do while" Para encerrar o modulo
            do{
              //Menu do Funcionario
                printf ("--------------------------------------------------\n");
                printf ("| Módulo Funcionário | \n");
                printf ("--------------------------------------------------\n");
                printf ("| | \n");
                printf ("| 1 - Registro; | \n");
                printf ("| 2 - Consulta; | \n"); 
                printf ("| 3 - Exclusão; | \n"); 
                printf ("| 4 - Cálculo de contracheque; | \n");
                printf ("| 5 - Encerrar o módulo; | \n");  
                printf ("| | \n");
                printf ("--------------------------------------------------\n");
                  //leitura da opcao 
                    printf ("Digite sua opção:\n");
                    scanf("%d",&opcaoFuncionario);
    
                switch (opcaoFuncionario)
                {
                  
                  
                  
                  case 1:
                    do{
                    printf("\n|Opção 1 escolida!|\n\n");
                    printf("\n|Cadastro dos Setores|\n");
                      
                          cadastroSetor();
                    
                    
                    printf("\n|Registro de funcionarios|\n");
                          registrarFuncionario(pessoa);
    
                    if (cadastrei == 1){
                      printf("\n\nFuncionario Cadastrado Com Sucesso!\n\n");
                      }
                    
                    printf("\n| Deseja voltar para o Modulo de Funcionario |\n");
                    printf("\n\n|Digite '0'| Caso Não  |Digite qualquer valor|\n\n");
                    scanf("%d",&voltarModulo);
                     
                   }while (voltarModulo != 0);
                      
                  break;
    
                  case 2:
                    printf("\n|Opção 2 escolida!|\n\n");
                    
                          consultaFuncionario();
                    
                  break;
    
                  case 3:
                    printf("\n|Opção 3 escolida!|\n\n");
                    
                          exclusaoFuncionario();
                    
                  break;
    
                  case 4:
                    printf("\n|Opção 4 escolida!|\n\n");
                    
                          calcularChequeFunc();
                    
                  break;
    
                  case 5:
                          printf("\n|Módulo De Funcionario Encerrado|\n\n");
                  break;
    
                  default:
                          printf("\n|Opção Inválida|\n\n");
                  }
              //Fim do "do while"
              }while (opcaoFuncionario != 5);
                break;
            case 2:
                printf("Escolhida a segunda opção ! \n");
                break;
            case 3:
                printf("Escolhida a terceira opção ! \n");
                break;
            case 4:
                printf("\n|Programa Encerrado|\n");
                break;
            default:
                printf("Opção inválida !!! \n");
        }
    
    }while (opcao != 4);
    return  0;
}