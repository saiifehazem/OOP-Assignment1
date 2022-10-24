#include "BigDecimalInt.h"

//Constructors
BigDecimalInt::BigDecimalInt() {
}
BigDecimalInt::BigDecimalInt(string decStr):numStr(decStr) {
    bool isNum = true;

    if ( numStr[0] == '+' or numStr [0] == '-' ) {
        for (int i = 1; i < numStr.length(); ++i) {
            isNum = isdigit ( numStr[i] );
            if (isNum == false)  break;
            numA.push_back(numStr[i] - '0');
        }
        if (numStr[0] == '+' ) nSign = '+';
        else nSign = '-';
    }
    else if ( isdigit ( numStr[0] ) == 1 ) {

        for (int i = 0; i < numStr.length(); ++i){
            if (isdigit(numStr[i])) numA.push_back( numStr[i] - '0' );
            else {
                isNum = false;
                //numA.erase(numA.begin(),numA.end());
                numA={0};
                break;
            }
        }
    }

    //Removing any leading zeros
    for (int i = 0; i < numA.size(); ++i) {
        if ( numA[0] == 0 ) numA.erase(numA.begin());
        else break;
    }

    if ( !isNum ) cout<<"Please enter a valid number !\n";
}
BigDecimalInt::BigDecimalInt(int decInt) {
}

//Destructor
BigDecimalInt::~BigDecimalInt() {
    //
}

//Function returns size of the number
int BigDecimalInt::size() {
    return numA.size();
}

//Function returns sign of the number
int BigDecimalInt::sign() {
    if (nSign == '+') return 1;
    else return -1;

}

//Function to print the number
void BigDecimalInt::print() {
    cout << nSign;
    for (int i = 0; i < numA.size(); ++i) {
        cout << numA[i];
    }
    cout << endl;

}

