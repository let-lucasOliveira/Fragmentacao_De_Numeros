#include <stdio.h>
#include <math.h>

/***********************************************
Fatec Santana de Parnaíba
Linguagem de Programação
Grupo:
João Victor Barreto Galvão
Lucas Nascimento Ramos de Oliveira
***********************************************/


//Funções
/*
Sobre funções:
  Para diferenciar os nomes de funções de variáveis, iniciar com "func..." exm: "funcSaberSePrimo".
  Para diferenciar os parâmetro de funções de variáveis, iniciar com "ex..." exm: "exNum1".
*/

//Função de identificar números primos
int funcPrimo(int exSaberSePrimo) {
  int exAux2 = exSaberSePrimo;
  int exAux = 0;

  for(int o = 2; o < exAux2; o++){
    if(exAux2 % o == 0){
      exAux++;
    };
  }

  if(exAux == 0){
    return 1;
  }else{
    return 0;
  }
}

//Função apenas para contar a quantidade de digitos que uma variável possui, como um sizeof.
//PSC: Caso o numero não precisasse cortar o zero esquerda, o "exDigitos" deveria começar com 1.
int funcContaDigitos(int exNum) {
  int exDigitos = 0;
  for(; exNum > 0; exNum /= 10){
    exDigitos++;
  }
  return exDigitos;
}

//Função de fragmentação
int funcFragmentacao(int exNum1, int exNum2){
  int exDigitosNum1 = funcContaDigitos(exNum1);
  int exPotenciaDe10 = pow(10, exDigitosNum1);
  
  for(int exTempNum2 = exNum2; exTempNum2 >= exNum1; exTempNum2 /= 10){
    int exFragmento = exTempNum2 % exPotenciaDe10;
    if(exFragmento == exNum1){
      return 1;
    }
  }
  return 0;
}

//Função para somar dois numeros
int funcSomar(int exNum1, int exNum2){
  int exResult = exNum1 + exNum2;
  return exResult;
}

//Função de somar os indices com base se o numero correspondente é par.
int funcSomaIndices_par(int exNum1, int exNum2){
  int exSomaN1N2 = funcSomar(exNum1,exNum2);
  int exIndicesPar = 0;
  
  for(int i = funcContaDigitos(exSomaN1N2); exSomaN1N2 > 0; i--){
    if(i % 2 == 0){
      exIndicesPar += exSomaN1N2 % 10;
    };
    exSomaN1N2 /= 10;
  };
  return exIndicesPar;
}

//Função de somar os indices com base se o numero correspondente é par.
//OBS: Nesse exemplo o indice começa com 1 ao invés dos padrões matemáticos, 0.
int funcSomaIndices_impar(int exNum1, int exNum2){
  int exSomaN1N2 = funcSomar(exNum1,exNum2);
  int exIndicesImpar = 0;
  
  for(int i = funcContaDigitos(exSomaN1N2); exSomaN1N2 > 0; i--){
    if(i % 2 > 0){
      exIndicesImpar += exSomaN1N2 % 10;
    };
    exSomaN1N2 /= 10;
  };
  return exIndicesImpar;
}

//Função que tem como proposito inverter os numeros da soma, por exemplo se for 12, o retorno seria 21.
int funcInversao(int exSomaN1N2){
  int exCopy = exSomaN1N2;
  int exQntDigito = funcContaDigitos(exSomaN1N2);
  int exDigitoInverso = 0;
  int exResultInverso = 0;
  
  for(int i = 0; i < exQntDigito; i++){
    exDigitoInverso = exCopy % 10;
    exResultInverso = exResultInverso * 10 + exDigitoInverso;
    exCopy /= 10;
  }
  return exResultInverso;
}

//--------------------------------------------------------------------------------------------------------------

//Inicio do programa
int main(void) {
  int num1;
  int num2;
  int soma;

  printf("Digite um numero \n");
  scanf("%d",&num1);

  if(num1 < 0){
    for(; num1 < 0;){//Gambiarra pra impedir o usuário a digitar valor < 0
      printf("Voce digitou um numero menor que 0! Digite um numero maior ou igual a zero!\n");
      scanf("%d", &num1);
    };
  };

  printf("Digite outro numero \n");
  scanf("%d",&num2);

  if(num2 < 0){
    for(; num2 < 0;){
      printf("Voce digitou um numero menor que 0! Digite um numero maior ou igual a zero!\n");
      scanf("%d", &num2);
    };
  };
  
    int fragmentacao = funcFragmentacao(num1, num2);
    int somaN1N2 = funcSomar(num1, num2);
    int soma_pares = funcSomaIndices_par(num1, num2);
    int soma_impares = funcSomaIndices_impar(num1, num2);
    int resultPrimo = funcPrimo(somaN1N2);

  if(num1 < num2){//Solução B
    printf("\nSolução B:\n");
    if(fragmentacao){
      printf("O numero %d eh um fragmento de %d\n", num1, num2);
    }else{
      printf("O numero %d nao eh um fragmento de %d\n", num1, num2);
    };
  }
  else{//Negação do B
    if(resultPrimo){//Solução C i
      printf("\nSolução C i:\n");
      printf("A soma dos numeros deu %d.\nSoma dos indices par: %d\nSoma dos indices impar: %d\n", somaN1N2, soma_pares, soma_impares);
    }else{//Negação do C i
      if(somaN1N2 % 2 == 0){//Solução C ii
      printf("\nSolução C ii:\n");
        //Inverter o valor da somaN1N2
        int somaN1N2inversa = funcInversao(somaN1N2);
        printf("O resultado da soma dos numeros %d e %d deu %d\nA inversao desses numeros fica: %d", num1, num2, somaN1N2, somaN1N2inversa);
      }else{//Soluçao C iii
        printf("\nSolução C iii:\n");
        //Mostrar os divisores da somaN1N2
        printf("Os divisores de %d sao: ", somaN1N2);
        for(int divAux = 1; divAux <= somaN1N2; divAux++){
          if(somaN1N2 % divAux == 0){
            printf("%d | ", divAux);
          };
        }
      }
    }
  }
}