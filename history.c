#include "history.h"
#include <stdio.h>
#include <string.h>
#define HIST_SIZE 40
//JUST MAKE A  HISTORY.H AND STUB IT OUT 
//TO RUN DO "make"
//the typr "shell"
//you should test stuff for ls, rm, etc
// TODO: Stuff in here to save and list history

int length = 0;
static char HISTORY[HIST_SIZE][256]; 
void save_history(char* command){
    char in[256];
    char out[256];
    if(length == 39){
            strcpy(out, HISTORY[length - 1]);
            strcpy(HISTORY[length - 1], HISTORY[length]);
            length = length - 2;
        while(length >= 0){
            strcpy(in, out);
            strcpy(out, HISTORY[length]);
            strcpy(HISTORY[length], in);
            length = length - 1;
        }
        length = 39;
        strcpy(HISTORY[length], command);
    } else {
        strcpy(HISTORY[length], command);
        length++;
    }
}

void history_print(){
    int cnt = 0;
    for(;cnt < length; cnt++){
        printf("%d: %s\n", cnt, HISTORY[cnt]);
    }
}
