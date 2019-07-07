/*
���û���+��֦�ķ������б�������
*/
#include <iostream>
#include <string>
#include <set>

using namespace std;

string src;
set<int> S;//�����е�Ԫ����Ψһ��
int n;

bool isOut=false;

void dfs(int t){
    if(isOut)
        return ;
    if(S.size()==n-1&&t>=src.size()){
        int cnt[n+1];
        for(auto it=S.begin();it!=S.end();it++){
            cnt[*it]=1;
        }
        for(int i=1;i<=n;i++){
            if(cnt[i]!=1)
                cout<<i<<" ";
        }
        cout<<endl;
        isOut=true;
    }
    else{
        if(src[t]!='0'){//��ǰ���ַ�������Ϊ0(��֦1)
            int s1 = src[t]-'0';
            if(s1<=n&&S.find(s1)==S.end()){//ֻ����1���ַ����Ƿ������Χ���Ƿ��Ѿ����ڣ���֦2,3��
                S.insert(s1);
                dfs(t+1);
                S.erase(s1);
            }
            if(t<src.size()-1){//����2���ַ�
                int s2 = (src[t]-'0')*10+(src[t+1]-'0');
                if(s2<=n&&S.find(s2)==S.end()){//�Ƿ������Χ���Ƿ��Ѿ����ڣ���֦2,3��
                    S.insert(s2);
                    dfs(t+2);
                    S.erase(s2);
                }
            }
        }

    }


}


int main()
{

    while(cin>>n){
        cin>>src;

        dfs(0);


    }

    return 0;
}
/*
9
12345689

11
101192345678

15
1513141210987654321
*/
