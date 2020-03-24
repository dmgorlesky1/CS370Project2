#include "shell.h"
/**
 *Modified By:
 * @Author Dillon Gorlesky
 * @Author Brooke Kriser
 * The purpose of this class is to hold any possible redirecting of outputs
 *      (stdout, stderr, stdin) to their appropriate destinations.
 * @Date 3/23/2020
 */ 



/*
 * append_redirection
 *
 * Redirects the standard output of this process to append to the file with the specified name.
 *
 * filename - the name of the file to which to append our output
 */
void append_redirection(char* filename) {
    /*
     * Write code to cause the standard output of this process to be sent to a file with
     * the specified name.  The output should be appended to the file if the file already exists.
     */

    close(STDOUT_FILENO);//Closes stdout

    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0600);//Assigns this file desc to 
                                        //1 since its lowest open
    if(fd < 0){
        printf("Unable to open '%s' file.\n", filename);
        exit(EXIT_FAILURE);
    }
}

/*
 * stdout_redirection
 *
 * Redirects the standard output of this process to overwrite the file with the specified name.
 *
 * filename - the name of the file which to overwrite
 */
void stdout_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard output of this process to be sent to a file with
     * the specified name.  If the file already exists, its contents should be truncated before
     * this process writes to the file.
     */

    close(STDOUT_FILENO);

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0640);
    if(fd < 0){
        printf("Unable to open '%s' file.\n", filename);
        exit(EXIT_FAILURE);
    }
}
/*
 * stderr_redirection
 *
 * Redirects the standard error of this process to overwrite the file with the specified name.
 *
 * filename - the name of the file which to overwrite
 */
void stderr_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard error of this process to be sent to a file with the
     * specified name.  If the file already exists, its contents should be truncated before this
     * process writes to the file.
     */
    close(STDERR_FILENO);

    int fd = open(filename, O_TRUNC | O_WRONLY | O_CREAT, 0640);
    if(fd < 0){
        printf("Unable to open '%s' file.\n", filename);
        exit(EXIT_FAILURE);
    }
}

/*
 * stdout_stderr_redirection
 *
 * Redirects the standard output AND standard error of this process to overwrite the file with the
 * specified name.
 *
 * filename - the name of the file which to overwrite
 */
void stdout_stderr_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard output and standard error of this process to be
     * sent to a file with the specified name.  If the file already exists, its contents should be
     * truncated before this process writes to the file.
     */
    stderr_redirection(filename);
    close(STDOUT_FILENO);

    int fd = open(filename, O_WRONLY | O_APPEND, 0640);
    if(fd < 0){
        printf("Couldn't redirect stdout.\n");
        exit(EXIT_FAILURE);
    }
}
/*
 * stdin_redirection
 *
 * Redirects the standard input to this process from the file with the specified name.
 *
 * filename - the name of the file from which to read as standard input.
 */
void stdin_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard input of this process to be read from a file with
     * the specified name.
     */
    close(STDIN_FILENO);

    int fd = open(filename, O_RDONLY);
    if(fd < 0){
        printf("Could not redirect stdin.\n");
        exit(EXIT_FAILURE);
    }
}

