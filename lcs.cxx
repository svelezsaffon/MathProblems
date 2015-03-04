#include <cstdio>
#include <vector>



#define MAX(A,B) ((A>=B)? A:B)


void rebuild(std::vector<int> &res,std::vector<int> xword,std::vector<int> yword,std::vector< std::vector < int > > dp, int i, int j){

    if(i>0 && j>0) {

        if (xword[i - 1] == yword[j - 1]) {
            //its a diagonal on the matrix
            int a=i-1,b=j-1;

            res.push_back(xword[a]);

            rebuild(res,xword, yword, dp, a, b);
        } else {

            if (dp[i][j] == dp[i - 1][j]) {
                //go this way

                int a=i-1;
                rebuild(res,xword, yword, dp, a, j);

            } else {
                //go this way

                int b=j-1;
                rebuild(res,xword, yword, dp, i, b);

            }

        }

    }


}


int main(int argc, char** argv) {

    int x,y;


    scanf("%d %d",&x,&y);

    std::vector< std::vector < int > > dp;
    std::vector<int> xword;
    std::vector<int> yword;

    int aux;
    for(int i=0;i<x;i++){
        scanf("%d",&aux);
        xword.push_back(aux);
    }


    for(int i=0;i<y;i++){
        scanf("%d",&aux);
        yword.push_back(aux);
    }





    for(int i=0;i<=x;i++){
        dp.push_back(std::vector<int>());

        for(int j=0;j<=y;j++){

            if(i==0 || j==0){

                dp[i].push_back(0);
            }else {

                if (xword[i-1] == yword[j-1]) {
                    //there is a match
                    dp[i].push_back(dp[i - 1][j - 1] + 1);
                } else {
                    //not a mathc, look for the others
                    dp[i].push_back(MAX(dp[i - 1][j], dp[i][j - 1]));

                }
            }

        }

    }

    std::vector<int> res;

    rebuild(res,xword, yword, dp, x, y);


    int num=dp[x][y];

    std::vector<int>::reverse_iterator back=res.rbegin();

    for(;back!=res.rend();++back){

        printf("%d ",*back);

    }



}




