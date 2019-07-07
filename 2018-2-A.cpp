/*
找出递推方程，注意要采用long long，int会溢出
*/
#include <iostream>
#define N 90+5

using namespace std;

long long dp[N];

int main()
{
    int n;

    dp[1]=2,dp[2]=3;

    cin>>n;

    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout<<dp[n]<<endl;

    return 0;
}
/*
Input:
5

X X X O X
X X O X X
X O O X X
X X O X X
X X X O O

Output:
X X X X X
X X O X X
X O O X X
X X O X X
X X X X X
*/
