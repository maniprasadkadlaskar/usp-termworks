#include<stdio.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int main() {
    pid_t pid = fork();

    if(pid < 0) {
        cout<<"Error executing fork"<<endl;
    }
    else if(pid == 0) {
        cout<<"process with pid : "<<getpid()<<" exited"<<endl;
        exit(0);
    }

    system("ps -o pid,ppid,state,tty,command");    
    sleep(30);
    return 0;
}
