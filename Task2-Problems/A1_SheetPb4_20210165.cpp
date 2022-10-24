#include <iostream>
using namespace std;

static void binaryPrint(int n){
    if(n < 2){
        cout << n;
    }else{
        binaryPrint(n/2);
        cout << n%2;
    }
}

static void num (string prefix , int k){
    // string prefix is a string of 0 and 1
    // int k is all the combinations of 0 and 1 which put after prefix
    if (k == 0){
        cout << prefix << endl;
    }else{
        num(prefix + "0", k-1);
        num(prefix + "1", k-1);
    }
}

int main() {
    binaryPrint (4); cout << endl;
    num ( "00101",2);
}