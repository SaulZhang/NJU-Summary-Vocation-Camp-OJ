/*
��Ϊ��֪���������Ŀ�����������С�򻯰ɡ�
����ÿ����ֵ����0~9֮��ģ���ֻ��һλ
�����������Ϊ��������������С��
����ÿ������ı��ʽΪһ���ַ������м�û�зָ������зָ�
*/
#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

stack<char> Sop;
stack<int> Snum;

map<char,int> Prior;

bool isNum(char c){
  if(c>='0'&&c<='9')
    return true;
  else
    return false;
}

bool isOp(char c){

    if(c=='+'||c=='-'||c=='*'||c=='/')
        return true;
    else
        return false;
}


int main()
{
    Prior['+']=0,Prior['-']=0,Prior['*']=1,Prior['/']=1;
    string src,houzhui;
    while(cin>>src){
        while(!Sop.empty())
            Sop.pop();
        //��׺->��׺
        int lenSrc = src.size();

        houzhui = "";

        for(int i=0;i<lenSrc;i++){
            if(src[i]=='(')
                Sop.push(src[i]);
            else if(isNum(src[i]))
                houzhui += src[i];
            else if(src[i]==')'){
                while(Sop.top()!='('){
                    houzhui+=Sop.top();
                    Sop.pop();
                }
                Sop.pop();
            }
            else
                while(isOp(src[i])){

                    if(Sop.empty()||Sop.top()=='('||Prior[src[i]]>Prior[Sop.top()]){
                        Sop.push(src[i]);
                        break;
                    }
                    else{
                        houzhui+=Sop.top();
                        Sop.pop();
                    }

                }
        }
        while(!Sop.empty())houzhui+=Sop.top(),Sop.pop();
        while(!Snum.empty())Snum.pop();

        //��׺->��ֵ
        int lenhouzhui = houzhui.size();

        for(int i=0;i<lenhouzhui;i++){
            if(isNum(houzhui[i])){
                Snum.push(houzhui[i]-'0');
            }
            else{
                int num1 = Snum.top();
                    Snum.pop();
                int num2 = Snum.top();
                    Snum.pop();

                if(houzhui[i]=='+'){
                    Snum.push(num2+num1);
                }
                else if(houzhui[i]=='-'){
                    Snum.push(num2-num1);
                }
                else if(houzhui[i]=='*'){
                    Snum.push(num2*num1);
                }
                else{
                    Snum.push(num2/num1);
                }

            }
        }
        if(Snum.size()!=1)
            cout<<"Error Expression!"<<endl;
        cout<<Snum.top()<<endl;
    }
    return 0;
}
/*
((1+3/2)*3-7)*(3+5)+2*3
3*((1+4)*5)/6
-2
*/
