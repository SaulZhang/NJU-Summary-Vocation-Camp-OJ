/*
测试数据参考该博客
https://blog.csdn.net/qq_37053885/article/details/94484979
*/
#include <iostream>
#include <queue>
#include <memory.h>
#define N 100+5
#define M 10000+5
#define MAXINT 0x3f3f3f3f
using namespace std;

int tot,n,m;
int head[N];
int dis[N];
bool vis[N];

struct Edge{
    int v;
    int w;
    int next;
}edge[M];

void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}

void add_Edge(int u,int v,int w){
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

struct Node{
    int id;
    int w;
    Node(int _id,int _w){
        id = _id;
        w = _w;
    }
    operator < (const Node& x)const{
        return w>x.w;
    }
};

priority_queue<Node> Que;

void Dijkstra(int s,int t){

    while(!Que.empty())Que.pop();

    dis[s] = 0;

    Que.push(Node(s,dis[s]));

    while(!Que.empty()){

        int u = Que.top().id;
        Que.pop();
        if(vis[u])
            continue;

        vis[u] = true;

        if(u==t)
            break;
        for(int i=head[u];~i;i=edge[i].next){

            if(!vis[edge[i].v]&&dis[u]+edge[i].w<dis[edge[i].v]){
                dis[edge[i].v] = dis[u]+edge[i].w;
                Que.push(Node(edge[i].v,dis[edge[i].v]));
            }

        }

    }

}

int main()
{
    while(~scanf("%d%d",&n,&m)){

        if(n==0&&m==0)
            break;
        init();
        memset(dis,MAXINT,sizeof(dis));
        memset(vis,false,sizeof(vis));
        int c1,c2,w;

        for(int i=0;i<m;i++){
            cin>>c1>>c2>>w;
            add_Edge(c1,c2,w);
            add_Edge(c2,c1,w);
        }

        Dijkstra(1,n);

        cout<<dis[n]<<endl;

    }
    return 0;
}
/*
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0
*/
