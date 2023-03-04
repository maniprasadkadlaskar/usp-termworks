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
    
    if(mkfifo("fifo1" , 0666) == -1) {
        cout<<"cannot create fifo file"<<endl;
        exit(1);    
    }

    if(mkfifo("fifo2" , 0666) == -1) {
        cout<<"cannot create fifo file"<<endl;
        exit(2);    
    }

    cout<<"Waiting for request..."<<endl;

    int rfd = open("fifo1" , O_RDONLY , NULL);
    int wfd = open("fifo2" , O_WRONLY , NULL);

    ssize_t n = read(rfd , fname , 256);
    fname[n] = '\0';
    
    int fd = open(fname , O_RDONLY , NULL);
    
    cout<<fname<<" file requested"<<endl;
    cout<<"Processing request..."<<endl;

    if(fd < 0) {
        strcpy(buf , "Invalid File name");
        write(wfd , buf , strlen(buf));
    }
    else {
        n = read(fd , buf , 512);
        write(wfd , buf , n);
    }

    cout<<"Request successfully served"<<endl;

    close(fd);
    close(rfd);
    close(wfd);
    unlink("fifo1");
    unlink("fifo2");
    return 0;
}
