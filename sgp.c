#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

FILE *arquivo;

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
  float salarioLiquido;
}tipoFuncionario;
//DeclaraÃ§Ã£o de uma variavel do tipo Struct
tipoFuncionario funcionario[21];
//Struct de Setores
typedef 
struct setores{
	int codSetor;
	int matriGerente;
	int quantidadeFun;
}tipoSetores;
tipoSetores setor[3];

tipoFuncionario arquivoMorto[20];

//
void lerArquivoParaCogigo(){
	
int posicaoSetor,posicaoFuncionario;
    
    for (posicaoSetor = 0;posicaoSetor < 3;posicaoSetor++){
    	fscanf(arquivo,"\nSetores Cadastrados: %d\n Quantidade de funcionarios em cada setores: %d\n",&setor[posicaoSetor].codSetor,&setor[posicaoSetor].quantidadeFun);
	}	
    
     // colocar todos os Funcionários Registrados Ativos no Arquivo	
    for (posicaoFuncionario = 0;posicaoFuncionario < 22;posicaoFuncionario++){
			
			fscanf(arquivo,"\nSetor Do Funcionário: %d\n",&funcionario[posicaoFuncionario].setorFun);
    		fscanf(arquivo,"\nNome Do Funcionário:: %s\n",&funcionario[posicaoFuncionario].nomeF);
    		fscanf(arquivo,"Matricula: %d \n",&funcionario[posicaoFuncionario].matri);
    		fscanf(arquivo,"Código '%d' Cargo: Funcionário\n",&funcionario[posicaoFuncionario].cargo);
			fscanf(arquivo,"Código '%d' Cargo: Gerente\n",&funcionario[posicaoFuncionario].cargo);
			
            fscanf(arquivo,"CPF: %s \n",&funcionario[posicaoFuncionario].cpf);
            fscanf(arquivo,"Data de nascimento %d/%d/%d \n",&funcionario[posicaoFuncionario].nasci.dia, funcionario[posicaoFuncionario].nasci.mes, funcionario[posicaoFuncionario].nasci.ano);
            fscanf(arquivo,"Estado civil: %s \n",&funcionario[posicaoFuncionario].EsCivil);
            fscanf(arquivo,"Gênero: %s \n",&funcionario[posicaoFuncionario].genero);
            fscanf(arquivo,"Quantidade de filhos menor de idade: %d \n",&funcionario[posicaoFuncionario].filhos);
            fscanf(arquivo,"Salário bruto: %2.f \n",&funcionario[posicaoFuncionario].salarioBruto);
            fscanf(arquivo,"Salário Líquido: %2.f \n",&funcionario[posicaoFuncionario].salarioLiquido);
            fscanf(arquivo,"Status: %s \n",&funcionario[posicaoFuncionario].status);
					
	}//Fim do For
			
	
		// colocar todos os Funcionários Registrados  Desligados 
		for (posicaoFuncionario = 0;posicaoFuncionario < 21;posicaoFuncionario++){
			
				
			fscanf(arquivo,"\nSetor Do Funcionário: %d\n",&arquivoMorto[posicaoFuncionario].setorFun);
    		fscanf(arquivo,"\nNome Do Funcionário:: %s\n",&arquivoMorto[posicaoFuncionario].nomeF);
    		fscanf(arquivo,"Matricula: %d \n", arquivoMorto[posicaoFuncionario].matri);
    		fscanf(arquivo,"Código '%d' Cargo: Funcionário\n",&arquivoMorto[posicaoFuncionario].cargo);
			fscanf(arquivo,"Código '%d' Cargo: Gerente\n",&arquivoMorto[posicaoFuncionario].cargo);			
            fscanf(arquivo,"CPF: %s \n",&arquivoMorto[posicaoFuncionario].cpf);
            fscanf(arquivo,"Data de nascimento %d/%d/%d \n",&arquivoMorto[posicaoFuncionario].nasci.dia, funcionario[posicaoFuncionario].nasci.mes, funcionario[posicaoFuncionario].nasci.ano);
            fscanf(arquivo,"Estado civil: %s \n", arquivoMorto[posicaoFuncionario].EsCivil);
            fscanf(arquivo,"Gênero: %s \n",&arquivoMorto[posicaoFuncionario].genero);
            fscanf(arquivo,"Quantidade de filhos menor de idade: %d \n",&arquivoMorto[posicaoFuncionario].filhos);
            fscanf(arquivo,"Salário bruto: %2.f \n",&arquivoMorto[posicaoFuncionario].salarioBruto);
            fscanf(arquivo,"Salário Líquido: %2.f \n",&arquivoMorto[posicaoFuncionario].salarioLiquido);
            fscanf(arquivo,"Status: %s \n",&arquivoMorto[posicaoFuncionario].status);
			
		}	
	
	
}
//
int ValidaNascimento(tipoNasci nascimento){

	int dia,mes,ano;

	if (nascimento.dia < 1 || nascimento.dia > 31 || nascimento.mes < 1 || nascimento.mes > 12 || nascimento.ano <1920 || nascimento.ano > 2021){
		return -1;
	}else
		return 1;
}
int gcomfirmacao = 0;
int cadastroSetor(int comfirmacao){
  int s;
  	for (s=0;s <3;s++){
  
  		printf("\nDigite o Código do Setor :  ");
		scanf("%d",&setor[s].codSetor);
  
  	}
  	if(s < 3){
	  	return gcomfirmacao = 1; 
	}
}
	
	tipoFuncionario pessoa;
	int f;
	int cadastrei;
	//Variaveis criadas para comparar o genero paraa estatistica e verificação do genero
	char masculino [] = {"masculino"};
	char feminino [] = {"feminino"};
	
