#include "history.h"
#include <stdio.h>
#include <string.h>
#define HIST_SIZE 40
//JUST MAKE A  HISTORY.H AND STUB IT OUT 
//TO RUN DO "make"
//the typr "shell"
//you should test stuff for ls, rm, etc
// Stuff in here to save and list history
/**
 * Saves and print the history of commands
 *
 * @author Brooke Kiser
 * @author Dilon Gorlesky
 */

int length = 0; //global length 
static char HISTORY[HIST_SIZE][256]; //holds the previous commands 

/**
 * Saves the comands history to 
 *
 */
void save_history(char* command){
    char in[256]; //temp for the new value
    char out[256]; //temp holding the old value
    if(length == 40){ // when the history buffer is full, move everything forward
            strcpy(out, HISTORY[length - 2]);
            strcpy(HISTORY[length - 2], HISTORY[length - 1]);
            length = length - 3;
        while(length >= 0){
            strcpy(in, out);
            strcpy(out, HISTORY[length - 1]);
            strcpy(HISTORY[length - 1], in);
            length = length - 1;
        }
        length = 40;
        strcpy(HISTORY[length - 1], command);
    } else {
        strcpy(HISTORY[length - 1], command);
        length++;
    }
}

/**
 * Prints the previous history for commands typed.
 */
void history_print(){
    int cnt = 0;
    for(;cnt < length - 1; cnt++){
        printf("%d: %s\n", cnt, HISTORY[cnt]);
    }
}
