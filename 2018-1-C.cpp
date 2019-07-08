/*
多重背包问题：采用二进制编码进行压缩
*/
#include <iostream>
#define N 10 + 5
#define M 100000+5

using namespace std;

int Num[N],Val[N];
int dp[M];

int main()
{
    int n,Cmax;
    while(~scanf("%d%d",&n,&Cmax)){

        for(int i=1;i<=n;i++)
            cin>>Num[i]>>Val[i];

        for(int i=0;i<=Cmax;i++)
            dp[i] = 0;

        for(int i=1;i<=n;i++){
            for(int k=1;Num[i]-k>=0;k*=2){//二进制编码
                for(int j=Cmax;j>=Val[i]*k;j--){
                    dp[j] = max(dp[j],dp[j-Val[i]*k]+Val[i]*k);
                }

                Num[i] -= k;

            }
            if(Num[i]>0){
                for(int j=Cmax;j>=Val[i]*Num[i];j--){
                    dp[j] = max(dp[j],dp[j-Val[i]*Num[i]]+Val[i]*Num[i]);
                }
            }
        }
        for(int i=0;i<=Cmax;i++)
            cout<<dp[i]<<" ";
        cout<<endl;
    }

    return 0;
}


/*
4 60
3 10
1 5
3 1
5 61
*/
