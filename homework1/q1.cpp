#include <iostream>
#include "SingleLinkList.cpp"
using namespace std;

int main(){
    LinkedList<int> a,b,c;
    cin >> a;
    cin >> b;
    c=a*b;
    if(c.length()!=0)
        cout << c;
    else
        cout << "没有交集" <<endl;
    return 0;
}
