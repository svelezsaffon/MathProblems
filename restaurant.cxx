#include <cstdio>



/*
In this problems we will always have positive values,
therefore we can use the iterative solution of modulos.
 */

int gcd(int a,int b){

    int gcd=1;
    for(int i=1;i<=a && i<=b;i++){

        if(a % i==0 && b % i==0){
            gcd=i;
        }

    }

    return gcd;
}






int main(int argc, char** argv) {

    unsigned int cases;
    scanf("%ud",&cases);

    while(cases--){

        int l,d;

        scanf("%d %d",&l,&d);

        int gd = gcd(l, d);

        printf("%d\n",((l/gd)*(d/gd)));

    }

}