// 第二种格式


#include <iostream>

using namespace std;

template<class T>

class Test

{

public:

    template<class S>                   // 注意<class S>S
    friend ostream& operator << (ostream& out, const Test<S>& obj);


    Test(T n = 0) :num(n) {}



    Test(const Test<T>& copy)
    {
        num = copy.num;
    }



private:

    T num;

};


// 注意<class T>和<class S>都行

template<class T>
ostream& operator << (ostream& out, const Test<T>& obj)
{
    out << obj.num << endl;

    return out;
}


int main(){
    Test<int> t(2);

    cout << t;

    return 0;
}  
