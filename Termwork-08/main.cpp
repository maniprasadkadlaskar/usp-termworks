#include<stdio.h>
#include<unistd.h>
#include<iostream>
#include<sys/wait.h>
using namespace std;

int main() {
    pid_t pid = fork();

    if(pid < 0) {
        cout<<"Fork failed"<<endl;
    }
    else if(pid == 0) {
        pid = fork();
        
        if(pid < 0) {
            cout<<"Fork failed"<<endl;
        }
        else if(pid == 0) {
            cout<<"Second child with pid : "<<getpid()<<" ppid : "<<getppid()<<endl;        
        }
        else {
            cout<<"First child with pid : "<<getpid()<<" ppid : "<<getppid()<<endl;                    
        }
    }
    else {
        system("ps -o pid,ppid,tty,state,command");
        wait(NULL);
        sleep(5);
        cout<<"parent with pid : "<<getpid()<<" ppid : "<<getppid()<<endl;                
        system("ps -o pid,ppid,tty,state,command");
    }

    return 0;
}