int registrarFuncionario(tipoFuncionario func){
	int contador= 0;
	int validoN;
  	int s;
  	int valor;
  	int cpfValida;
  	int reposta;
  	int validaGeneroM,validaGeneroF;
  	
 		 
	do{//repetir ate que o codigo digitado seja igual que o cadastrado   
		do{//repetir ate que o o setor digitado estar com vagas
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
          
        if (valor ==-1  ){
            printf("Setor Não Cadastrado!");
        }//fim do if
        
    	}while (setor[valor].quantidadeFun > 6);
       
    }while (valor == -1);

  	printf("\nDigite o Nome do Funcionario:  ");
    fflush(stdin);
    gets(pessoa.nomeF);
  	printf("\nDigite a Matricula do funcionario:  ");
    scanf("%d",&pessoa.matri);   
	
	do{//Loço de repetição que so para quando o usuario digitar certo	
	printf("\n|Digite '1' Para Funcionário ou '2' Para Gerente|\n");
  	printf("\nDigite o Cargo do Funcionario:  ");
	scanf("%d",&pessoa.cargo);
	//verificação do cargo
	if (pessoa.cargo != 1 && pessoa.cargo != 2){
		printf("\nCargo Inválido!\n");
	}
}while (pessoa.cargo != 1 && pessoa.cargo != 2);
		// validação do do Cargo de Gerente
	      if(pessoa.cargo == 2){
        contador = 0;
        while(contador < 23){
         if(pessoa.setorFun == funcionario[contador].setorFun && pessoa.cargo == funcionario[contador].cargo){
            printf("ERRO* Já Existe Um Gerente Nesse Setor \n");
            printf("\n|Digite '1' Para Funcionário ou '2' Para Gerente|\n");
  	        printf("\nDigite o Cargo do Funcionario:  ");
  		        scanf("%d",&pessoa.cargo);
            contador = 0;
          }else{
          contador++;
          }
        }
      }
	    
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
	
  		printf("\nDigite a Data de Nascimento (dd/mm/aa):   ");
    	scanf("%d/%d/%d",&pessoa.nasci.dia,&pessoa.nasci.mes,&pessoa.nasci.ano);
    // Validação da Data de Nascimento
     	validoN = ValidaNascimento(pessoa.nasci);
    
		if (validoN == -1){
			printf("\nData Inválida! Tente Novamente!\n");
		}
		
	}while (validoN == -1);
	
	  	printf("\nDigite o Estado Civil:  ");
		fflush(stdin);
		gets(pessoa.EsCivil);
	do{// loço de repetição para a validação do genero
	
	  	printf("\nDigite o Gênero: ");
	  	fflush(stdin);
	    gets(pessoa.genero);
	    	strlwr(pessoa.genero);
	    //comparação se é masculino ou feminino	
	    validaGeneroM = strcmp(pessoa.genero,masculino);
	    validaGeneroF = strcmp(pessoa.genero,feminino);
	    //se nao for nehum dos dois ele exibe a mensagem 
	    if (validaGeneroM != 0 && validaGeneroF != 0  ){
	    	printf("\nGênero Incorreto!\n");
		}
	}while(validaGeneroM != 0 && validaGeneroF != 0);
	    
	  	printf("\nDigite quantidade de filhos Menor de idade:  ");
	    scanf("%d",&pessoa.filhos);
	  	printf("\nDigite o Salário Bruto:  ");
	    scanf("%f",&pessoa.salarioBruto);
	  	funcionario[f] = pessoa;	  
	  	f++;
	  	setor[valor].quantidadeFun++;

 		if (setor[valor].quantidadeFun >=7){
    		printf("\n| Não Existem Vagas Nesse Setor! |\n");
		}	
		 
 return  1; 
}

