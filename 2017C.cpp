#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

const int N = 1000+5;

string Token,TokenSet[N],src;
stack<string> S1,S2;//其中S2专门用来判断ELSE是否合法,当IF-THEN匹配完之后把THEN压入到S2中，
                     //只有当S2不为空时才能匹配ELSE。

bool Syntax(int len){
    while(!S1.empty())S1.pop();
    while(!S2.empty())S2.pop();
    for(int i=0;i<len;i++){
        if(TokenSet[i]=="IF"){
            S1.push(TokenSet[i]);
        }
        else if(TokenSet[i]=="THEN"){
            if(!S1.empty()&&S1.top()=="IF"){
                S2.push(TokenSet[i]);
                S1.pop();
            }
            else{
                cout<<"No Matching Token 'THEN'"<<endl;
                return false;
            }
        }
        else if(TokenSet[i]=="ELSE"){
            if(!S2.empty()&&S2.top()=="THEN"){
                S2.pop();
            }
            else{
                cout<<"No Matching Token 'ELSE'"<<endl;
                return false;
            }
        }
        else if(TokenSet[i]=="BEGIN"){
            S1.push(TokenSet[i]);
        }
        else if(TokenSet[i]=="END"){

            if(!S1.empty()&&S1.top()=="BEGIN"){
                S1.pop();
            }
            else{
                cout<<"No Matching Token 'END'"<<endl;
                return false;
            }
        }
        else{
            cout<<"invalid token!"<<endl;
            return false;
        }

    }

    if(!S1.empty())
        return false;

    return true;
}

int main()
{
    int cnt;
    while(cin>>src){
        cnt=0;
        stringstream ss(src);

        while(getline(ss,Token,',')){
            TokenSet[cnt++] = Token;
        }

        if(Syntax(cnt)){
            cout<<"Yes!"<<endl;
        }
        else{
            cout<<"No!"<<endl;
        }

    }
    return 0;
}
/*
IF,THEN,IF,THEN,IF,THEN,BEGIN,END,ELSE,BEGIN,END,ELSE,BEGIN,END,ELSE,BEGIN,BEGIN,END,END
IF,THEN,IF
IF,THEN
BEGIN,END
BEGIN,IF,THEN,ELSE,END
*/
