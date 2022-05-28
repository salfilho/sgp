#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
// Struct da Data de Nascimento
typedef 
struct nascimento{
	int dia;
	int mes;
	int ano;
}tipoNasci;

// Struct do Funcionario
typedef  

struct pessoa{
  int matri;
  char nomeF[40];
  tipoNasci nasci;
  char EsCivil[40];
  int filhos;
  char cpf[13];
  char genero[40];
  int setorFun;
  float salarioBruto;
  int cargo;
  char status[20];
}tipoFuncionario;
//DeclaraÃ§Ã£o de uma variavel do tipo Struct
tipoFuncionario funcionario[23];
//Struct de Setores
typedef 

struct setores{
	int codSetor;
	int matriGerente;
	int quantidadeFun;
}tipoSetores;
tipoSetores setor[3];

int ValidaNascimento(tipoNasci nascimento){

	int dia,mes,ano;

	if (nascimento.dia < 1 || nascimento.dia > 31 || nascimento.mes < 1 || nascimento.mes > 12 || nascimento.ano <1920 || nascimento.ano > 2021){
		return -1;
	}else
		return 1;
}

void cadastroSetor(){
  int s;
  	for (s=0;s <3;s++){
  
  		printf("\nDigite o Código do Setor :  ");
      		scanf("%d",&setor[s].codSetor);
   	} 
}

  
	//
	tipoFuncionario pessoa;
	//
	int f;
	int cadastrei;
	
int registrarFuncionario(tipoFuncionario func){
	int contador= 0;
	int validoN;
  	int s;
  	int valor;
  	int cpfValida;
  	int reposta;
  	int k ;
  //repetir ate que o codigo digitado seja igual que o cadastrado  
  //OBS: Essa validaÃ§Ã£o sÃ³ pegara com um limite de setor.
  ///////
  
  
    
		 
		do{ 
			do{
			
			printf(" \n|Escolha um dos Setores Cadastrados %d %d %d |\n",setor[0].codSetor,setor[1].codSetor,setor[2].codSetor);
		 
	        printf("\nDigite o Código do Setor do Funcionario:  ");
	          scanf("%d",&pessoa.setorFun);
	      	    						     	
        	s=0;
          while (pessoa.setorFun != setor[s].codSetor && s < 3){
            s++;
          }//fim do while
         
      
        if (pessoa.setorFun == setor[s].codSetor){ 
          valor = s;
          }else   
            valor = -1;
          
        if (valor ==-1){
            printf("Setor Não Cadastrado!");
        }//fim do if
        
    	}while (setor[valor].quantidadeFun > 1);
       
    }while (valor == -1);

  	printf("\nDigite o Nome do Funcionario:  ");
    	fflush(stdin);
    	gets(pessoa.nomeF);
  	printf("\nDigite a Matricula do funcionario:  ");
    	scanf("%d",&pessoa.matri);
    	
	printf("\n|Digite '1' Para Funcionário ou '2' Para Gerente|\n");
  	printf("\nDigite o Cargo do Funcionario:  ");
  		scanf("%d",&pessoa.cargo);
  		//Ideia Que tive para validar o gerente, porem ele compara o vetor todo e não só pro setor
  		//	k =0;
  		//	while (pessoa.cargo != funcionario[k].cargo && k < 8 && pessoa.setorFun == setor[s].codSetor){
  		//			k++;
		//			  }
		//	  if (pessoa.cargo == funcionario[k].cargo){
		//	  	printf("\nGerente ja Cadastrado Nesse Setor!");
		//	  }
		  
    
  	printf("\nDigite os Status:  ");
  		fflush(stdin);
    	gets(pessoa.status);   
	//Laço de repetição para a validação do cpf 
    do{
	
		printf("\nDigite o CPF:  ");
		fflush(stdin);
	    	gets(pessoa.cpf);
	    //Validação do CPf
	    cpfValida = strlen(pessoa.cpf);
	    
	    if (cpfValida < 11 || cpfValida > 11){
	    	printf("CPF Inválido! Tente Novamente!");
		}
	
	}while (cpfValida < 11 || cpfValida > 11);
	
	//Laço de repetição para a validação da Data de Nascimento
	do{
	
  		printf("\nDigite a Data de Nascimento:  ");
    		scanf("%d/%d/%d",&pessoa.nasci.dia,&pessoa.nasci.mes,&pessoa.nasci.ano);
    // Validação da Data de Nascimento
     	validoN = ValidaNascimento(pessoa.nasci);
    
		if (validoN == -1){
			printf("\nData Inválida! Tente Novamente!\n");
		}
	}while (validoN == -1);
	//
	  printf("\nDigite o Estado Civil:  ");
	  	fflush(stdin);
	    gets(pessoa.EsCivil);
	  printf("\nDigite o Gênero: ");
	  	fflush(stdin);
	    gets(pessoa.genero);
	  printf("\nDigite quantidade de filhos Menor de idade:  ");
	    scanf("%d",&pessoa.filhos);
	  printf("\nDigite o Salário Bruto:  ");
	    scanf("%f",&pessoa.salarioBruto);
	  funcionario[f] = pessoa;
	  f++;
	  setor[valor].quantidadeFun++;

  if (setor[valor].quantidadeFun >=2){
    printf("\n| Não Existem Vagas Nesse Setor! |\n");
	}	
		 
 return  1; 
}

