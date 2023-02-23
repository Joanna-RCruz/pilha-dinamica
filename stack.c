#include <stddef.h>

int push(char *str, char c, size_t size){
    int i=0;
    for(;i<size;i++){
        if(!str[i]){
            str[i] = c;
            return 1;
        }
    } return 0;
}

char pop(char *str, size_t size){
    int i=0;
    for(;i<size;i++){
        if(!str[i]){
            char tmp = str[i-1];
            str[i-1] = 0;
            return tmp;
        }
    }
}