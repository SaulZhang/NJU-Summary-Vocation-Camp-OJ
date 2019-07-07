/*
转化为求多次的最大子段和问题
*/
#include <iostream>
#include <stdio.h>
#define N 100+5

using namespace std;

int A[N][N];
int Acc[N][N];

int n;

int main()
{
    while(~scanf("%d",&n)){

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>A[i][j];
            }
        }

        for(int j=0;j<n;j++)
            Acc[0][j] = A[0][j];//第0行赋值

        for(int i=1;i<n;i++){//第1~n行累加
            for(int j=0;j<n;j++){
                Acc[i][j] = Acc[i-1][j] + A[i][j];
            }
        }

        //最大字段和
        int E[N];

        int Max = A[0][0];
        int CurSum;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==0){
                    for(int k=0;k<n;k++){
                        E[k] = Acc[j][k];
                    }

                    CurSum = 0;
                    for(int k=0;k<n;k++){
                        CurSum = max(E[k],E[k]+CurSum);
                        Max = max(Max,CurSum);
                    }

                }
                else{

                    for(int k=0;k<n;k++){
                        E[k] = Acc[j][k]-Acc[i-1][k];
                    }

                    CurSum = 0;
                    for(int k=0;k<n;k++){
                        CurSum = max(E[k],E[k]+CurSum);
                        Max = max(Max,CurSum);
                    }
                }
            }
        }
        cout<<Max<<endl;
    }
    return 0;
}
/*
 4
 0 -2 -7  0
 9  2 -6  2
-4  1 -4  1
-1  8  0 -2

*/
