#include <iostream>
using namespace std;


//假定list由小到大排序
//找到时返回下标，找不到返回-1
template<typename T>
int find(T t,T * list,int left,int right){
    if(left==right){
        if(t==list[left]){
            return left;
        }
        else return -1;
    }
    int middle = (left+right)/2;
    if(list[middle]==t){
        return middle;
    }
    else if(list[middle]<t){
        return find(t,list,middle+1,right);
    }else{
        return find(t,list,left,middle-1);
    }
}
template<typename T>
int find(T t, T * list,int size){
    return find(t,list,0,size-1);
}

int main(){
    int a[2]={1,2};
    int b;
    cin >> b;
    int i = find(b,a,2);
    if(i!=-1){
        cout << i << endl; 
    }
    return 0;
}