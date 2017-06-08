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
    int leafsAmount();
    int depth();
private:
    T t;
    Node<T> * left;
    Node<T> * right;
    Node<T> * parent;
};
template<typename T>
Node<T>::~Node()
{
    delete left;
    delete right;
}

template<typename T>
int Node<T>::leafsAmount(){
    int result = 0;
    if(getLeft()!=NULL)result += getLeft()->leafsAmount(); 
    if(getRight()!=NULL)result += getRight()->leafsAmount();
    if(result==0)return 1;
    else return result;
}

template<typename T>
int Node<T>::depth(){
    if(getLeft()==NULL&&getRight()==NULL)return 1;
    else{
        int d1 = (getLeft()==NULL)? 0 : (getLeft()->depth());
        int d2 = (getRight()==NULL)? 0 : (getRight()->depth());
        return d1>d2 ? d1+1 : d2+1;
    }

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
    cout << "leafs=" << root->leafsAmount()<<endl;
    cout << "Depth=" << root->depth()<<endl;
    return 0;
}