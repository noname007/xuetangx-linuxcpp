#include <iostream>

extern "C"{
#include "pthread.h"

#include "unistd.h"
}


using namespace std;

void * printsmall(void * data){
    while(1){
        printf("small\n");
        sleep(1);
    }
    return  NULL;
}

void * printBig(void * data){
    while(true){
        printf("Big\n");
        sleep(1);
    }
    return  NULL;
}

int main() {
    cout << "Hello, World!" << endl;
    pthread_t pid;
    pthread_create(&pid,NULL,printsmall,NULL);
   // printf("thread id:%d",pid);
    printBig(NULL);
    return 0;
}