int consultaFuncionario(){

	int matricula_consulta = 0;
  	int k;
  	k = 0;
  	int contador = 0;

		printf("Para a pesquisa digite a matricula do funcionario desejado \n");
	    scanf("%d",&matricula_consulta);
    do{
	
     	while(matricula_consulta != funcionario[contador].matri && contador < 22){
          contador++;
     	}    

        if(matricula_consulta == funcionario[contador].matri){
            printf("\nNome: %s \n", funcionario[contador].nomeF);
            if (funcionario[contador].cargo == 1){
            	printf("Cargo: Funcionário\n");
			}else if (funcionario[contador].cargo == 2){
				printf("Cargo: Gerente\n");
			}
			printf("\nSetor Do Funcionário: %d\n",funcionario[contador].setorFun);	
            printf("Matricula: %d \n", funcionario[contador].matri);
            printf("CPF: %s \n", funcionario[contador].cpf);
            printf("Data de nascimento %d/%d/%d \n", funcionario[contador].nasci.dia, funcionario[contador].nasci.mes, funcionario[contador].nasci.ano);
            printf("Estado civil: %s \n", funcionario[contador].EsCivil);
            printf("Gênero: %s \n", funcionario[contador].genero);
            printf("Quantidade de filhos menor de idade: %d \n", funcionario[contador].filhos);
            printf("Salario bruto: %2.f \n", funcionario[contador].salarioBruto);
            printf("Status: %s \n", funcionario[contador].status);
            k++;
    }
        	if(k == 0){
	          	printf("Funcionario não encontrado \n");
	          	printf("Deseja pesquisar o funcionario novamente? Se sim, digite a matricula, se não, digite 0\n");
	            scanf("%d", &matricula_consulta);
	            contador = 0;
        	} 
        	if(k != 0){
	          	printf("Deseja fazer outra consulta? Se sim, digite a matricula, se não, digite 0 \n");
	            scanf("%d",&matricula_consulta);
	            contador = 0;
	            k = 0;
	        }
  	
}while(matricula_consulta !=0);  
  return  0;  
}

int posicaoFuncionarioExcluido = 0;


