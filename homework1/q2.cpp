#include <iostream>
#include "SingleLinkList.cpp"

int main(int argc, char const *argv[]) {
    LinkedList<int> a;
    cin >> a;
    int t;
    cin >> t;
    int n = a.findAt(t);
    if(n-1<0){
        cout<<"该结点没有前驱结点"<<endl;
    }
    else{
        a.remove(n-1);
        cout << a;
    }
    return 0;
}
