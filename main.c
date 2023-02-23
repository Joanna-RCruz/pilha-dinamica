/*(Pilha Dinâmica) Uma pilha pode ser usada para rastrear os tipos de escopos encontrados numa
expressão matemática e verificar se o uso deles está correto. Os delimitadores de escopos podem
ser os parênteses, os colchetes e as chaves. Escreva um programa que leia uma expressão
matemática e verifique se os escopos estão posicionados de forma correta.*/


#include <stdio.h>
#include <string.h>
#include "stack.h"

int checkscope(const char *input, char *stack){
    int i=0;
    for(;i<strlen(input);i++){
        printf("%s\n", stack);
        
        if(input[i] == '(' || input[i] == '{' || input[i] == '['){
            push(stack, input[i], 256);
        }
        
        if(input[i] == ')' || input[i] == '}' || input[i] == ']'){
            char tmp = pop(stack, 256);
            switch(tmp){
                case '(':
                    if(input[i] != ')') return -1;
                    break;
                
                case '{':
                    if(input[i] != '}') return -1;
                    break;
                
                case '[':
                    if(input[i] != ']') return -1;
                    break;
                
                default:
                    return -2;
            }
        }
    }
    return 0;
}

int main(){
    char stack[256];
    
    const char *eval = "((){[]({})})";
    
    printf("%d", checkscope(eval, stack));

    return 0;
}