void exclusaoFuncionario(){
	
	int s;  
  	int cpfCompara,matriExclusao;
  	int c ;
  	int k = 0;
  	char copia[20];
  	tipoFuncionario *mudarStatus;
	char cpfExclusao[12];  
	int opcaoContinua = 0;
  
	do{ 
		printf("\nDigite o CPf do Funcionário que Deseja Mudar os Status: ");
		fflush(stdin);
		gets(cpfExclusao);
		
		printf("\nDigite a Matrícula do Funcionário : ");
		scanf("%d",&matriExclusao);
	c =0;
	
		while (matriExclusao != funcionario[c].matri && c < 22){
			c++;
		}
		
		//Laço para achar o setor do funcionario que sera excluido
        while (setor[s].codSetor != funcionario[c].setorFun && s < 3){
		    s++;
		}
		if(matriExclusao == funcionario[c].matri){
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
		    k++;
	}
		printf("\nDigite o Novo Status do Funcionário: ");
		fflush(stdin);
		scanf("%s",&mudarStatus->status); 
		// Comparo status originais com o atual 
		if (copia != funcionario[c].status){
			printf("\nStatus Mudado com Sucesso!\n"); 
			arquivoMorto[posicaoFuncionarioExcluido] = funcionario[c];
   			posicaoFuncionarioExcluido++;
			// quando for excluido a matricula sera 0 e a quantidade de funcionarios desse setor sera decrementada
			funcionario[c].matri = 0;
			funcionario[c].setorFun = 0;
			setor[s].quantidadeFun--; 
		}
		// Funcionario excluido vai para a struct de funcionarios desligados
		arquivoMorto[posicaoFuncionarioExcluido] = funcionario[c];
   		posicaoFuncionarioExcluido++;
   		
      	printf("\n Atual Status Do Funcionário : | %s | \n",funcionario[c].status);
      }
      
      	if(k == 0){
      		printf("Funcionario não encontrado \n");
	        printf("Deseja pesquisar o funcionario novamente? Se sim, digite 1, se não, digite 0\n");
	        	scanf("%d",&opcaoContinua);
	        c = 0;
	        k = 0;
		}
		
		if(k != 0){
			printf("Deseja fazer outra exclusão? Se sim, digite 1, se não, digite 0 \n");
			scanf("%d",&opcaoContinua);
			c = 0;
	        k = 0;
		}
      
	}while (opcaoContinua != 0);
}

float calcula_desconto_inss (float sBruto){
    float desconto_inss, desconto_faixa1,desconto_faixa2,desconto_faixa3,desconto_faixa4;
    desconto_faixa1 = 0;
    desconto_faixa2 = 0;
    desconto_faixa3 = 0;
    desconto_faixa4 = 0;
    desconto_inss = 0;

    if(sBruto <= 1212.00){
        desconto_faixa1 = sBruto * 0.075;        
    }  
    if(sBruto > 1212.01 && sBruto <= 2427.35){
        desconto_faixa1 = 1212.00 * 0.075;
        desconto_faixa2 = (sBruto - 1212.00) * 0.09;  
    } 
            
    if(sBruto > 2427.36 && sBruto <= 3641.03){
        desconto_faixa1 = 1212.00 * 0.075;
        desconto_faixa2 = 1215.35 * 0.09;  
        desconto_faixa3 = (sBruto - 1212.00 - 1215.35) * 0.12; 
    } 
             
    if(sBruto > 3641.04 && sBruto <= 7087.22){
        desconto_faixa1 = 1212.00 * 0.075;
        desconto_faixa2 = 1215.35 * 0.09;
        desconto_faixa3 = 1213.68 * 0.12;  
        desconto_faixa4 = (sBruto - 3641.03) * 0.14;
    }      
    
    desconto_inss = desconto_faixa1 + desconto_faixa2 + desconto_faixa3 + desconto_faixa4;

    return desconto_inss;
}


