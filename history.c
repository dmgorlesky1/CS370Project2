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
    char* in;
    char* out;
    printf("SAVE   %s\n", command);
    if(length == 39){
            out = HISTORY[length - 1];
            strcpy(HISTORY[length - 1], HISTORY[length]);
            length = length - 2;
        while(length != 0){
            in = out;
            out = HISTORY[length];
            strcpy(HISTORY[length], in);
            length = length - 1;
        }
        length = 39;
        strcpy(HISTORY[length], command);
    } else {
        strcpy(HISTORY[length], command);
        printf("ELSE  %d   %s\n",length, HISTORY[length]);
        length++;
    }
    printf("HISTORY   %d   %s\n", length, HISTORY[length - 1]);
}

void history_print(){
    printf("PRINT   %d\n", length);
    int cnt = 0;
    for(;cnt < length; cnt++){
        printf("HERE\n");
        printf("%d: %s\n", cnt, HISTORY[cnt]);
    }
}
