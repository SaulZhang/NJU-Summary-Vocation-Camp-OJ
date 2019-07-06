/*
将后续遍历逆序，问题等价为最长公共子序列的长度
*/
#include <iostream>
#include <string>
using namespace std;

const int N = 1000+5;

int dp[N][N];

string Reverse(string a){

    string res="";

    int len = a.size();

    for(int i=len-1;i>=0;i--){
        res += a[i];
    }
    return res;
}

int main()
{
    string A,B;

    while(cin>>A>>B){
        int len = A.size();

        for(int i=0;i<=len;i++)
            dp[0][i]=dp[i][0]=0;

        B = Reverse(B);

        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        cout<<dp[len][len]<<endl;
    }
    return 0;
}
/*
ABCDEFGH
CEFDBHGA
*/
