#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<iostream>
using namespace std;

int main(int argc , char *argv[]) {
    if(argc == 3) {
        link(argv[1] , argv[2]);
    }
    else if(argc == 4) {
        if(strcmp(argv[1] , "-s") == 0) {
            symlink(argv[2] , argv[3]);
        }    
        else {
            cout<<argv[1]<<" not found. Do you mean '-s' ?"<<endl;        
        }
    }
    else {
        cout<<"Invalid arguements"<<endl;
    }
    return 0;
}
