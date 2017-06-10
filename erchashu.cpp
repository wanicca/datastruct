#include<iostream>
using namespace std;

template<typename T>
class Node
{
public:
    Node(T _t,Node<T> *_left=NULL,Node<T> *_right=NULL,Node<T> *_parent=NULL):t(_t),left(_left),right(_right),parent(_parent){}
    ~Node();
    Node<T> * getLeft(){return left;}
    Node<T> * getRight(){return right;}
    Node<T> * getParent(){return parent;}
    T getData(){return t;}
    void setLeft(Node<T> * n){left = n;n->parent=this;}
    void setRight(Node<T> * n){right = n;n->parent=this;}
private:
    T t;
    Node<T> * left;
    Node<T> * right;
    Node<T> * parent;
};
template<typename T>
Node<T>::~Node()
{
    if(left!=NULL)delete left;
    if(right!=NULL)delete right;
}

template<typename T>
void firstPrint(Node<T> * t){
    cout << t->getData() <<' ';
    if(t->getLeft()!=NULL){
        firstPrint(t->getLeft());
    }
    if(t->getRight()!=NULL){
        firstPrint(t->getRight());
    }
}
// template<typename T>
// void firstPrint2(Node<T> * t){
//     Node<T> * p = t;
//     while(p!=t->getParent()){
//         cout << p->getData();
//         if(p->getLeft()!=NULL)
//             p = p->getLeft();
//         else if(p->getRight()!=NULL)
//             p = p->getRight();
//         else {
//             for(;(p!=t->getParent()&&p->getRight()==NULL);p=p->parent());
//             p = p->getRight();
//         }
//     }
// }


template<typename T>
void middlePrint(Node<T> * t){
    if(t->getLeft()!=NULL){
        middlePrint(t->getLeft());
    }
    cout << t->getData() <<' ';
    if(t->getRight()!=NULL){
        middlePrint(t->getRight());
    }
}

template<typename T>
void lastPrint(Node<T> * t){
    if(t->getLeft()!=NULL){
        lastPrint(t->getLeft());
    }
    if(t->getRight()!=NULL){
        lastPrint(t->getRight());
    }
    cout << t->getData() <<' ';
}

int main(){
    char c;
    c=cin.get();
    Node<char> * root = new Node<char>(c);
    Node<char> * p = root;
    while((c = cin.get())!='\n'){
        if(c=='#'){
            while((c=cin.get())=='#'){
                if(p->getParent()==NULL){
                    c = '\n';
                    break;
                }
                while(p->getParent()->getParent()!=NULL&&p==p->getParent()->getRight()){
                    p = p->getParent();
                }
                if(p->getParent()!=NULL)p = p->getParent();
            }
            if(c=='\n')break;
            p->setRight(new Node<char>(c));
            p = p->getRight();
            continue;
        }else{
            p -> setLeft(new Node<char>(c));
            p = p->getLeft();
        }
    }
    cout << "前序遍历结果：";
    firstPrint(root);
    cout << '\n';
    cout << "中序遍历结果：";
    middlePrint(root);
    cout << '\n';
    cout << "后序遍历结果：";
    lastPrint(root);
    cout << '\n';
    return 0;
}