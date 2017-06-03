#include "iostream"
using namespace std;
template<class T> class Node{
  private:
    T element;
    // Node<T> *former;
    Node<T> *next;
  public:
    Node(){*next = NULL;}
    Node(T _element,Node<T> *_next=NULL):element(_element),next(_next){};
};
template<class T> class AbLinklist:public List{
protected:
    Node<T> head;
    int len;

public:
    virtual Node<T> *getNode(int n);
    virtual Node<T> *getHead(){return head;}
    virtual int findAt(T t);
    int length(){return len;}
    T& get(int n){return getNode(n)->element;}


};

Node<T> * AbLinkList::getNode(int n){
    if(n>=len||n<0)return NULL;
    Node<T> *p = head.next;
    while(n--)p=p.next;
    return p;
}
