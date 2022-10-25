#include <bits/stdc++.h>

using namespace std;

int main() {
//Taking string and splitting it into vector of strings
    string text;
    vector<string> v;
    getline(cin, text);
    text += ' ';
    int k = 0;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ') {
            v.push_back(text.substr(k, i - k));
            k = i + 1;
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        string word2, word3;
        char punct2 = v[i][2], punct3 = v[i][3];
        word2 = v[i].substr(0, 2);
        word3 = v[i].substr(0, 3);
        if ((word3 == "him" or word3 == "her") && ispunct(punct3)) {
            v[i] = "him or her";
            v[i] += punct3;
            continue;
        } else if ((word3 == "she" && ispunct(punct3)) or (word2 == "he" && ispunct(punct2))) {
            v[i] = "he or she";
            if (ispunct(punct3)) v[i] += punct3;
            else v[i] += punct2;
            continue;
        } else if ((word3 == "She" && ispunct(punct3)) or (word2 == "He" && ispunct(punct2))) {
            v[i] = "He or she";
            if (ispunct(punct3)) v[i] += punct3;
            else v[i] += punct2;
            continue;
        } else if ((word3 == "Him" or word3 == "Her") && ispunct(punct3)) {
            v[i] == "Him or her";
            v[i] += punct3;
            continue;
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    return 0;

}