float calcula_desconto_irpf (float sLiquido){
    float aliquota,deducao,desconto_irpf;

    if(sLiquido <= 1903.98) printf("funcionário isento de pagar imposto de renda!");
          
    if(sLiquido >= 1903.99 && sLiquido <= 2826.65){
        aliquota = 0.075;
        deducao = 142.80;
    }       
     
    if(sLiquido >= 2826.66 && sLiquido <= 3751.05){
        aliquota = 0.15; 
        deducao = 354.80;
    }      
     
    if(sLiquido >= 3751.06 && sLiquido <= 4664.68){
        aliquota = 0.225; 
        deducao = 636.13;
    }      
    
    if(sLiquido > 4664.68){
        aliquota = 0.275; 
        deducao = 869.36;
    }      
    desconto_irpf = (sLiquido * aliquota) - deducao;

    return desconto_irpf;
    
}

void calculocontracheque(){
  int k = 0;
  float vale_transporte,desconto_inss,salario_bruto,desconto_irpf,salario_liquido1,total_descontos,salario_liquido_final;
  char nome_funcionario_contracheque[40];
  int voltarModulo,opcao,cargo_funcionario_contracheque,setor_funcionario_contracheque,matricula_consulta,contador;
   matricula_consulta = 0;
  contador = 0;
		                printf("Para a pesquisa digite a matricula do funcionario desejado \n");
	                  scanf("%d",&matricula_consulta);	
	                  
	            do{
                    while(matricula_consulta != funcionario[contador].matri && contador < 22){
                          contador++;
                    }
                    
                    if (matricula_consulta == funcionario[contador].matri){
                              salario_bruto = funcionario[contador].salarioBruto;
                              strcpy(nome_funcionario_contracheque,funcionario[contador].nomeF);
                              cargo_funcionario_contracheque = funcionario[contador].cargo;
                              setor_funcionario_contracheque = funcionario[contador].setorFun;
                    vale_transporte = salario_bruto * 0.06;
                    desconto_inss = calcula_desconto_inss(salario_bruto);                    
                    salario_liquido1 = salario_bruto - desconto_inss;                    
                    desconto_irpf = calcula_desconto_irpf(salario_liquido1);
                    total_descontos = vale_transporte + desconto_inss + desconto_irpf;
                    salario_liquido_final = salario_bruto - total_descontos;
					funcionario[contador].salarioLiquido = salario_liquido_final;
                    printf("\n\n");
                    printf ("----------------------------------------------------------\n");
                    printf ("| TST - Desenvolvimento de Sistemas                      |\n");
                    printf ("| CNPJ: 78.965.365/0001-35                               |\n");
                    printf ("----------------------------------------------------------\n");
                    printf ("Nome: %s \n",nome_funcionario_contracheque);
                    printf ("Cargo: %i \n",cargo_funcionario_contracheque);
                    printf ("Setor: %i \n",setor_funcionario_contracheque);
                    printf ("----------------------------------------------------------\n"); 
                    printf ("| Descrição                 |     Vencimentos            |\n");
                    printf ("----------------------------------------------------------\n"); 
                    printf ("|HORAS NORMAIS                          %.2f          |\n",salario_bruto); 
                    printf ("----------------------------------------------------------\n");
                    printf ("|Total Vencimentos                      %.2f          |\n",salario_bruto);    
                    printf ("----------------------------------------------------------\n"); 
                    printf ("| Descrição                 |     Descontos              |\n");
                    printf ("----------------------------------------------------------\n");                    
                    printf ("INSS                                    %.2f           |\n",desconto_inss);       
                    printf ("IRPF                                    %.2f           |\n",desconto_irpf);        
                    printf ("Vale transporte                         %.2f           |\n",vale_transporte);
                    printf ("----------------------------------------------------------\n"); 
                    printf ("Total descontos                         %.2f           |\n",total_descontos);                    
                    printf ("---------------------------------------------------------|\n"); 
                    printf ("Salário Liquido                         %.2f          |\n",salario_liquido_final);                    
                    printf ("---------------------------------------------------------|\n");
                    printf ("Salário base:                           %.2f          |\n",salario_bruto);                    
                    printf ("---------------------------------------------------------|\n");  
                    printf ("Salário base INSS:                      %.2f          |\n",salario_bruto); 
                    printf ("---------------------------------------------------------|\n");
                    printf ("Salário base IRPF:                      %.2f          |\n",salario_liquido1); 
                    printf ("---------------------------------------------------------\n");   
				k++;                   
				}
				if(k == 0){
					printf("Funcionario não encontrado \n");
	          	    printf("Deseja pesquisar o funcionario novamente? Se sim, digite a matricula, se não, digite 0\n");
	                scanf("%d", &matricula_consulta);
	                contador = 0;
	                k = 0;
				}
				if(k != 0){
	          	printf("Deseja cálcular novamente? Se sim, digite a matricula, se não, digite 0 \n");
	            scanf("%d",&matricula_consulta);
	            contador = 0;
	                k = 0;
	            }
		}while(matricula_consulta !=0);
}



