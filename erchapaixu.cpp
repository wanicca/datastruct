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
    TreeNode<T> * middleNext();
    T getData(){return t;}
    void setData(T _t){t = _t;}
    void setLeft(TreeNode<T> * n){left = n;if(n!=NULL)n->parent=this;}
    void setRight(TreeNode<T> * n){right = n;if(n!=NULL)n->parent=this;}
    void deleteLeft();
    void deleteRight();
private:
    T t;
    TreeNode<T> * left;
    TreeNode<T> * right;
    TreeNode<T> * parent;
};
template<typename T>
TreeNode<T>::~TreeNode()
{
    // 移除递归删除
    // if(left!=NULL)delete left;
    // if(right!=NULL)delete right;
}
template<typename T>
void TreeNode<T>::deleteLeft(){
    if(getLeft()!=NULL){
        getLeft()->deleteLeft();
        delete left;
    }
}

template<typename T>
void TreeNode<T>::deleteRight(){
    if(getRight()!=NULL){
        getRight()->deleteRight();
        delete right;
    }
}

template<typename T>
TreeNode<T> * TreeNode<T>::middleNext(){
    TreeNode<T> * p = NULL;
    if(getRight()!=NULL){
        p = getRight();
        while(p->getLeft()!=NULL)p=p->getLeft();
    }else if(getParent()!=NULL){
        if(this == getParent()->getLeft()){
            p = getParent();
        }else{
            p = getParent();
            while(p->getParent()!=NULL&&p==p->getParent()->getRight()){
                p = p->getParent();
            }
            p = p->getParent();
        }
    }
    return p;
}

template <typename T>
class SortedTree
{
public:
    SortedTree(){root = NULL;};
    ~SortedTree();
    TreeNode<T> * middleFirst();
    bool remove(T t);
    void add(T t);
    void removeNode(TreeNode<T> * node);
    void middlePrint();
private:
    TreeNode<T> * root;
};

template<typename T>
SortedTree<T>::~SortedTree(){
    if(root!=NULL){
        root->deleteLeft();
        root->deleteRight();
    }
}

template<typename T>
TreeNode<T> * SortedTree<T>::middleFirst(){
    TreeNode<T> *p = root;
    while(p->getLeft()!=NULL){
        p = p->getLeft();
    }
    return p;
}

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
bool SortedTree<T>::remove(T t){
    TreeNode<T> * p = root;
    while(true){
        if(p==NULL)return false;
        if(p->getData()==t){
            //TODO 找到后删除
            removeNode(p);
            break;
        }else{
            if(t>p->getData())p = p->getRight();
            else p = p->getLeft();
        }
    }
    return true;
}

template<typename T>
void SortedTree<T>::removeNode(TreeNode<T> * node){
    if(node == NULL) return ;
    if(node->getLeft()==NULL){
        if(node->getRight()==NULL){
            if(node == root){
                root = NULL;
                delete node;
            }else if(node==node->getParent()->getLeft()){
                node->getParent()->setLeft(NULL);
                delete node;
            }else{
                node->getParent()->setRight(NULL);
                delete node;
            }
        }else{
            if(node == root){
                root = node -> getRight();
                delete node;
            }else if(node==node->getParent()->getLeft()){
                node->getParent()->setLeft(node->getRight());
                delete node;
            }else{
                node->getParent()->setRight(node->getRight());
                delete node;
            }
        }
    }else{
        if(node->getRight()==NULL){
            if(node == root){
                root = node -> getLeft();
                delete node;
            }else if(node==node->getParent()->getLeft()){
                node->getParent()->setLeft(node->getLeft());
                delete node;
            }else{
                node->getParent()->setRight(node->getRight());
                delete node;
            }
        }else{
            TreeNode<T> * next = node->middleNext();
            node -> setData(next -> getData());
            removeNode(next);
        }
    }
}

template<typename T>
void SortedTree<T>::middlePrint(){
    TreeNode<T> * p = middleFirst();
    while(p!=NULL){
        cout << p->getData() << "  ";
        p = p->middleNext();
    }
    cout << endl;
}
int main(){
    int n,t;
    SortedTree<int> st;
    cin >> n;
    cout << "原始数据：";
    while(n--){
        cin >> t;
        cout << t << " ";
        st.add(t);
    }
    cout << endl;
    cout << "中序遍历结果：";
    st.middlePrint();
    cin >> t;
    cout << "删除结点后结果：";
    if(st.remove(t))
        st.middlePrint();
    else
        cout << "没有" << t << "结点。" << endl;
    return 0;
}