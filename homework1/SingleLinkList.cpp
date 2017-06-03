#include <iostream>
#include <sstream>
#include <functional>
using namespace std;
template<class T> class Node{
public:
    T element;
    // Node<T> *former;
    Node<T> *next;
    Node(){next = NULL;}
    Node(T _element,Node<T> *_next=NULL):element(_element),next(_next){};
};
template<class T> class LinkedList{
  private:
    Node<T> *head;
    Node<T> *end;
    int len;

  public:
    Node<T> *getHead()const{return head;}
    Node<T> *getEnd()const {return end;}
    Node<T> *getNode(int n)const;
    int length()const {return len;}
    int findAt(T t,int start)const ;
    T& get(int n)const;
    bool set(int n,T t);
    bool insert(int n,T t);
    void append(T t);
    bool remove(int n);
    // bool removeAll(function<bool(T)> filter);
    bool removeAll(bool (*filter)(T t));
    void makeEmpty();
    LinkedList<T> operator+(LinkedList<T>& l);
    LinkedList<T> operator*(LinkedList<T>& l);
    LinkedList<T>& operator=(const LinkedList<T>& l);
    template<class S>friend istream& operator>> (istream& is,LinkedList<S>& l);
    template<class S>friend ostream& operator<< (ostream& os,LinkedList<S>& l);
    LinkedList(){head = new Node<T>;end=head;len = 0;}
    LinkedList(LinkedList<T>& l){
        head = new Node<T>;
        end = head;
        Node<T> *p=l.getHead();
        p = p->next;
        while(p!=NULL){
            append(p->element);
            p = p->next;
        }
    }
    ~LinkedList(){
        makeEmpty();
        delete head;
    }
};


template<class T>
Node<T> * LinkedList<T>::getNode(int n)const{
    if(n>=len||n<0)return NULL;
    Node<T> *p = head->next;
    while(n--)p=p->next;
    return p;
}
template<class T>
int LinkedList<T>::findAt(T t,int start=0)const {
    int at = start;
    Node<T> *p=head->next;
    while(p){
        if(p->element==t)break;
        p=p->next;
        at++;
    }
    if(at==len)return -1;
    return at;
}
template<class T>
T& LinkedList<T>::get(int n)const{
    return getNode(n)->element;
}
template<class T>
bool LinkedList<T>::set(int n,T t){
    Node<T> *p = getNode(n);
    if(p==NULL)return false;
    p->element = t;
    return true;
}
template<class T>
bool LinkedList<T>::insert(int n,T t){
    Node<T> *p;
    if(n>0)
        p = getNode(n-1);
    else
        p = head;
    if(p==NULL)return false;
    Node<T> *q=p->next;
    p->next=new Node<T>(t,q);
    len++;
    return true;
}
template<class T>
void LinkedList<T>::append(T t){
    end -> next = new Node<T>(t);
    end = end-> next;
    len++;
}
template<class T>
bool LinkedList<T>::remove(int n){
    Node<T> *p;
    Node<T> *q;
    if(n>0)
        p = getNode(n-1);
    else
        p = head;
    if(p==NULL||p->next==NULL)return false;
    q = p->next;
    p->next = q->next;
    if(q==end)end=p;
    delete q;
    len--;
    return true;
}
template<class T>
bool LinkedList<T>::removeAll(bool (*filter)(T t)){
// bool LinkedList<T>::removeAll(function<bool(T)> filter){
    Node<T> *p=head;
    Node<T> *q;
    bool flag=false;
    while(p->next!=NULL){
        if(filter(p->next->element)){
            q=p->next;
            p->next = q->next;
            if(q==end)end=p;
            delete q;
            flag = true;
            continue;
        }
        p = p->next;
    }
    return flag;
}
template<class T>
void LinkedList<T>::makeEmpty(){
    while(head->next!=NULL)remove(0);
}
template<class T>
LinkedList<T> LinkedList<T>::operator+(LinkedList<T>& l){
    Node<T> *p=head->next;
    Node<T> *q=l.getHead()->next;
    LinkedList nList;
    while(p!=NULL){
        while(q!=NULL && q->element < p->element){
            nList.append(q->element);
            q = q->next;
        }
        nList.append(p->element);
        p = p->next;
    }
    while(q!=NULL){
        nList.append(q->element);
        q = q->next;
    }
    return nList;
}
template<class T>
LinkedList<T> LinkedList<T>::operator*(LinkedList<T>& l){
    Node<T> *p=head->next;
    Node<T> *start=l.getHead()->next;
    LinkedList nList;
    while(p!=NULL){
        Node<T> *q = start;
        while(q!=NULL && q->element != p->element){
            q = q->next;
        }
        if(q){
            nList.append(p->element);
            start = q->next;
            if(start==NULL){
                break;
            }
        }
        p = p->next;
    }
    return nList;
}
template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& l){
    makeEmpty();
    end = head;
    const Node<T> *p=l.getHead()->next;
    while(p!=NULL){
        append(p->element);
        p = p->next;
    }
    return *this;
}

template<class T>
istream& operator>>(istream& is,LinkedList<T>& l){
    string s;
    getline(is,s);
    istringstream istr(s);
    T t;
    while(istr >> t){
        l.append(t);
    }
    return is;
}

template<class T>
ostream& operator<<(ostream& os,LinkedList<T>& l){
    Node<T> *p = l.getHead()->next;
    while(p!=NULL){
        if(p->next!=NULL)
            os << p->element << ' ';
        else os << p->element;
        p = p->next;
    }
    cout << endl;
    return os;
}