void folhaPagamento(){
	
	int setorFolhaPagamento;
	int posicaoFPagamento ;
	int opcaoFolhaPagamento;
	
	printf("\n|Folha de Pagamento|\n");
	printf("|----------------------------------\n");
	printf("|1 - |Folha de Pagamento Geral;|\n");
	printf("|----------------------------------\n");
	printf("|2 - |Folha de Pagamento por Setor|\n;");
	printf("|----------------------------------\n");
	scanf("%d",&opcaoFolhaPagamento);
	switch (opcaoFolhaPagamento)
{	
	case 1:
		printf("\n|Folha de Pagamento Geral|\n");
		for (posicaoFPagamento = 0;posicaoFPagamento < 22;posicaoFPagamento++){
			if (funcionario[posicaoFPagamento].matri != 0 && funcionario[posicaoFPagamento].setorFun != 0){
			printf("-------------------------------\n");
			printf("|Setor Do Funcionário : %d\n|",funcionario[posicaoFPagamento].setorFun);
			printf("-------------------------------\n");
			printf("|Nome Do Funcionário: %s\n|",funcionario[posicaoFPagamento].nomeF);
			printf("-------------------------------\n");
			printf("|Matricula Do Funcionário: %d\n|",funcionario[posicaoFPagamento].matri);
			printf("-------------------------------\n");
			printf("|Salário Líquido : %2.f\n|",funcionario[posicaoFPagamento].salarioLiquido);
			printf("-------------------------------\n");
			printf("\n____________________________________\n");
			}//Fim do 'if'	
		}//Fim do 'For"
		break;
		
		case 2:
			printf("\n|Folha de Pagamento Por Setor|\n");
			printf("Digite o Setor Que Deseja a Folha de Pagamento: ");
			scanf("%d",&setorFolhaPagamento);
			
		for (posicaoFPagamento = 0;posicaoFPagamento < 22;posicaoFPagamento++){
			if (funcionario[posicaoFPagamento].matri != 0 && funcionario[posicaoFPagamento].setorFun != 0 && funcionario[posicaoFPagamento].setorFun == setorFolhaPagamento ){
			printf("-------------------------------\n");
			printf("|Setor Do Funcionário : %d\n|",funcionario[posicaoFPagamento].setorFun);
			printf("-------------------------------\n");
			printf("|Nome Do Funcionário: %s\n|",funcionario[posicaoFPagamento].nomeF);
			printf("-------------------------------\n");
			printf("|Matricula Do Funcionário: %d\n|",funcionario[posicaoFPagamento].matri);
			printf("-------------------------------\n");
			printf("|Salário Líquido : %2.f\n|",funcionario[posicaoFPagamento].salarioLiquido);
			printf("-------------------------------\n");
			printf("\n____________________________________\n");
			}//Fim do 'if'	
		}//Fim do 'For"
			
		break;
		}
}

 int analise_global(){
	int qmasculino, qfeminino, qfilho, qsalario, qidade;
	float porcent_homem, porcent_mulher, porcent_filho, porcent_salario, porcent_idade;	
	//Variavel criada para receber o retorno da funçaõ que compara 
	int GeneroM;
	int GeneroF;	
	char S = {'%'};
	int i = 0;
	qmasculino=0;
	qfeminino=0;
	qfilho=0;
	qsalario=0;
	qidade=0;

  while(i<f){
  	//função que deixa as letras do genero todas minusculas
  	strlwr(funcionario[i].genero);
  	//função que compara o genero cadastrado com o genero masculino da variavel
  	//quando retorna 0 é porque aelas são iguais
  	GeneroM = strcmp(funcionario[i].genero,masculino);
	  if(GeneroM == 0){
		  qmasculino++;
		  }
	  //função que compara o genero cadastrado com o genero feminino da variavel
	  //quando retorna 0 é porque aelas são iguais
	GeneroF = strcmp(funcionario[i].genero,feminino);
	   if(GeneroF == 0){
		  qfeminino++;		  
	  }
	  if(funcionario[i].filhos > 0){
		  qfilho++;
	  }
	  if(funcionario[i].salarioBruto > 2200){
		  qsalario++;
	  }
	  if(funcionario[i].nasci.ano < 1987){
		  qidade++;
	  }
	  i++;
  	}

	  porcent_homem = (((float)qmasculino/f) * 100);
	  porcent_mulher= (((float)qfeminino/f) * 100);
	  porcent_filho = (((float)qfilho/f) * 100);
	  porcent_salario = (((float)qsalario/f) * 100);
	  porcent_idade = (((float)qidade/f) * 100);

		printf("ESTATÍSTICAS DISPONÍVEIS: \n");
		printf("------------------------------ \n");
		printf("Porcentagem de homens: %2.f%c \n",porcent_homem,S);
		printf("Porcentagem de mulheres: %2.f%c \n",porcent_mulher,S);
		printf("Porcentagem de funcionários que possuem filhos: %2.f%c  \n",porcent_filho,S);
		printf("Porcentagem de funcinários que recebem mais que 2/dois salários mínimo: %2.f%c \n",porcent_salario,S);
		printf("Porcentagem de funcionários que possuem idade maior que 35 anos: %2.f%c \n",porcent_idade,S);
}