//Operators
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec) {
    int mn = min(numA.size(), anotherDec.numA.size());
    int mx = max(numA.size(), anotherDec.numA.size());
    int lp = mx - mn ;
    int sz1 = numA.size(), sz2 = anotherDec.numA.size();
    vector<int> temp(mx) ;
    stringstream result;
    string finalNum = "";
    reverse(numA.begin(), numA.end());
    reverse(anotherDec.numA.begin(), anotherDec.numA.end());
    if( numA.size() > anotherDec.numA.size() ) {
        for (int i = 0; i < lp; ++i) {
            anotherDec.numA.push_back(0);
        }
    }
    else if (  numA.size() < anotherDec.numA.size()) {
        for (int i = 0; i < lp; ++i) {
            numA.push_back(0);
        }
    }

    if ( nSign == '+'  && anotherDec.nSign == '+' ) {
        for (int i = 0; i < mx; ++i) {
            if (numA[i] + anotherDec.numA[i] > 10) {
                temp[i] = (numA[i] + anotherDec.numA[i]) % 10;
                numA[i + 1] += 1;
            } else {
                temp[i] = numA[i] + anotherDec.numA[i];
            }
        }
        reverse(temp.begin(), temp.end());
        copy(temp.begin(), temp.end(), ostream_iterator<int>(result, ""));
        finalNum = result.str();
    }
    else if ( nSign == '-'  && anotherDec.nSign == '-' ) {
        for (int i = 0; i < mx; ++i) {
            if (numA[i] + anotherDec.numA[i] > 10) {
                temp[i] = (numA[i] + anotherDec.numA[i]) % 10;
                numA[i + 1] += 1;
            } else {
                temp[i] = numA[i] + anotherDec.numA[i];
            }
        }
        reverse(temp.begin(), temp.end());
        copy(temp.begin(), temp.end(), ostream_iterator<int>(result, ""));
        finalNum = result.str();
        finalNum = '-' + finalNum;
    }

    else if ( nSign == '+'  && anotherDec.nSign == '-' ) {
        if ( sz1 >= sz2  ) {
            for (int i = 0; i < mx; ++i) {
                if ( numA[i] - anotherDec.numA[i] < 0 ) {
                    numA[i+1] -= 1;
                    temp[i] = numA[i] + 10 - anotherDec.numA[i];
                }
                else {
                    temp[i] = numA[i]  - anotherDec.numA[i];
                }
            }
            reverse(temp.begin(), temp.end());
            copy(temp.begin(), temp.end(), ostream_iterator<int>(result, ""));
            finalNum = result.str();
        }
        else if ( sz1 < sz2) {
            for (int i = 0; i < mx; ++i) {
                if ( - numA[i] + anotherDec.numA[i] < 0 ) {
                    anotherDec.numA[i+1] -= 1;
                    temp[i] = anotherDec.numA[i] + 10 - numA[i];
                }
                else {
                    temp[i] = anotherDec.numA[i]  - numA[i];
                }
            }
            reverse(temp.begin(), temp.end());
            copy(temp.begin(), temp.end(), ostream_iterator<int>(result, ""));
            finalNum = result.str();
            finalNum = '-' + finalNum;
        }

    }
    else if ( nSign == '-'  && anotherDec.nSign == '+' ) {
        if ( sz2 >= sz1  ) {
            for (int i = 0; i < mx; ++i) {
                if ( anotherDec.numA[i] - numA[i] < 0 ) {
                    anotherDec.numA[i+1] -= 1;
                    temp[i] = anotherDec.numA[i] + 10 - numA[i];
                }
                else {
                    temp[i] = anotherDec.numA[i]  - numA[i];
                }
            }
            reverse(temp.begin(), temp.end());
            copy(temp.begin(), temp.end(), ostream_iterator<int>(result, ""));
            finalNum = result.str();
        }
        else if ( sz2 < sz1) {
            for (int i = 0; i < mx; ++i) {
                if ( - anotherDec.numA[i] + numA[i] < 0 ) {
                    numA[i+1] -= 1;
                    temp[i] = numA[i] + 10 - anotherDec.numA[i];
                }
                else {
                    temp[i] = numA[i]  - anotherDec.numA[i];
                }
            }
            reverse(temp.begin(), temp.end());
            copy(temp.begin(), temp.end(), ostream_iterator<int>(result, ""));
            finalNum = result.str();
            finalNum = '-' + finalNum;
        }

    }
    BigDecimalInt answer(finalNum);
    return answer;
}
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec){
    int mn = min(numA.size(), anotherDec.numA.size()) , mx = max(numA.size(), anotherDec.numA.size());
    int lp = mx - mn ;
    int sz1 = numA.size(), sz2 = anotherDec.numA.size();
    vector<int> temp(mx) ;
    stringstream result;
    string finalNum = "";
    reverse(numA.begin(), numA.end());
    reverse(anotherDec.numA.begin(), anotherDec.numA.end());
    if( numA.size() > anotherDec.numA.size() ) {
        for (int i = 0; i < lp; ++i) {
            anotherDec.numA.push_back(0);
        }
    }
    else if (  numA.size() < anotherDec.numA.size()) {
        for (int i = 0; i < lp; ++i) {
            numA.push_back(0);
        }
    }

    if (nSign == '+' && anotherDec.nSign == '-'){
        for (int i = 0; i < mx; ++i) {
            if (numA[i] + anotherDec.numA[i] > 10) {
                temp[i] = (numA[i] + anotherDec.numA[i]) % 10;
                numA[i + 1] += 1;
            } else {
                temp[i] = numA[i] + anotherDec.numA[i];
            }
        }
        reverse(temp.begin(), temp.end());
        copy(temp.begin(), temp.end(), ostream_iterator<int>(result, ""));
        finalNum = result.str();
    }
    else if ( nSign =='-' && anotherDec.nSign =='+'){
        for (int i = 0; i < mx; ++i) {
            if (numA[i] + anotherDec.numA[i] > 10) {
                temp[i] = (numA[i] + anotherDec.numA[i]) % 10;
                numA[i + 1] += 1;
            } else {
                temp[i] = numA[i] + anotherDec.numA[i];
            }
        }
        reverse(temp.begin(), temp.end());
        copy(temp.begin(), temp.end(), ostream_iterator<int>(result, ""));
        finalNum = result.str();
        finalNum = '-' + finalNum;
    }
    else if (nSign == '+' && anotherDec.nSign =='+'){
        if ( sz1 >= sz2  ) {
            for (int i = 0; i < mx; ++i) {
                if ( numA[i] - anotherDec.numA[i] < 0 ) {
                    numA[i+1] -= 1;
                    temp[i] = numA[i] + 10 - anotherDec.numA[i];
                }
                else {
                    temp[i] = numA[i]  - anotherDec.numA[i];
                }
            }
            reverse(temp.begin(), temp.end());
            copy(temp.begin(), temp.end(), ostream_iterator<int>(result, ""));
            finalNum = result.str();
        }
        else if ( sz1 < sz2) {
            for (int i = 0; i < mx; ++i) {
                if ( - numA[i] + anotherDec.numA[i] < 0 ) {
                    anotherDec.numA[i+1] -= 1;
                    temp[i] = anotherDec.numA[i] + 10 - numA[i];
                }
                else {
                    temp[i] = anotherDec.numA[i]  - numA[i];
                }
            }
            reverse(temp.begin(), temp.end());
            copy(temp.begin(), temp.end(), ostream_iterator<int>(result, ""));
            finalNum = result.str();
            finalNum = '-' + finalNum;
        }
    }
    else if (nSign == '-' && anotherDec.nSign == '-'){
        if ( sz2 >= sz1  ) {
            for (int i = 0; i < mx; ++i) {
                if ( anotherDec.numA[i] - numA[i] < 0 ) {
                    anotherDec.numA[i+1] -= 1;
                    temp[i] = anotherDec.numA[i] + 10 - numA[i];
                }
                else {
                    temp[i] = anotherDec.numA[i]  - numA[i];
                }
            }
            reverse(temp.begin(), temp.end());
            copy(temp.begin(), temp.end(), ostream_iterator<int>(result, ""));
            finalNum = result.str();
        }
        else if ( sz2 < sz1) {
            for (int i = 0; i < mx; ++i) {
                if ( - anotherDec.numA[i] + numA[i] < 0 ) {
                    numA[i+1] -= 1;
                    temp[i] = numA[i] + 10 - anotherDec.numA[i];
                }
                else {
                    temp[i] = numA[i]  - anotherDec.numA[i];
                }
            }
            reverse(temp.begin(), temp.end());
            copy(temp.begin(), temp.end(), ostream_iterator<int>(result, ""));
            finalNum = result.str();
            finalNum = '-' + finalNum;
        }
    }



    BigDecimalInt answer(finalNum);
    return answer;
}
bool BigDecimalInt::operator==(BigDecimalInt anotherDec) {
    stringstream num1 , num2;
    copy(numA.begin(), numA.end(), ostream_iterator<int>(num1, ""));
    copy(anotherDec.numA.begin(), anotherDec.numA.end(), ostream_iterator<int>(num2, ""));
    if ( num2.str() == num1.str() &&  nSign == anotherDec.nSign ) {
        return true;
    }
    else return false ;
}
bool BigDecimalInt::operator > (BigDecimalInt anotherDec) {
    stringstream num1, num2;
    copy(numA.begin(), numA.end(), ostream_iterator<int>(num1, ""));
    copy(anotherDec.numA.begin(), anotherDec.numA.end(), ostream_iterator<int>(num2, ""));
    if ( nSign == '+' && anotherDec.nSign == '-' ) return true;
    else if ( nSign == '-' && anotherDec.nSign == '+' ) return false;
    else if ( nSign == '+' && anotherDec.nSign == '+' ) {
        if ( numA.size() > anotherDec.numA.size() ) return true;
        else if ( numA.size() < anotherDec.numA.size() ) return false;
        else {
            for (int i = 0; i < numA.size(); ++i) {
                if ( numA[i] > anotherDec.numA[i] ) return true;
                else if ( numA[i] < anotherDec.numA[i] ) return false;
            }
        }
    }
    else if ( nSign == '-' && anotherDec.nSign == '-' ) {
        if ( numA.size() > anotherDec.numA.size() ) return false;
        else if ( numA.size() < anotherDec.numA.size() ) return true;
        else {
            for (int i = 0; i < numA.size(); ++i) {
                if ( numA[i] > anotherDec.numA[i] ) return false;
                else if ( numA[i] < anotherDec.numA[i] ) return true;
            }
        }
    }
    return false;
}
bool BigDecimalInt::operator < (BigDecimalInt anotherDec) {
    stringstream num1, num2;
    copy(numA.begin(), numA.end(), ostream_iterator<int>(num1, ""));
    copy(anotherDec.numA.begin(), anotherDec.numA.end(), ostream_iterator<int>(num2, ""));
    if ( nSign == '+' && anotherDec.nSign == '-' ) return false;
    else if ( nSign == '-' && anotherDec.nSign == '+' ) return true;
    else if ( nSign == '+' && anotherDec.nSign == '+' ) {
        if ( numA.size() > anotherDec.numA.size() ) return false;
        else if ( numA.size() < anotherDec.numA.size() ) return true;
        else {
            for (int i = 0; i < numA.size(); ++i) {
                if ( numA[i] > anotherDec.numA[i] ) return false;
                else if ( numA[i] < anotherDec.numA[i] ) return true;
            }
        }
    }
    else if ( nSign == '-' && anotherDec.nSign == '-' ) {
        if ( numA.size() > anotherDec.numA.size() ) return true;
        else if ( numA.size() < anotherDec.numA.size() ) return false;
        else {
            for (int i = 0; i < numA.size(); ++i) {
                if ( numA[i] > anotherDec.numA[i] ) return true;
                else if ( numA[i] < anotherDec.numA[i] ) return false;
            }
        }
    }
    return false;
}
ostream &operator<<(ostream &out, BigDecimalInt b) {
    cout << b.nSign;
    for (int i : b.numA) {
        cout << i;
    }
    return cout;
}






