#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

bool isNumber(char c){
    return c>='0'&&c<='9';
}

int prior(char op){
    switch(op){
        case '+':return 0;break;
        case '-':return 0;break;
        case '*':return 1;break;
        case '/':return 1;break;
        default: cerr<< "未知操作符" << op << endl; return 0;
    }
}
int precede(char a,char b){
    //TODO 判断运算符优先性 正为a优先于b 0为同级，负为b优先于a
    return prior(a)-prior(b);
}


void calculateOnce(stack<int> &data,char op){
    //假定都是二元操作符
    if(data.size()<2) cerr<< "操作数不足";
    int a = data.top();
    data.pop();
    int b = data.top();
    data.pop();
    switch(op){
        case '+':data.push(b+a);break;
        case '-':data.push(b-a);break;
        case '*':data.push(b*a);break;
        case '/':data.push(b/a);break;
        default:cerr<< "未知操作符" << op << endl ;
    }
}

int readNumber(istream& is){
    if(!isNumber(is.peek())){
        cerr<< "非数字，无法读取";
    }
    int r = is.get()-'0';
    while(isNumber(is.peek())){
        r = r*10+is.get()-'0';
    }
    return r;
}


int calculate(string s){
    stringstream ss(s);
    stack<char> ops;
    stack<int> data;
    char before='('; //用于处理负数，前一个读取的字符为(且当前读取-时反转minusflag标记，其实可以考虑弄个一元运算符出来？
    bool minusflag = false;
    for(char c=ss.peek();c!='#';before=c,c=ss.peek()){
        if(isNumber(c)){
            if(minusflag){
                data.push(-readNumber(ss));
                minusflag=false;
            }else{
                data.push(readNumber(ss));
            }
        }else{
            if(before=='('&&c=='-'){
                ss.get();
                minusflag = true;
                continue;
            }
            if(c=='('){
                ops.push(ss.get());
                //before='(';
                continue;
            }
            c=ss.get();
            if(c!=')'&&(ops.empty()||ops.top()=='('||precede(c,ops.top())>0)){
                ops.push(c);
            }else if(c==')'){
                while(ops.top()!='('){
                    calculateOnce(data,ops.top());
                    ops.pop();
                    if(ops.empty())cerr<< "括号错误！";
                }
                ops.pop();//把前括号排出去
            }else {
                while(!ops.empty()&&ops.top()!='('&&precede(c,ops.top())<=0){
                    calculateOnce(data,ops.top());
                    ops.pop();
                }
                ops.push(c);
            }
            //before=c;
        }
    }
    while(!ops.empty()){
        calculateOnce(data,ops.top());
        ops.pop();
    }
    return data.top();
    return 0;
}

int main(){
    string s;
    // while(true){
        getline(cin,s);
        cout <<"计算结果是:"<< calculate(s) << endl;
    // }
    return 0;
}