/*
��ǰ������һ�������������
�ٴӺ���ǰ��һ�������������
�������м����������������
*/
#include <iostream>
#include <algorithm>
#define N 1000+5
using namespace std;

int dp1[N],dp2[N];

double A[N];

int main()
{
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>A[i];
            dp1[i]=dp2[i]=1;
        }

        //����O(nlogn)û�������ôά��ÿ�����г����µ�dpֵ

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(A[i]>A[j]){
                    dp1[i]=max(dp1[i],dp1[j]+1);
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(A[i]>A[j]){
                    dp2[i]=max(dp2[i],dp2[j]+1);
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ans =max(ans,dp1[i]+dp2[j]);
            }
        }

        cout<<n-ans<<endl;
    }

    return 0;
}

/*
8
1.86 1.86 1.30621 2 1.4 1 1.97 2.2
8
2 2 2 20 2 2 2 2
*/
