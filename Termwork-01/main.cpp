#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<limits.h>
using namespace std;

void compiletime() {
//    _POSIX_OPEN_MAX
    #ifdef _POSIX_OPEN_MAX
        cout<<"_POSIX_OPEN_MAX "<<_POSIX_OPEN_MAX<<endl;
    #else
        cout<<"_POSIX_OPEN_MAX not-defined"<<endl;
    #endif

//    _POSIX_CHILD_MAX
    #ifdef _POSIX_CHILD_MAX
        cout<<"_POSIX_CHILD_MAX "<<_POSIX_CHILD_MAX<<endl;
    #else
        cout<<"_POSIX_CHILD_MAX not-defined"<<endl;
    #endif

//    _POSIX_PATH_MAX
    #ifdef _POSIX_PATH_MAX
        cout<<"_POSIX_PATH_MAX "<<_POSIX_PATH_MAX<<endl;
    #else
        cout<<"_POSIX_PATH_MAX not-defined"<<endl;
    #endif

//    _POSIX_NAME_MAX
    #ifdef _POSIX_NAME_MAX
        cout<<"_POSIX_NAME_MAX "<<_POSIX_NAME_MAX<<endl;
    #else
        cout<<"_POSIX_NAME_MAX not-defined"<<endl;
    #endif
}

void runtime() {
    int res;

//    _SC_CHILD_MAX
    if((res = sysconf(_SC_CHILD_MAX)) == -1)
        perror("sysconf");
    else
        cout<<"_SC_CHILD_MAX "<<res<<endl;

//    _PC_OPEN_MAX
    if((res = sysconf(_SC_OPEN_MAX)) == -1)
        perror("sysconf");
    else
        cout<<"_SC_OPEN_MAX "<<res<<endl;

//    _PC_NAME_MAX
    if((res = pathconf("/" , _PC_NAME_MAX)) == -1)
        perror("pathconf");
    else
        cout<<"_PC_NAME_MAX "<<res<<endl;

//    _PC_PATH_MAX
    if((res = fpathconf(0 , _PC_PATH_MAX)) == -1)
        perror("pathconf");
    else
        cout<<"_PC_PATH_MAX "<<res<<endl;

}

int main() {
	cout<<"\nCompile time limits \n\n";
    compiletime();
	cout<<"\nRun time limits \n\n";
    runtime();
	return 0;
}
