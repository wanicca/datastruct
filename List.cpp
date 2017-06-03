#include <iostream>
using namespace std;
template<class T> class List
{
public:
    List()
    {
    }
    virtual int length()=0;
    virtual T& get(int n)=0;
    virtual int findAt(T t);
    virtual bool set(int n,T t)=0;
    virtual bool insert(int n,T t)=0;
    virtual bool remove(int n)=0;
    virtual void clear()=0;
    virtual ~List()=0;
    virtual T& operator[](int n){return get(n);}
private:

};
