#include "shell.h"

/*
 * append_redirection
 *
 * Redirects the standard output of this process to append to the file with the specified name.
 *
 * filename - the name of the file to which to append our output
 */
void append_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard output of this process to be sent to a file with
     * the specified name.  The output should be appended to the file if the file already exists.
     */
    int i = 0;
    int stdout_copy = dup(1);
    char buffer[100];
    close(1);//Closes stdout

    int fd = open(filename, O_RDWR | O_CREAT | O_APPEND);//Assigns this file desc to 1 since its lowest open
    if(fd < 0){
        printf("Unable to open '%s' file.\n", filename);
        printf("Please check whether the file exists and you have write privilege.\n");
        close(fd);
        dup2(stdout_copy, 1);
        exit(EXIT_FAILURE);
    }
    read(0, buffer, 100);
    write(fd, buffer, 100);

    close(fd);
//May need to open it, or may not. I need print statements somewhere to see if its actually
//doing what i want or if its actually correct. If the process lives for a while after
//this i dont want to restore it right away but maybe when it dies?
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
    int stdout_copy = dup(1);
    char buffer[100];
    read(stdout_copy, buffer, 100);
    close(1);

    int fd = open(filename, O_TRUNC | O_WRONLY | O_CREAT);
    if(fd < 0){
        printf("Couldn't open file.\n");
        close(fd);
        dup2(stdout_copy, 1);
        exit(EXIT_FAILURE);
    }

    write(fd, buffer, 100);
    
    close(fd);
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
    int stderr_copy = dup(2);
    close(2);
    char buffer[100];
    int fd = open(filename, O_TRUNC | O_WRONLY | O_CREAT);
    if(fd < 0){
        printf("Couldn't write to file.\n");
        close(fd);
        dup2(stderr_copy, 2);
        exit(EXIT_FAILURE);
    }
    read(1, buffer, 100);
    write(fd, buffer, 100);
    
    close(fd);

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
    int stdout_copy = dup(1);
    int stderr_copy = dup(2);
    close(1);
    close(2);
    int fd = open(filename, O_TRUNC | O_CREAT | O_WRONLY);
    dup2(fd, stderr_copy);
    if(fd < 0){
        printf("Couldn't redirect stdout and stderr.\n");
        close(fd);
        dup2(stdout_copy, 1);
        dup2(stderr_copy, 2);
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
    char buffer[100];
    int stdin_copy = dup(0);
    close(0);
    int fd = open(filename, O_RDONLY );
    if(fd < 0){
        printf("Could not redirect stdin.\n");
        close(fd);
        dup2(stdin_copy, 0);
        exit(EXIT_FAILURE);
    }
    
    read(0, buffer, 100);
    
}

