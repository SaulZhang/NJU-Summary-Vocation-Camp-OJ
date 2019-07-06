/*
采用遍历每一位的26个字母的情况进行邻域的选择
利用BFS的方式进行搜索，每个单词扩展的结点最多为26*5
26*5*20000≈1e6，复杂度还能接受
*/
#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

struct Node{

    string s;
    int l;
    Node(string _s,int _l){
        s = _s;
        l = _l;
    }
};

map<string,int> Voc;
queue<Node> Que;
map<string,int> Vis;

int main()
{

    int n;
    string st,ed,s;
    cin>>st>>ed;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        Voc[s]=1;
    }

    Que.push(Node(st,1));

    Vis[st]=true;

    int len = st.size();
    int ans=0;

    while(!Que.empty()){

        Node tmp = Que.front();
        Que.pop();

        if(tmp.s==ed){
            ans = tmp.l;
            break;
        }

        string temp;//存放临时字符串

        for(int i=0;i<len;i++){//邻域搜索
            for(char c='a';c<='z';c++){

                temp = tmp.s;
                temp[i] = c;

                if(Voc[temp]==1){
                    if(Vis[temp]==1)
                        continue;
                    else{
                        Que.push(Node(temp,tmp.l+1));
                        Vis[temp]=1;
                    }
                }

            }
        }

    }

    cout<<ans<<endl;

    return 0;

}
/*
输入样例：
起始单词 终止单词
词典大小
词典中的每个词

hit cog
5
hot dot dog cog dig
*/
