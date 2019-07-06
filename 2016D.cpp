/*
POJ2631
http://poj.org/problem?id=2631
这里采用到了求树的最大直径的结论，首先随机选取一个起始点u，然后通过改点进行一次BFS
找到距离改点最远的点v，在进行一次BFS，找到里v最远的点k，k与v之间的距离即为所求答案.
*/

#include <iostream>
#include <string.h>
#include <queue>
#define N 10000+5

using namespace std;

int tot,head[N],dis[N];

void init(){
    tot=0;

    memset(head,-1,sizeof(head));
}

struct Edge{
    int v;
    int w;
    int next;
}edge[2*N];

struct Node{
    int u;
    int length;
    Node(int _u,int _l){
        u = _u;
        length = _l;
    }
};

queue<Node> Que;

void add_Edge(int u,int v,int w){

    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

bool vis[N];

int main()
{
    int a,b,l;
    init();

    memset(vis,false,sizeof(vis));
    while(cin>>a>>b>>l){
        if(a==0&&b==0&&l==0)
            break;
        add_Edge(a,b,l);
        add_Edge(b,a,l);
    }

    int u=1;
    Que.push(Node(u,0));
    vis[u] = true;

    int Max = 0;
    int n_idx = 0;

    while(!Que.empty()){

        Node tmp = Que.front();
        Que.pop();

        if(tmp.length>Max){
            Max = tmp.length;
            n_idx = tmp.u;
        }

        for(int i=head[tmp.u];~i;i=edge[i].next){
            if(vis[edge[i].v])
                continue;
            else{
                Que.push(Node(edge[i].v,tmp.length+edge[i].w));
                vis[edge[i].v]=true;
            }
        }
    }

    memset(vis,false,sizeof(vis));
    u = n_idx;
    Que.push(Node(u,0));
    vis[u] = true;
    Max = 0;

    while(!Que.empty()){

        Node tmp = Que.front();

        Que.pop();

        if(tmp.length>Max){
            Max = tmp.length;
            n_idx = tmp.u;
        }

        for(int i=head[tmp.u];~i;i=edge[i].next){
            if(vis[edge[i].v])
                continue;
            else{
                Que.push(Node(edge[i].v,tmp.length+edge[i].w));
                vis[edge[i].v]=true;
            }
        }
    }

    cout<<Max<<endl;

    return 0;
}
/*
5 1 6
1 4 5
6 3 9
2 6 8
6 1 7
0 0 0
*/
