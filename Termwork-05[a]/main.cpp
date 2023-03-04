#include<stdio.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int main() {
    extern char **environ;

    for(char **ptr = environ;*ptr != NULL;ptr++) {
        cout<<*ptr<<endl;    
    }

    return 0;
}
