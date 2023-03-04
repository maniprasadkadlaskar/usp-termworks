#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int main() {
    cout<<"\nFeature test macros\n\n";

//    _POSIX_JOB_CONTROL
    #ifdef _POSIX_JOB_CONTROL
        cout<<"_POSIX_JOB_CONTROL "<<_POSIX_JOB_CONTROL<<endl;
    #else
        cout<<"_POSIX_JOB_CONTROL not-defined"<<endl;
    #endif

//    _POSIX_SAVED_IDS
    #ifdef _POSIX_SAVED_IDS
        cout<<"_POSIX_SAVED_IDS "<<_POSIX_SAVED_IDS<<endl;
    #else
        cout<<"_POSIX_SAVED_IDS not-defined"<<endl;
    #endif
    
//    _POSIX_CHOWN_RESTRICTED
    #ifdef _POSIX_CHOWN_RESTRICTED
        cout<<"_POSIX_CHOWN_RESTRICTED "<<_POSIX_CHOWN_RESTRICTED<<endl;
    #else
        cout<<"_POSIX_CHOWN_RESTRICTED not-defined"<<endl;
    #endif

//    _POSIX_NO_TRUNC
    #ifdef _POSIX_NO_TRUNC
        cout<<"_POSIX_NO_TRUNC "<<_POSIX_NO_TRUNC<<endl;
    #else
        cout<<"_POSIX_NO_TRUNC not-defined"<<endl;
    #endif

//    _POSIX_VDISABLE
    #ifdef _POSIX_VDISABLE
        cout<<"_POSIX_VDISABLE "<<_POSIX_VDISABLE<<endl;
    #else
        cout<<"_POSIX_VDISABLE not-defined"<<endl;
    #endif

    return 0;
}

