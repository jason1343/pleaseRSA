#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lcm(int p, int q);
int gcd(int E, int L);

int p = 0;
int q = 0;
int E = 0;
int D = 0;
int N = 0;
int L = 0;

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
    N = p*q;
    printf("N : %d\n", N);

    //L 구하기
    L = lcm(p - 1, q - 1);
    if(L == -1){
        printf("Unexpected Error =(");
        return -1;
    }
    else printf("L : %d\n", L);


    //E, D 구하기
    while(1){
        
        //E 구하기 1<E<L, L과 서로소
        while(1){
            E = ((rand()*rand()) % ((L-1) - 2 + 1)) + 2;
            int e = gcd(E, L);

            //E와 L의 최대공약수가 1일 경우
            if (e == 1){
                break;
            }
        }
        //D 구하기 1<D<L, E*D를 L로 나눴을 때 나머지가 1이어야함.
        while(1){
            int D = ((rand()*rand()) % ((L-1) - 2 + 1)) + 2;
            if((E * D) % L == 1){
                printf("The Final D : %d\n", D);
                break;
            }
        }

        
        break;
    }



    return 0;
}

//최소공배수 함수
int lcm(int p, int q){
    //더 큰 수를 결정
    int bigger_val = (p > q) ? p : q;
    
    //결정한 더 큰 수부터 1씩 늘려가며 최소공배수를 찾는다.
    for(int i = bigger_val; i <= (p*q); i++){
        if(i % p == 0 && i % q ==0){
            return i;
        }
    }
    return -1;
}

//최대공약수 함수
int gcd(int E, int L){
    //결정한 더 작은 수인 E부터 1씩 감소시키며 최대공약수를 찾는다.
    for(int i = E; i > 0; i--){
        if (E % i == 0 && L % i == 0){
            return i;
        }
    }
    return -1;
}