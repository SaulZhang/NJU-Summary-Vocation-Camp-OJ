#include <iostream>
#define N 10000+5
using namespace std;

int A[N];

int main()
{
    int n;

    while(~scanf("%d",&n)){
        int ans=0;
        int cur_max = 0;
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<n;i++){
            cur_max = max(A[i],cur_max+A[i]);
            ans = max(ans,cur_max);
        }

        cout<<ans<<endl;
    }

    return 0;
}

/*


*/
