/*
对边缘的点从外向内进行DFS
*/
#include <iostream>
#define N 100+5
using namespace std;

char Mat[N][N];
int n;
bool Vis[N][N];

int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};


void dfs(int x,int y){

    for(int i=0;i<4;i++){
        int newX = x + dir[i][0];
        int newY = y + dir[i][1];

        if(newX>=0&&newX<=n-1&&newY>=0&&newY<=n-1){
            if(Mat[newX][newY]=='O'&&!Vis[newX][newY]){
                Vis[newX][newY] = true;
                Mat[newX][newY] = 'X';
                dfs(newX,newY);
            }
        }

    }


}


int main()
{
    while(~scanf("%d",&n)){

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>Mat[i][j];
                Vis[i][j]=false;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0||j==n-1||i==n-1){//对边缘的点进行DFS
                    if(Mat[i][j]=='O'&&!Vis[i][j]){

                        Mat[i][j] = 'X';
                        Vis[i][j] = true;
                        dfs(i,j);
                    }
                }


            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<Mat[i][j]<<" ";
            }
            cout<<endl;
        }


    }
    return 0;
}
/*
Input:
5
X X X O X
X X O X X
O O X O O
X O O X O
X X O O O

Output:
X X X X X
X X O X X
X O O X X
X X O X X
X X X X X
*/
