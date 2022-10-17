#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Players{
    string name;
    int score;
};
vector<Players> p(10);
void fillPlayers(){
    vector<string> arrn = {"Bill","Bill","Tony","Jessy","Alex","Alex","Zizo","Zizo","Zoz","Billa"};
    vector<int>arrs = {45,55,70,69,79,82,81,99,100,100};
    for(int i=0;i<10;i++){
        p[i].name = arrn[i];
        p[i].score = arrs[i];
    }
     sort(p.begin(),p.end(),[](Players a,Players b){
       return a.score < b.score;
       });
}
void addPlayer(){
    string n;
    int s;
    cin>>n>>s;
    for(int i=0;i<10;i++){
        if(s > p[i].score){
            p[0].name = n;
            p[0].score = s;
        }
    }
    sort(p.begin(),p.end(),[](Players a,Players b){
       return a.score < b.score;
       });
};
void displayPlayers(){
    for(int i=0;i<10;i++){
        cout<<p[i].name<<" "<<p[i].score<<endl;
    }
};
void searchUser(){
    string pn;
    int mx = 0;
    cin>>pn;
    for(int i=0;i<10;i++){
        if(pn == p[i].name && p[i].score > mx){
            mx = p[i].score;
        }
    }
    if(mx==0)
        cout<<"Player not in the top 10!"<<endl;
    else{
        cout<<mx<<endl;
    }
};
void menu(){
    cout<<"Choose one of the following numbers"<<endl;
    cout<<"1- Add a new player and it's score"<<endl;
    cout<<"2- Display the top 10 names and scores"<<endl;
    cout<<"3- Search for player"<<endl;
    cout<<"4- Exit"<<endl;
    cout<<">>";

}

int main()
{
  fillPlayers();
  while(true){
   menu();
   int num;
   cin>>num;
    if(num == 1){
        addPlayer();
    }
    else if(num == 2){
        displayPlayers();
    }
    else if(num == 3){
        searchUser();
    }
    else{
        return -1;
    }
  }
}
