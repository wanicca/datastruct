#include "iostream"
#include "SeqList.cpp"
using namespace std;
int main(){
    SeqList<int> insertMe;
    int t;
    while(true){
        cin >> t;
        insertMe.insert(t);
        cout << insertMe;
    }

    return 0;
}
