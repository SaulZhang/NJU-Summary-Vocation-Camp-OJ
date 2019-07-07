/*
//dp[i][j]��ǰi�������У�����j�����������ȡ�õ����¼۸�

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

        for(int i=1;i<=n;i++){//��Ϊÿһ�������̱���ѡһ����Ʒ�����һ��ʼҪ��ʼ��Ϊ�����
                              //ʹ��dp[i][j]���ٸ���һ��
            for(int j=0;j<=B;j++){
                dp[i][j] = inf;
            }
        }

        for(int i=1;i<=n;i++){//����������
            cin>>m;
            for(int j=1;j<=m;j++){//����������i����Ʒ
                cin>>b>>p;//����������̵�m���豸
                for(int k=0;k<=B;k++){//��������

                    if(dp[i-1][k]!=inf){

                        if(k<=b){//��ǰ��Ʒ�Ĵ���С�ڸ�������ʱ
                            dp[i][k] = min(dp[i][k],dp[i-1][k]+p);
                        }
                        else
                            dp[i][b] = min(dp[i][b],dp[i-1][k]+p);
                    }

                }
            }
        }

        double ans=0;
        for(int j=0;j<=B;j++){//�������е�
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


