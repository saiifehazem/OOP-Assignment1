#include <bits/stdc++.h>
using namespace std;
map<string , pair<int,int>> File_content;
vector<string > email_words ;
int total_points = 0;
map<string , pair<int,int>> Handle_file() {
    fstream words;
    words.open("Phishing",ios::in);
    string s ;
    while (getline(words,s)) {
        string substr;
        int point;
        for (auto &character: s) {
            if (character == '-')
                continue;
            else if (character == '1' || character == '2' || character == '3')
                point = character - '0';
            else
                substr += character;
        }
        File_content.insert({substr,{0,point}});
    }
    words.close();
    return File_content;
}

ostream  & operator << (ostream& out , vector<string>& v ) {
    for(auto &i : v)
        cout<<i<<" ";
    return out;
}

void Phishing (vector<string> & v) {
    vector<string> occurrence;
    for(auto &word : v){
        if (File_content[word].second>0 && File_content[word].second<4){
            occurrence.emplace_back(word);
            File_content[word].first++;
            total_points += File_content[word].second;
        }
    }
}


int main(){
    File_content = Handle_file();

    string email;
    cout<<"enter your email:";

    getline(cin,email,'\n');
    string sub;
    for(auto &i : email){
        if (i==' '){
            email_words.emplace_back(sub);
            sub = "";
        }
        else
            sub += i;
    }
    email_words.emplace_back(sub);

    Phishing(email_words);
    for(auto &element : File_content){
        if (element.second.first>0)
            cout<<element.first<<" "<<element.second.first<<" "<<element.second.second*element.second.first<<"\n";
    }

    cout<<"the total points is :"<<total_points;

    return 0;
}