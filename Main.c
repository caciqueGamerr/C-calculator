#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpar_buffer(){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

float ler_numero(char mensagem[]){
    float n;
    int ok;
    char next;

    printf("%s", mensagem);
    ok = scanf("%f", &n);
    next = getchar();

    while(ok != 1 || next != '\n'){
        if(next != '\n'){
            limpar_buffer();
        }
        printf("Entrada inválida. %s", mensagem);
        ok = scanf("%f", &n);
        next = getchar();
    }
    return n;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    setlocale(LC_NUMERIC, "C");

    char accept = 's';
    int op, ok, erro;
    float first_number, second_number, value;
    char c, next;

    do{
        erro = 0;                   // zera a cada volta

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

        ok = scanf("%d", &op);
        next = getchar();

        while(ok != 1 || next != '\n' || op < 1 || op > 5){
            if(next != '\n'){
                limpar_buffer();
            }
            printf("Entrada não aceita, por favor tente novamente\n");
            printf("Opção: ");
            ok = scanf("%d", &op);
            next = getchar();
        }

        if(op == 5){
            break;
        }

        first_number = ler_numero("Digite o primeiro número: ");
        second_number = ler_numero("Digite o segundo número: ");

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
                if(second_number == 0){
                    printf("Erro: Divisão por zero não é permitida.\n");
                    erro = 1;       // marca o erro
                }
                else{
                    value = first_number / second_number;
                    c = '/';
                }
            break;
        }

        if(erro == 0){
            printf("Resultado: %f %c %f = %f\n", first_number, c, second_number, value);
        }

        accept = 'a';
        while(accept != 's' && accept != 'S' && accept != 'n' && accept != 'N'){
            printf("Deseja realizar outra operação? (s/n): ");
            scanf("%c", &accept);
            next = getchar();
            if(next != '\n'){
                limpar_buffer();
                accept = 'a';
            }
            if(accept == 's' || accept == 'S'){
                system("cls");
            }
            else if(accept == 'n' || accept == 'N'){
                break;
            }
            else{
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
            }
        }

    } while(accept == 's' || accept == 'S');

    printf("Obrigado por usar a calculadora! Até a próxima.\n");
    return 0;
}