#include <iostream>

using namespace std;

static void binaryPrint(int n) {
    if (n < 2) {
        cout << n;
    } else {
        binaryPrint(n / 2);
        cout << n % 2;
    }
}

static void num(string prefix, int k) {
    // string prefix is a string of 0 and 1
    // int k is all the combinations of 0 and 1 which put after prefix
    if (k == 0) {
        cout << prefix << endl;
    } else {
        num(prefix + "0", k - 1);
        num(prefix + "1", k - 1);
    }
}

int main() {
    cout << "Enter your choice of number: \n 1-Binary Print \n 2- Binary Combinations \n";
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "Enter a number: ";
        int n;
        cin >> n;
        binaryPrint(n);
        cout << endl;
    } else if (choice == 2) {
        string prefix;
        int k;
        cin >> prefix >> k;
        num(prefix, k);
        cout << endl;
    }
}