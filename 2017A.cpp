/*
由于该二叉树为满二叉树，因此假定输入数据为层次遍历的结果，
可以采用层次遍历的方法来构造二叉树
*/
#include <iostream>
#include <queue>
#include <stack>
#define N 1000+5
using namespace std;

int loc;
int n,sum;

void init(){
    loc = 0;
}
int A[N];

struct TreeNode{
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
}Tree[N];

TreeNode* create(){
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}

queue<TreeNode*> Que;
stack<int> S,Stmp;
vector<int> res;

void dfs(TreeNode* T,int curSum){

    S.push(T->data);
    curSum+=T->data;

    if(T->lchild==NULL&&T->rchild==NULL&&curSum==sum){
        res.clear();
        Stmp = S;
        while(!Stmp.empty()){
            res.push_back(Stmp.top());
            Stmp.pop();
        }
        for(int i=res.size()-1;i>=0;i--){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }

    if(T->lchild!=NULL)
        dfs(T->lchild,curSum);

    if(T->rchild!=NULL)
        dfs(T->rchild,curSum);

    curSum -= T->data;
    S.pop();
}


int main()
{
    while(~scanf("%d%d",&n,&sum)){

        for(int i=0;i<n;i++)
            cin>>A[i];

        while(!Que.empty())
            Que.pop();
        while(!S.empty())
            S.pop();

        TreeNode* T = create();
        T->data = A[0];
        Que.push(T);

        int pos=0;

        while(!Que.empty()){//层次遍历建树
            TreeNode* tmp = Que.front();
            Que.pop();
            if(pos<n&&A[++pos]!=-1){
                TreeNode* lt = create();
                lt->data = A[pos];
                tmp->lchild = lt;
                Que.push(lt);
            }
            if(pos<n&&A[++pos]!=-1){
                TreeNode* rt = create();
                rt->data = A[pos];
                tmp->rchild = rt;
                Que.push(rt);
            }
        }

        dfs(T,0);


    }

    return 0;
}

/*
7 2
1 1 1 -1 -1 -1 -1
31 14
3 4 5 7 6 2 5 6 3 2 1 2 4 3 2 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

31 22
5 4 8 11 -1 13 4 7 2 -1 -1 -1 -1 5 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
