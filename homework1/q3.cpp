#include "iostream"
#include "SingleLinkList.cpp"
#include "functional"
int x,y;
bool myfilter(int t){
    return t>x&&t<y;
}
int main(int argc, char const *argv[]) {
    LinkedList<int> l;
    cin >> l; // 先输入一行链表的元素，构建链表
    // int x,y;
    cin >> x >> y;
    //原先用函数指针
    bool (*filter)(int) = myfilter;
    // function<bool(int)> filter= [=] (int t) -> bool{return t > x && t < y ;}; //听说C++11支持lambda了，加上std=c++11发现这样写更简单。
    if(l.removeAll(filter)){
        cout << "删除成功！目前链表元素如下：" <<endl;
        cout << l;
    } else{
        cout << "删除失败，无符合条件的元素。" <<endl;
    }

    return 0;
}
