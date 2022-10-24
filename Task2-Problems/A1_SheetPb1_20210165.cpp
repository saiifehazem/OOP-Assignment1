#include <iostream>
using namespace std;
 
int main() {
//Taking string and splitting it into vector of strings
        string text; vector<string> v;
        while( getline(cin, text, ' ')) {
            v.push_back(text);
        }
 
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] =="him" or  v[i] =="her"  ) {
                v[i] = "him or her";
                continue;
            }
            else if (v[i] =="she" or v[i] =="he" ) {
                v[i] = "he or she";
                continue;
            }
            else if (v[i] =="She" or v[i] =="He" ) {
                v[i] = "He or she";
                continue;
            }
            else if (v[i] == "Him" or "Her"){
                v[i] == "Him or her";
                continue;
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            cout <<v[i] <<' ';
        }
}