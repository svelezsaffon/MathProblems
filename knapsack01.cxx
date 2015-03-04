#include <cstdio>
#include <vector>

#define SACKWEIGHT 5
#define ITEMNUM 4


#define MAX(A,B) ((A>=B)? A:B)

int main(int argc, char** argv) {

    std::vector<int> item_weight;
    item_weight.push_back(4);
    item_weight.push_back(2);
    item_weight.push_back(3);
    item_weight.push_back(1);

    std::vector<int> item_val;
    item_val.push_back(10);
    item_val.push_back(4);
    item_val.push_back(7);
    item_val.push_back(5);




    int dp[ITEMNUM+1][SACKWEIGHT+1];



    for(int i=0;i<=ITEMNUM;i++){

        for(int w=0;w<=SACKWEIGHT;w++){

            if(i==0 || w==0){
                dp[i][w]=0;
            }else{

                if(item_weight[i-1]<=w){
                    //DO dynamic programming
                    dp[i][w]= MAX(dp[i-1][w-item_weight[i-1]]+item_val[i-1], dp[i-1][w]);
                }else{
                    //CHOOSE THE VALUE OF THE PREVIOUS LINE(ITEM)
                    dp[i][w]=dp[i-1][w];
                }

            }
        }

    }


    for(int i=0;i<=ITEMNUM;i++) {

        for (int w = 0; w <= SACKWEIGHT; w++) {

            printf("%d ",dp[i][w]);

        }

        printf("\n");


    }


    printf("Max stealing=%d\n",dp[ITEMNUM][SACKWEIGHT]);



}