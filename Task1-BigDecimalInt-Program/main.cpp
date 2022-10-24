#include <bits/stdc++.h>
#include "BigDecimalInt.h"
#include "BigDecimalInt.cpp"

using namespace std;

int main() {
    BigDecimalInt z("21354513");
    cout<<z.size();
    cout<<z.sign();
    cout<<z;
    BigDecimalInt y = z;
    cout<<y;
    y.print();
}