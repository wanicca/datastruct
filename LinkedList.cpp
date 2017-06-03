#include <iostream>
using namespace std;
template<class T> class SingleLinkList:public AbLinklist<T>{
  private:
    Node<T> head;
    int len;

  public:
    // int length(){return len;}
    T& get(int n);
    int findAt(T t);
    bool set(int n,T t);
    bool insert(int n,T t);
    bool remove(int n);
    void clear();
};

T& SingleLinkList::get(int n){
    return getNode(n)->element;
}

bool SingleLinkList::set(int n,T t){
    Node<T> *p = getNode(n);
    if(p==NULL)return false;
    p->element = t;
    return true;
}

bool SingleLinkList::insert(int n,T t){
    Node<T> *p;
    if(n>0)
        p = getNode(n-1);
    else
        p = head;
    if(p==NULL)return false;
    q=p->next;
    p->next=new Node<T>(t,q);
    return true;
}
