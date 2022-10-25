#include <bits/stdc++.h>
#include <fstream>

using namespace std;

vector <string> f1, f2;

void loadf1(vector<string>&txt,ifstream &file)
{
    char line[100];
    string fName;
    cout<<"Please enter text file name without extension: ";
    cin>>fName;
    fName+=".txt";
    file.open(fName);

    if(file)
    {
        cout << "File was opened successfully !!"<<endl;
        while(!file.eof())
        {
            file.getline(line, 100, '\n');
            txt.push_back(string(line));
        }
    }

    else
    {
        cout << "This file does not exist!"<<endl;
    }
}

void loadf2(vector<string>&txt, ifstream &file)
{
    char line[100];
    string fName;
    cout<<"Please enter text file name without extension: ";
    cin>>fName;
    fName+=".txt";
    file.open(fName);

    if(file)
    {
        cout << "File was opened successfully !!"<<endl;
        cout<<endl;
        while(!file.eof())
        {
            file.getline(line, 100, '\n');
            txt.push_back(string(line));
        }
    }
    else
    {
        cout << "This file does not exist!"<<endl;
    }
}

void compare()
{
    string choice;
    while(true)
    {
        cout<<"Choose:"<<endl<<"1- Char by Char"<<endl<<"2- Word by Word"<<endl;
        cout<<"Your choice: ";
        cin>>choice;
        cout<<endl;
        if(choice=="1")
        {
            bool check=true;
            int index;

            for(int i=0; i<max(f1.size(),f2.size()); i++)
            {
                for(int k=0; k<max(f1[i].size(),f2[i].size()); k++)
                {
                    if(f1[i][k]!=f2[i][k])
                    {
                        index=i;
                        check=false;
                        break;
                    }
                }
                if(!check)
                {
                    break;
                }
            }
            if(check && f1!=f2)
            {
                cout<<"They are not identical as the other file has more characters!"<<endl;
            }
            else if(check)
            {
                cout<<"They are identical"<<endl;
            }
            else
            {
                cout<<"They are not identical."<<endl;
                cout<<"Line number is: "<<index+1<<endl;
                cout<<"The different lines are: "<<endl;
                cout<<"1- "<<f1[index]<<endl;
                cout<<"2- "<<f2[index]<<endl;
            }
            break;
        }
        else if(choice=="2")
        {
            string word1,word2;
            bool check=true;
            vector <string> words1;
            vector <string> words2;
            map <string,int> mp1;
            map <string,int> mp2;
            for(int i=0; i<f1.size(); i++)
            {
                word1="";
                for(int k=0; k<f1[i].size(); k++)
                {
                    if(f1[i][k]!=' ')
                    {
                        word1+=f1[i][k];
                    }
                    else if(word1!="")
                    {
                        words1.push_back(word1);
                        mp1[word1]=i;
                        word1="";
                    }
                }
                mp1[word1]=i;
                words1.push_back(word1);
            }
            for(int i=0; i<f2.size(); i++)
            {
                word2="";
                for(int k=0; k<f2[i].size(); k++)
                {
                    if(f2[i][k]!=' ')
                    {
                        word2+=f2[i][k];
                    }
                    else if(word2!="")
                    {
                        words2.push_back(word2);
                        mp2[word2]=i;
                        word2="";
                    }
                }
                mp2[word2]=i;
                words2.push_back(word2);
            }
            for(int i=0; i<min(words1.size(),words2.size()); i++)
            {
                if(words1[i]!=words2[i])
                {
                    word1=words1[i];
                    word2=words2[i];
                    check=false;
                    break;
                }
            }

            if(words1!=words2 && check)
            {
                cout<<"They are not identical because there is more words in the other file!"<<endl;
                cout<<"The different lines are: "<<endl;
                cout<<"1- "<<f1[mp1[word1]]<<endl;
                cout<<"2- "<<f2[mp2[word2]]<<endl;
            }
            else if(!check)
            {
                cout<<"They are not identical."<<endl;
                cout<<"They are different in words: "<<endl;
                cout<<word1<<" "<<word2<<endl;
                cout<<"The different lines are: "<<endl;
                cout<<"1- "<<f1[mp1[word1]]<<endl;
                cout<<"2- "<<f2[mp2[word2]]<<endl;
            }
            else
            {
                cout<<"They are identical"<<endl;
            }
            break;
        }
        else
        {
            cout<<"Invalid input."<<endl;
        }
    }
}

int main()
{
    ifstream first;
    ifstream second;
    loadf1(f1, first);
    loadf2(f2, second);
    compare();
    return 0;
}
