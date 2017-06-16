#include <iostream>
using namespace std;


//由小到大排序
template<typename T>
T * bubbleSort(T * list,int size){
    for (int i = 0; i < size; i++)
    {   
        bool exchange = false;
        for(int j=size-1;j>i;j--){
            if(list[j-1]>list[j]){
                T temp = list[j-1];
                list[j-1]=list[j];
                list[j]=temp;
                exchange=true;
            }
        }
        cout << "第" << i + 1 << "次排序后:";
        for(int j = 0;j<size;j++){
            cout << list[j] << ' ';
        }
        cout << endl;
        if(!exchange){
            break;
        }
    }
    return list;
}

int main(){
    int a[] = {8,7,6,1,4,5,2,3};
    bubbleSort(a,8);
    return 0;
}
/*
        ./datastruct/paixu.o
第1次排序后:1 8 7 6 2 4 5 3
第2次排序后:1 2 8 7 6 3 4 5
第3次排序后:1 2 3 8 7 6 4 5
第4次排序后:1 2 3 4 8 7 6 5
第5次排序后:1 2 3 4 5 8 7 6
第6次排序后:1 2 3 4 5 6 8 7
第7次排序后:1 2 3 4 5 6 7 8
第8次排序后:1 2 3 4 5 6 7 8

可以观察到第一次排序后5向右移动了，但其最终应当向左移动。
*/