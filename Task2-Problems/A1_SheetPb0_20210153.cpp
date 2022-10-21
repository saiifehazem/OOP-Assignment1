#include <iostream>
#include<string>
using namespace std;


int main() {
      string s,ns;
      cout<<"Enter Your Sentence:";
      getline(cin,s);
      for(int i=0;i<s.length();i++){
        if(isupper(s[i])){
            s[i] = tolower(s[i]);
            ns+=s[i];
        }
        else if(s[i] == ' ' && s[i+1] == ' '){
            continue;
        }
        else
            ns+=s[i];
      }
      ns[0] = toupper(ns[0]);
      cout<<ns;
}
