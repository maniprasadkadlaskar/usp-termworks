#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<iostream>
using namespace std;

void System(const char *cmd) {
    pid_t pid = fork();
    
    if(pid == 0)
        execl("/bin/bash", "bash", "-c" , cmd , NULL);
    else 
        waitpid(pid , NULL , 0);
}

int main(int argc , char *argv[]) {
    for(int i=1;i < argc;i++)
        System(argv[i]);

    return 0;
}
