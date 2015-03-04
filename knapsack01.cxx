#include <cstdio>
#include <vector>

#define SACKWEIGHT 5
#define ITEMNUM 3


#define MAX(A,B) ((A>=B)? A:B)

int main(int argc, char** argv) {

    std::vector<int> item_weight;
    item_weight.push_back(1);
    item_weight.push_back(6);
    item_weight.push_back(9);
    //item_weight.push_back(1);

    std::vector<int> item_val;
    item_val.push_back(1);
    item_val.push_back(6);
    item_val.push_back(9);
    //item_val.push_back(5);




    std::vector< std::vector< int > > dp;

    for(int i=0;i<=ITEMNUM;i++){

        dp.push_back(std::vector<int>());

        for(int w=0;w<=SACKWEIGHT;w++){

            if(i==0 || w==0){
                dp[i].push_back(0);
            }else{

                if(item_weight[i-1]<=w){
                    //DO dynamic programming
                    dp[i].push_back(MAX(dp[i-1][w-item_weight[i-1]]+item_val[i-1], dp[i-1][w]));
                }else{
                    //CHOOSE THE VALUE OF THE PREVIOUS LINE(ITEM)
                    dp[i].push_back(dp[i-1][w]);
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