/* Program demonstrates the use of kill() */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
int notDone = 1; int cnt = 0;
void mySIGhandler(int sig) {
    signal(SIGALRM,SIG_IGN);
    //breaks infinite loop by reset notDone
    notDone = 0;
    //printf("loop should break\n");
}
int main(void) {
    //install handler
    signal(SIGALRM,mySIGhandler);
    pid_t pid = fork();
    if (pid == 0) {
        printf("child created\n");
        while(1);
        printf("this line should not be shown\n");
        exit(0);
        //let parent enters loop (manual synchronization)
        // sleep(4); //let parent enters loop
        // printf("sending SIGALRM\n");
        // kill(getppid(),SIGALRM);
        // exit(0); // send signal and die
    } else {
        sleep(3);
        kill(pid,SIGINT);
        printf("I am gonna dieeeeeeee yaaaaaaaa");
        // printf("parent wait for SIGALRM\n");
        // while (notDone) cnt++; //infinite loop
    }
    //Could be time instead of cnt
    // printf("it takes %d\n",cnt);
    // return 0;
} //main