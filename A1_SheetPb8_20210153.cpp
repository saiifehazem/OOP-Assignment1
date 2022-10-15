#include <iostream>
#include <vector>
using namespace std;

template <typename T> class smartArray{
    T* arr;
    int capacity;
    int current;
public:
    smartArray(){
        arr = new T[1];
        capacity = 1;
        current =0;
    }
    smartArray(smartArray<T>& anotherArr){
        current = anotherArr.current;
        capacity = anotherArr.capacity;
        arr = new T[capacity];
        for(size_t i=0;i<capacity;i++){
            arr[i] = anotherArr[i];
        }
    }
    ~smartArray(){
        delete [] arr;
    }
    int Size(){
        return current;
    }
    void push(T data){
        if(current == capacity){
            T* temp = new T[2 * capacity];
            for(int i=0;i<capacity;i++){
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *=2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }
    int& operator[](int index){
        return arr[index];
    }


};
int main(){
    smartArray<int>sa;
    sa.push(10);
    sa.push(20);
    sa.push(80);
    cout<<sa.Size()<<endl;
    cout<<sa[0]<<" "<<sa[1]<<" "<<sa[2]<<endl;
    smartArray<int>sa2 = sa;
    sa2[1]=88;
    cout<<sa2[0]<<" "<<sa2[1]<<" "<<sa2[2]<<endl;
    smartArray<int>sa3(sa);
    cout<<sa3[0]<<" "<<sa3[1]<<" "<<sa3[2]<<endl;

}