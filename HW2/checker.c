#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]){ 
int Arg1_PlaceHolder = atoi(argv[1]); // making string args into integers
int Arg2_PlaceHolder = atoi(argv[2]);
    printf ("Checker Process [%d]: Starting.\n", getpid()); //starting process
if (Arg1_PlaceHolder % Arg2_PlaceHolder == 0){ //checking divisibility
    printf("Checker Process [%d]: %d *IS* divisible by %d.\n", getpid(), Arg1_PlaceHolder, Arg2_PlaceHolder);
    printf("Checker Process [%d]: Returning 1.\n", getpid());
    return 1;

} else if(Arg1_PlaceHolder % Arg2_PlaceHolder !=0){ // continuing to check divisibility
    printf("Checker Process [%d]: %d *IS NOT* divisible by %d.\n",getpid(), Arg1_PlaceHolder, Arg2_PlaceHolder);
    printf("Checker Process [%d]: Returning 0.\n", getpid());
    return 0;
}
return 0;
}
