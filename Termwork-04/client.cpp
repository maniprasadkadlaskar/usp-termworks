#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<iostream>
using namespace std;

int main() {
    char fname[256];
    char buf[512];
    
    cout<<"Connecting to server..."<<endl;

    int wfd = open("fifo1" , O_WRONLY , NULL);
    int rfd = open("fifo2" , O_RDONLY , NULL);

    cout<<"Connected to server"<<endl;

    cout<<"Enter file to be requested : ";
    cin>>fname;

    write(wfd , fname , strlen(fname));
    
    cout<<"Waiting for server response..."<<endl;

    ssize_t n;
    while((n = read(rfd , buf , 512)) < 0);
    write(1 , buf , n);

    cout<<"\nServer responded successfully"<<endl;

    close(rfd);
    close(wfd);

    return 0;
}
