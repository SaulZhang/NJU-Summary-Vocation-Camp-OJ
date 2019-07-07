/*
//dp[i][j]在前i个厂家中，给定j的最大带宽可以取得的最下价格

dp[i][j] = min{dp[i][j],dp[i-1][k]+p}
*/
#include <iostream>
#include <stdio.h>
#define N 100+5
#define B 1000+100

const int inf = 123123123;

using namespace std;

int dp[N][B+1];

int main()
{
    int T,n,m;
    int b,p;

    cin>>T;

    for(int t=1;t<=T;t++){
        cin>>n;
        for(int i=0;i<=B;i++)
            dp[0][i]=0;

        for(int i=1;i<=n;i++){//因为每一个制造商必须选一个商品，因此一开始要初始化为无穷大，
                              //使得dp[i][j]至少更新一次
            for(int j=0;j<=B;j++){
                dp[i][j] = inf;
            }
        }

        for(int i=1;i<=n;i++){//遍历生产商
            cin>>m;
            for(int j=1;j<=m;j++){//遍历生产商i的商品
                cin>>b>>p;//输入该生产商的m个设备
                for(int k=0;k<=B;k++){//遍历带宽

                    if(dp[i-1][k]!=inf){

                        if(k<=b){//当前商品的带宽小于给定带宽时
                            dp[i][k] = min(dp[i][k],dp[i-1][k]+p);
                        }
                        else
                            dp[i][b] = min(dp[i][b],dp[i-1][k]+p);
                    }

                }
            }
        }

        double ans=0;
        for(int j=0;j<=B;j++){//遍历所有的
            if(dp[n][j]!=inf){
                ans = max(ans,j*1.0/dp[n][j]);
            }
        }

        printf("%.3f\n",ans);

    }

    return 0;
}
/*
1 3
3 100 25 150 35 80 25
2 120 80 155 40
2 100 100 120 110
/*


