#include <limits.h>
#include <cstdio>


int abs(int num){
    int mask = -((unsigned int)(int)num >> (sizeof(int)* CHAR_BIT -1));
    return (num+mask)^mask;
}




int main(int argc, char **argv){


    unsigned int cases;
    scanf("%ud",&cases);


    while(cases--){

        int N,K;
        scanf("%d %d",&N,&K);

        int pos=K-N-1;

        if(pos == N){

            pos++;


        }


        pos= abs(pos) % N;


        printf("%d\n",pos);


    }

}