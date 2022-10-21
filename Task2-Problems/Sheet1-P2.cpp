#include <bits/stdc++.h>
using namespace std;
vector<string> split(string target , string delimiter){
    vector<string> answer ;
    string substring ;
    for(int i =0 ; i<target.size();i++){
        if (target[i] != delimiter[0])
            substring += target[i];
        else if (target[i] == delimiter[0]){
            string del ;
            del = target.substr(i,delimiter.size());
            if (del == delimiter) {
                i = i + del.size() - 1;
                answer.emplace_back(substring);
                substring = "";

                
            }
            else
                substring += target[i];
        }

    }
    answer.push_back(substring);
    return answer;
}

ostream & operator<< (ostream& out , vector<string> &ans) {
    for (auto & an : ans) {
        cout<<an<<" ";
    }
    return out;
}

int main() {
    vector<string> to_print = split("doabcmeabcmaabcfo","abc ");
    cout<<to_print;


    return 0;
}
