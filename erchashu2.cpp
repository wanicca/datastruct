#include<iostream>
using namespace std;

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
    int leafsAmount();
    int depth();
    bool similar(TreeNode<T> * dest);
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

template<typename T>
int TreeNode<T>::leafsAmount(){
    int result = 0;
    if(getLeft()!=NULL)result += getLeft()->leafsAmount(); 
    if(getRight()!=NULL)result += getRight()->leafsAmount();
    if(result==0)return 1;
    else return result;
}

template<typename T>
int TreeNode<T>::depth(){
    if(getLeft()==NULL&&getRight()==NULL)return 1;
    else{
        int d1 = (getLeft()==NULL)? 0 : (getLeft()->depth());
        int d2 = (getRight()==NULL)? 0 : (getRight()->depth());
        return d1>d2 ? d1+1 : d2+1;
    }

}

template<typename T>
bool TreeNode<T>::similar(TreeNode<T> * dest){
    bool result = true;
    if(dest!=NULL){
        if(getLeft()!=NULL){
            result = result && getLeft() -> similar(dest->getLeft());
        }else{
            result = result && dest -> getLeft() == NULL;
        }
        if(getRight()!=NULL){
            result = result && getRight() -> similar(dest->getRight());
        }else{
            result = result && dest -> getRight() == NULL;
        }
    }else result = false;
    return result;
}

int main(){
    char c;
    c=cin.get();  
    TreeNode<char> * root1 = new TreeNode<char>(c);
    TreeNode<char> * p = root1;
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
            p->setRight(new TreeNode<char>(c));
            p = p->getRight();
            continue;
        }else{
            p -> setLeft(new TreeNode<char>(c));
            p = p->getLeft();
        }
    }
    c = cin.get();
    TreeNode<char> * root2 = new TreeNode<char>(c);
    p = root2;
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
            p->setRight(new TreeNode<char>(c));
            p = p->getRight();
            continue;
        }else{
            p -> setLeft(new TreeNode<char>(c));
            p = p->getLeft();
        }
    }
    cout << ((root1->similar(root2)) ? "A与B相似" : "A与B不相似" ) << endl;
    return 0;
}