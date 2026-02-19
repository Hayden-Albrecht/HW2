#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main (int argc, char *argv[]){
    pid_t pid;

for (int i =0; i<4; i++){ //create child processes
    pid = fork();
    if (pid < 0){ //if for fork failure
        printf ("Fork failed.\n");
        return 1;
    } else if (pid == 0){ // if for fork success
    printf("Coordinator: forked with process ID: %d.\n",getpid());
    printf("Coordinator: waiting for process [%d].\n", getpid());
    char *args[] = {"./checker", argv[1], argv[2+i], NULL}; //Char array for passing args to checker
    execv(args[0], args);
   perror("execv"); //if a failure occurs trying to access checker
    exit(2);
    }else {
        int status;
        wait(&status); // tells parent to wait for child process to complete
        int result = WEXITSTATUS(status);
        printf("Coordinator: child process %d exited with status %d.\n", getpid(), result); 
    }
}
for (int i = 0; i<4; i++){
    wait(NULL);
}
printf("Exiting. \n");


}