//Função de jogar Tudo que tem na memoria para o Arquivo
void copiaDadosParaArquivo(){
char tituloMorto[] = "Funcionários No Aquivo Morto";
char tituloAtivo[] = "Funcionários Ativos";	

int posicaoSetor,posicaoFuncionario;
    
    for (posicaoSetor = 0;posicaoSetor < 3;posicaoSetor++){
    	fprintf(arquivo,"\nSetores Cadastrados: %d\n Quantidade de funcionarios em cada setores: %d\n",setor[posicaoSetor].codSetor,setor[posicaoSetor].quantidadeFun);
	}	
    	fprintf(arquivo,"\n\n%s\n\n",tituloAtivo);
     // colocar todos os Funcionários Registrados Ativos no Arquivo	
    for (posicaoFuncionario = 0;posicaoFuncionario < 22;posicaoFuncionario++){
		if (funcionario[posicaoFuncionario].matri != 0 && funcionario[posicaoFuncionario].setorFun != 0){
			
			fprintf(arquivo,"\nSetor Do Funcionário: %d",funcionario[posicaoFuncionario].setorFun);
    		fprintf(arquivo,"\nNome Do Funcionário:: %s\n",funcionario[posicaoFuncionario].nomeF);
    		fprintf(arquivo,"Matricula: %d \n", funcionario[posicaoFuncionario].matri);
    		if (funcionario[posicaoFuncionario].cargo == 1){
            	fprintf(arquivo,"Código '%d' Cargo: Funcionário\n",funcionario[posicaoFuncionario].cargo);
			}else if (funcionario[posicaoFuncionario].cargo == 2){
				fprintf(arquivo,"Código '%d' Cargo: Gerente\n",funcionario[posicaoFuncionario].cargo);
			}
            fprintf(arquivo,"CPF: %s \n", funcionario[posicaoFuncionario].cpf);
            fprintf(arquivo,"Data de nascimento %d/%d/%d \n", funcionario[posicaoFuncionario].nasci.dia, funcionario[posicaoFuncionario].nasci.mes, funcionario[posicaoFuncionario].nasci.ano);
            fprintf(arquivo,"Estado civil: %s \n", funcionario[posicaoFuncionario].EsCivil);
            fprintf(arquivo,"Gênero: %s \n", funcionario[posicaoFuncionario].genero);
            fprintf(arquivo,"Quantidade de filhos menor de idade: %d \n", funcionario[posicaoFuncionario].filhos);
            fprintf(arquivo,"Salário bruto: %2.f \n", funcionario[posicaoFuncionario].salarioBruto);
            fprintf(arquivo,"Salário Líquido: %2.f \n",funcionario[posicaoFuncionario].salarioLiquido);
            fprintf(arquivo,"Status: %s \n\n", funcionario[posicaoFuncionario].status);
		}//Fim do if			
	}//Fim do For
			
		fprintf(arquivo,"\n\n%s\n\n",tituloMorto);
		// colocar todos os Funcionários Registrados  Desligados 
		for (posicaoFuncionario = 0;posicaoFuncionario < 21;posicaoFuncionario++){
			if (arquivoMorto[posicaoFuncionario].matri != 0 && arquivoMorto[posicaoFuncionario].setorFun != 0){
				
			fprintf(arquivo,"\nSetor Do Funcionário: %d\n",arquivoMorto[posicaoFuncionario].setorFun);
    		fprintf(arquivo,"\nNome Do Funcionário:: %s\n",arquivoMorto[posicaoFuncionario].nomeF);
    		fprintf(arquivo,"Matricula: %d \n", arquivoMorto[posicaoFuncionario].matri);
    		if (arquivoMorto[posicaoFuncionario].cargo == 1){
            	fprintf(arquivo,"Código '%d' Cargo: Funcionário\n",funcionario[posicaoFuncionario].cargo);
			}else if (arquivoMorto[posicaoFuncionario].cargo == 2){
				fprintf(arquivo,"Código '%d' Cargo: Gerente\n",arquivoMorto[posicaoFuncionario].cargo);
			}
            fprintf(arquivo,"CPF: %s \n", arquivoMorto[posicaoFuncionario].cpf);
            fprintf(arquivo,"Data de nascimento %d/%d/%d \n", arquivoMorto[posicaoFuncionario].nasci.dia, funcionario[posicaoFuncionario].nasci.mes, funcionario[posicaoFuncionario].nasci.ano);
            fprintf(arquivo,"Estado civil: %s \n", arquivoMorto[posicaoFuncionario].EsCivil);
            fprintf(arquivo,"Gênero: %s \n", arquivoMorto[posicaoFuncionario].genero);
            fprintf(arquivo,"Quantidade de filhos menor de idade: %d \n",arquivoMorto[posicaoFuncionario].filhos);
            fprintf(arquivo,"Salário bruto: %2.f \n",arquivoMorto[posicaoFuncionario].salarioBruto);
            fprintf(arquivo,"Salário Líquido: %2.f \n",arquivoMorto[posicaoFuncionario].salarioLiquido);
            fprintf(arquivo,"Status: %s \n",arquivoMorto[posicaoFuncionario].status);
			}
		}		
}//Fim da Função 
int main (){
arquivo = fopen("arquivo.txt","w");	
lerArquivoParaCogigo();
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
                    if (gcomfirmacao == 0){
                    printf("\n|Cadastro dos Setores|\n");
                      	
                          gcomfirmacao = cadastroSetor(gcomfirmacao);
                    	}
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
                          calculocontracheque();
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
                
                		folhaPagamento();
                break;
            case 3:
                printf("Escolhida a terceira Opção  ! \n");
                
                	analise_global();
                break;
            case 4:
                printf("\n|Programa Encerrado|\n");
                break;
            default:
                printf("Opção  inválida !!! \n");
        }
    
    }while (opcao != 4);
   	
   	copiaDadosParaArquivo();
   	
    fclose(arquivo);
    return  0;
}
