#include <iostream>

extern "C"{
#include "pthread.h"

#include "unistd.h"
#include "math.h"
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


//=============== 4
void * IsPrime(void *n){
    unsigned int p = reinterpret_cast<unsigned long  int > (n);
    unsigned int i = 3;
    unsigned int t = (uint)sqrt(p) + 1;

    if(p == 2)
    {
        return reinterpret_cast<void *> (true);
    }

    if(p % 2 == 0)
    {
        return reinterpret_cast<void *> (false);
    }


    while (i <= t)
    {
        if(p % i == 0)
        {
            return reinterpret_cast<void *> (false);
        }

        i += 2;
    }
    return reinterpret_cast<void *>(true);
}

int main() {
    //cout << "Hello, World!" << endl;
   // pthread_t pid;
    //pthread_create(&pid,NULL,printsmall,NULL);
   // printf("thread id:%d",pid);
   // printBig(NULL);

//    printf("%d %d\n", sizeof(int),sizeof(void *));

//    printf("%lu %lu\n", sizeof(int),sizeof(void *));
//
//    pthread_t tids[8];
//
//    bool primalities[8];
//
//    for(int i = 0; i<8;++i){
//        pthread_create(&tids[i],NULL,IsPrime, reinterpret_cast<void *>(i + 2));
//    }
//
//    for(int i = 0; i < 8;++i)
//    {
//        pthread_join(tids[i], reinterpret_cast<void **>(&primalities[i]));
//    }
//
//    for (int j = 0; j < 8; ++j) {
//        cout<<primalities[j]<<" ";
//    }
//
//    cout<<endl;

    pthread_t  tid;

    pthread_attr_t att;
    pthread_attr_init(&att);
    pthread_attr_setdetachstate(&att,PTHREAD_CREATE_DETACHED);

    pthread_create(&tid,&att,printsmall,NULL);

    pthread_attr_destroy(&att);

    //====没有下面的函数,主线程结束,子线程也跟着结束




    while (1){

        sleep(1);
    }
    return 0;
}