#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void limpar_buffer(void){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    char accept = 's';

    do{
    printf("===============================\n");
    printf("     Calculadora Simples\n");
    printf("===============================\n");
    printf("Selecione uma operação: \n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair\n");
    printf("Opção: ");

    int op,ok;
    float first_number,second_number,value;
    char c;

    ok = scanf("%d", &op);
    limpar_buffer();

    while(ok != 1 || op < 1 || op > 5){
        printf("Entrada não aceita, por favor tente novamente\n");

        printf("Selecione uma operação: \n");
        printf("1. Adição\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Sair\n");
        printf("Opção: ");

        ok = scanf("%d", &op);   // precisa do "ok ="
        limpar_buffer();
    }

    if(op == 5){
        accept = 'n';
        printf("Obrigado por usar a calculadora! Até a próxima.");
        break;
    }

    printf("Digite o primeiro número: ");
    scanf("%f",&first_number);
    printf("Digite o segundo número: ");
    scanf("%f",&second_number);

    switch(op){
        case 1:
            value = first_number + second_number;
            c = '+';
        break;
        case 2:
            value = first_number - second_number;
            c = '-';
        break;
        case 3:
            value = first_number * second_number;
            c = '*';
        break;
        case 4:
            if(first_number == 0 || second_number == 0){
                while(first_number == 0 || second_number == 0){
                    if(accept == 'n' || accept == 'N'){
                        break;
                    }
                    printf("Erro: Divisão por zero não é permitida.\n");

                    accept = 'a';
                    while(accept != 's' && accept != 'S' && accept != 'n' && accept != 'N'){
                        printf("Deseja realizar outra operação? (s/n): ");
                        scanf(" %c",&accept);
                        if(accept == 's' || accept == 'S'){
                            printf("Digite o primeiro número: ");
                            scanf("%f",&first_number);
                            printf("Digite o segundo número: ");
                            scanf("%f",&second_number);
                        }
                        else if(accept == 'n' || accept == 'N'){
                            accept = 'n';
                            printf("Obrigado por usar a calculadora! Até a próxima.");
                            break;
                        }
                        else{
                            printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
                        }
                }
                }
            }
            value = first_number / second_number;
            c = '/';
        break;
    }
    if(accept == 'n' || accept == 'N'){
        break;
    }
    printf("Resultado: %f %c %f = %f\n",first_number, c, second_number, value);

    accept = 'a';

    while(accept != 's' && accept != 'S' && accept != 'n' && accept != 'N'){
        printf("Deseja realizar outra operação? (s/n): ");
        scanf(" %c",&accept);
        if(accept == 's' || accept == 'S'){
            system("cls"); 
        }
        else if(accept == 'n' || accept == 'N'){
            printf("Obrigado por usar a calculadora! Até a próxima.");
        }
        else{
            printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
        }
    }

} while(accept == 's' || accept == 'S');

    //printf("%d",X);
}