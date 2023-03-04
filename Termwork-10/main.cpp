#include<stdio.h>
#include<iostream>
#include<signal.h>
#define INTERVAL 5
using namespace std;

void callme(int signo) {
    cout<<"Hello World"<<endl;
}

int main() {
    struct sigaction action;
    action.sa_handler = callme;

    if(sigaction(SIGALRM , &action , NULL) == -1) {
        perror("sigaction");
        exit(1);    
    }

    if(alarm(INTERVAL) == -1) {
        perror("alarm");
        exit(2);    
    }

    if(sleep(INTERVAL) == -1) {
        perror("sleep");
        exit(3);    
    }

    return 0;
}