int consultaFuncionario(){


  
    




  
  return  0;  
}

void exclusaoFuncionario(){
	
  	int cpfCompara,matriExclusao;
  	int c ;
  	char copia[20];
  	tipoFuncionario *mudarStatus;
	char cpfExclusao[12];  
	int opcaoContinua = 0;
  	do{
		printf("\nDigite o CPf do Funcionário que Deseja Mudar os Status: ");
		fflush(stdin);
		gets(cpfExclusao);
		
		printf("\nDigite o CPf do Funcionário que Deseja Mudar os Status: ");
		scanf("%d",&matriExclusao); 
			// While para Obter a posição do Funcionario
			c =0;
		  while (matriExclusao != funcionario[c].matri && c < 22){
		    c++;
		  }
		 
		  	// Ponteiro recebe o endereço de funcionario
		    mudarStatus = &funcionario[c];
		    //Comparação da cpf digitado com o cpf do funcionario
		    cpfCompara = strcmp(cpfExclusao,funcionario[c].cpf);
		    // condiçao caso ache o funcionario
		  if( cpfCompara== 0 && matriExclusao == funcionario[c].matri){ 
		    printf("\nSetor Do Funcionário : %d \n",funcionario[c].setorFun);
		    printf("\nMatricula Do Funcionário: %d\n",funcionario[c].matri);
		    printf("\nNome Do Funcionário:: %s\n",funcionario[c].nomeF);
		    printf("\nStatus Do Funciónario: %s",funcionario[c].status);
		    printf("\nCPF Do Funcionário: : %s\n",funcionario[c].cpf);
		    printf("\nData De Nascimento Do Funcionário:: %d/%d/%d\n",funcionario[c].nasci.dia,funcionario[c].nasci.mes,funcionario[c].nasci.ano);
			//copia os status originais do funcionario    
		    strcpy(copia,funcionario[c].status);
		    }
					printf("\nDigite o Novo Status do Funcionário: ");
					fflush(stdin);
		  			scanf("%s",&mudarStatus->status); 
				// Comparo status originais com o atual 
				if (copia != funcionario[c].status){
					printf("\nStatus Mudado com Sucesso!\n");   
				}
		   
		      	printf("\n Atual Status Do Funcionário : | %s | \n",funcionario[c].status);
		      	
		      	printf("\n   |Deseja Mudar Mais Um Status?|");
		      	printf("\n| Se Sim, Digite '1', Caso Não Digite '0'|\n ");
		      		scanf("%d",&opcaoContinua);
	}while (opcaoContinua != 0);
    
    
  } 
int calcularChequeFunc(){
  
  return  0;
}



int main (){
setlocale(LC_ALL,"portuguese");	
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
                printf ("| 5 - Encerrar o Módulo; | \n");  
                printf ("| | \n");
                printf ("--------------------------------------------------\n");
                  //leitura da opcao 
                    printf ("Digite sua opção:\n");
                    scanf("%d",&opcaoFuncionario);
    
                switch (opcaoFuncionario)
                {
                  
                  
                  
                  case 1:
                    
                    printf("\n|Opção 1 escolida!|\n\n");
                    printf("\n|Cadastro dos Setores|\n");
                      
                          cadastroSetor();
                    
                    do{
                    	printf("\n|Registro de funcionarios|\n");	
                    	
                         cadastrei =  registrarFuncionario(pessoa);
    
                    	if (cadastrei == 1){
                    		printf("\nFuncionário Cadastrado Com Sucesso!\n");
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
                    printf("\n|Opção  3 escolida!|\n\n");
                    
                          exclusaoFuncionario();
                    
                  break;
    
                  case 4:
                    printf("\n|Opção  4 escolida!|\n\n");
                    
                          calcularChequeFunc();
                    
                  break;
    
                  case 5:
                          printf("\n|Módulo De Funcionario Encerrado|\n\n");
                  break;
    
                  default:
                          printf("\n|Opção  Inválida|\n\n");
                  }
              //Fim do "do while"
              }while (opcaoFuncionario != 5);
                break;
            case 2:
                printf("Escolhida a segunda Opção  ! \n");
                break;
            case 3:
                printf("Escolhida a terceira Opção  ! \n");
                break;
            case 4:
                printf("\n|Programa Encerrado|\n");
                break;
            default:
                printf("Opção  inválida !!! \n");
        }
    
    }while (opcao != 4);
    return  0;
}
