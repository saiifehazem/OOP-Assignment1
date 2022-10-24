#include <iostream>
using namespace std;

static void binaryPrint(int n){
    if(n == 0){
        return;
    }
    binaryPrint(n/2);
    cout << n%2;
}


static void numbers(string prefix, int k){
    //The number k is non-negative.
    //The argument called prefix is a strong of 0's and 1's
    // find out All possible combinations of the prefix and k-digit suffix
    if (k == 0){
        cout << prefix << endl;
    } else {
        numbers(prefix + "0", k - 1);
        numbers(prefix + "1", k - 1);
    }
}

int main {
	binaryPrint (4);
	numbers ( "00101",2)
}