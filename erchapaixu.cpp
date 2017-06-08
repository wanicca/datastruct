#include <iostream>

using namespace  std;

template<typename T>
class TreeNode
{
public:
    TreeNode(T _t,TreeNode<T> *_left=NULL,TreeNode<T> *_right=NULL,TreeNode<T> *_parent=NULL):t(_t),left(_left),right(_right),parent(_parent){}
    ~TreeNode();
    TreeNode<T> * getLeft(){return left;}
    TreeNode<T> * getRight(){return right;}
    TreeNode<T> * getParent(){return parent;}
    T getData(){return t;}
    void setLeft(TreeNode<T> * n){left = n;n->parent=this;}
    void setRight(TreeNode<T> * n){right = n;n->parent=this;}
private:
    T t;
    TreeNode<T> * left;
    TreeNode<T> * right;
    TreeNode<T> * parent;
};
template<typename T>
TreeNode<T>::~TreeNode()
{
    delete left;
    delete right;
}

template <typename T>
class SortedTree
{
public:
    SortedTree(){};
    ~SortedTree() {if(root!=NULL)delete root;};
    void add(T t);
    void remove(T t);
    void middlePrint();
private:
    TreeNode<T> * root;
};

template<typename T>
void SortedTree<T>::add(T t){
    if(root == NULL){
        root = new TreeNode<T>(t);
    }else{
        TreeNode<T> * p = root;
        while (true){
            if(t > p->getData()){
                if(p->getRight()==NULL){
                    p->setRight(new TreeNode<T>(t));
                    break;
                }else{
                    p = p->getRight();
                }
            }else{
                if(p->getLeft()==NULL){
                    p->setLeft(new TreeNode<T>(t));
                    break;
                }else{
                    p = p->getLeft();
                }
            }
        }
    }
}

template<typename T>
void SortedTree<T>::remove(T t){
    TreeNode<T> * p = root;
    while(true){
        if(p->getData()==t){

        }
    }
}

template<typename T>
void SortedTree<T>::middlePrint(){
    
}
int main(){

    return 0;
}