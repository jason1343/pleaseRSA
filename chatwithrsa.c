#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int p = 0;
int q = 0;

int main(){
    srand(time(NULL));
    short thisisUM = 0;

    //소수 p 구하기
    while(thisisUM == 0){
        int count = 0;
        p = (rand() % (30000 - 20000 + 1)) + 20000;

        for(int i = 2; i <= p-1; i++){
            if(p % i == 0){
                count++;
            }
        }
        if(count == 0) thisisUM = 1;
    }

    //소수 q 구하기
    thisisUM = 0;
    while(thisisUM == 0){
        int count = 0;
        q = (rand() % (30000 - 20000 + 1)) + 20000;

        for(int i = 2; i <= q-1; i++){
            if(q % i == 0){
                count++;
            }
        }
        if(count == 0) thisisUM = 1;
    }
    printf("p, q : %d, %d \n", p, q);

    //N 구하기
    long long N = p*q;
    printf("N : %lld", N);

    return 0;
}