#include "iostream"
using namespace std;
template <typename T>
class SeqList {
private:
    T *elements;
    int maxsize,len;

public:
    SeqList (int _maxsize=10):maxsize(_maxsize){elements = new T[maxsize];len=0;}
    bool insert(T t);
    bool set(int n,T t){
        if(n<maxsize){
            elements[n]=t;
            return true;
        }else{
            return false;
        }
    }
    T get(int n){
        return elements[n];
    }
    template <typename S>
    friend ostream& operator<<(ostream& os,SeqList<S>& s);
    virtual ~SeqList (){
        delete [] elements;
    }
};
template <typename T>
bool SeqList<T>::insert(T t){
    int i;
    for(i=0;i<len;i++){
        if(elements[i]>t)break;
    }
    if(len<maxsize){
        for(int j=len;j>i;j--){
            elements[j]=elements[j-1];
        }
        elements[i]=t;
        len++;
    }else{
        cout << "到达上限" << endl;
        return false;
    }
}
template<class T>
ostream& operator<<(ostream& os,SeqList<T>& s){
    for(int i=0;i<s.len;i++){
        cout << s.get(i) << " ";
    }
    cout << endl;
    return os;
}
