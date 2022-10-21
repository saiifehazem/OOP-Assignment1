#include <bits/stdc++.h>

#ifndef ASSIGNMENT1_BIGDECIMALINT_BIGDECIMALINT_H
#define ASSIGNMENT1_BIGDECIMALINT_BIGDECIMALINT_H

using namespace std;

class BigDecimalInt {

private:
string numStr;
vector <int> numA ={0} ;
char nSign = '+';

public:
    BigDecimalInt();
    explicit BigDecimalInt(string decStr);
    //BigDecimalInt(int decInt);

    BigDecimalInt operator + (BigDecimalInt anotherDec);
    BigDecimalInt operator - (BigDecimalInt anotherDec);
    //bool operator < ( BigDecimalInt anotherDec);
    //bool operator > ( BigDecimalInt anotherDec);
    bool operator == (BigDecimalInt anotherDec);
    BigDecimalInt& operator =(const BigDecimalInt& anotherDec);
    int size();
    string sign();
    friend ostream &operator<<(ostream &out, BigDecimalInt &b);

};


#endif //ASSIGNMENT1_BIGDECIMALINT_BIGDECIMALINT_H
