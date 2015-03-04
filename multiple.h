#include <limits.h>


int abs(int a){
    const int mask=-((unsigned int)(int)a>>(sizeof(int)* CHAR_BIT-1));

    return (a+mask) ^ mask;

}


int sign(int v){

    /*
    In most architectures this is 32 (sizeof(int) * CHAR_BIT -1)

    THe left most bit in integers is 1 if ots negative
    0 if its positive

    The following gives ud the left most bit
    ((unsigned int)(int) v >>(sizeof(int) * CHAR_BIT -1))
    -1 -> negative
    -0 -> positive


    */

    return  -((unsigned int)(int) v >>(sizeof(int) * CHAR_BIT -1));


}

unsigned multiple_3(int a){

    a= abs(a);

    if(a==0){
        return 1;
    }else if(a==1){
        return 0;
    }



    int odd=0;
    int even=0;

    unsigned pos=0;

    for(;a;a>>=1){

        if(pos==0){
            even+=(1 & a);
            pos=1;
        }else{
            odd+=(1 & a);
            pos=0;
        }
    }

    return multiple_3(odd-even);
}


unsigned power_2(int a){
    return a && !(a & (a-1));
}


void swap(int &a,int &b){
    a=(a^b);
    b=(a^b);
    a=(a^b);
}



int multiply_7(int a){
    //multiply by 7 is the same
    //as multiply by 8 and substract the original number
    //multiplyin by 8 is the same as <<3

    return ((a<<3)-a);

}