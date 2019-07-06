#include <iostream>
#include <algorithm>

#define N 100+5
using namespace std;


int A[N];

int solve(int n){

    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=i+2;j<n;j++){

            int low = A[j]-A[i];
            int hig = A[j]+A[i];

            int lb = upper_bound(A,A+n,low)-A;
            lb = max(i+1,lb);

            int rb = lower_bound(A,A+n,hig)-A;
            rb = min(j-1,rb-1);

            if(rb>=lb){
                ans += rb-lb+1;
            }
        }
    }

    return ans;

}


int main()
{

    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            cin>>A[i];
        sort(A,A+n);

        cout<<solve(n)<<endl;
    }
    return 0;
}

/*
5
2 2 2 2 2
*/
