#include <cstdio>
#include <vector>



#define MAX(A,B) ((A>=B)? A:B)

int main(int argc, char** argv) {


int cases;

    scanf("%d",&cases);


    while(cases--){

        int elem,W;

        scanf("%d %d",&elem,&W);

        std::vector<int> weights;

        for(int i=0;i<elem;i++){
            int aux;
            scanf("%d",&aux);
            weights.push_back(aux);
        }


        std::vector<int> m;
        m.push_back(0);


        for(int i=1;i<=W;i++){
            int max=0;
            for(int j=0;j<elem;j++){
                if(weights[j]<=i){
                    max= MAX(max, weights[j]+m[i-weights[j]]);
                }
            }

            m.push_back(max);

        }


        printf("%d\n",m[W]);


    }





}