#include "shell.h"
#include "history.h"
#include <sys/stat.h>

/**
 * do_file_list
 *
 * Implements a built-in version of the 'ls' command.
 *
 * args - An array of strings corresponding to the command and its arguments.
 *        If args[1] is NULL, the current directory (./) is assumed; otherwise
 *        it specifies the directory to list.
 */
void do_file_list(char** args) {
    DIR *d;//Pointer to DIR type
    struct dirent *dir;
    if(args[1] == NULL){//Current directory
        d = opendir(".");
        if(d == NULL){
            printf("Could not open current directory.\n");
            exit(0);
        }

        while((dir = readdir(d)) != NULL){
            printf("%s\n", dir->d_name);
        }
        closedir(d);


    } else {//Not current directory
    //.. represents parent directory
        d = opendir("..");
        if(d == NULL){
            printf("Could not open current directory.\n");
            exit(0);
        }

        while((dir = readdir(d)) != NULL){
            printf("%s\n", dir->d_name);
        }
        closedir(d);

    }
}

/**
 * do_file_remove
 *
 * Implements a built-in version of the 'rm' command.
 *
 * args - An array of strings corresponding to the command and its arguments.
 *        args[0] is "rm", additional arguments are in args[1] ... n.
 *        args[x] = NULL indicates the end of the argument list.
 */
void do_file_remove(char** args) {
    
    int n = 1;                                                               
    // unlink system call
    if(args[n] != NULL){
        while(args[n] != NULL){
            unlink(args[n]);
            n++;
        }
    }else {
        printf("Usage: rm <file 1> <file 2> ...\n");
   }
}


/**
 * do_touch
 *
 * Implements a built-in version of the 'touch' command.
 *
 * args - An array of strings corresponding to the command and its arguments.
 *        args[0] is "touch", additional arguments are in args[1] ... n.
 *        args[x] = NULL indicates the end of the argument list.
 */
void do_touch(char** args) {
    /*                                                                          
     * TODO: Write code here that will modify the access time of a file(s) if it exists, or create
     * the file(s) if it/they does not exist.  If no file list is specified, print a usage message.
     */       
    int n =1;                                                                  
    struct stat statbuf;
    if(args[n] != NULL){
        while(args[n] != NULL){
            if(stat(args[n], &statbuf) == -1){
                open(args[n], O_CREAT, 0600);
            } else {
                utime(args[n], NULL);
            }
            n++;
        }
    } else {
        printf("touch <file_name_1> <file_name_2> ...\n");
    }







}
/**
 * do_history
 *
 * Implements a built-in version of the 'history' command. This will just list the command in the
 * form:
 *  0: command
 *  1: command
 *  2: command
 *
 * args - An array of strings corresponding to the command and its arguments.
 *        args[0] is "history", additional arguments are in args[1] ... n.
 *        args[x] = NULL indicates the end of the argument list.
 */
void do_history(char** args) {
    history_print();




}
