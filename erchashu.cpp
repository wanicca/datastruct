#include<iostream>
using namespace std;

template<typename T>
class Node
{
public:
    Node(T _t,Node<T> *_left=NULL,Node<T> *_right=NULL):t(_t),left(_left),right(_right){}
    ~Node();
    Node<T> * getLeft(){return left;}
    Node<T> * getRight(){return right;}
    Node<T> * getParent(){return parent;}
    void setLeft(Node<T> * n){left = n;n->parent=this;}
    void setRight(Node<T> * n){right = n;n->parent=this;}
private:
    Node<T> * left;
    Node<T> * right;
    Node<T> * parent;
    T t;
};
template<typename T>
Node<T>::~Node()
{
    delete left;
    delete right;
}

int main(){
    Node<char> * root = new Node<char>('0');
    Node<char> * p = root;
    char c;
    while((c = cin.get())!='\n'){
        
    }
    return 0;
}