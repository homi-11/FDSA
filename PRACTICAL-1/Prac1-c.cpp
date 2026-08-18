#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;

    cout<<"enter a sentence: ";
    getline(cin,sentence);

    string word = "";
    string longestWord = "";

    sentence += ' ';

    for(int i=0;i<sentence.length();i++){
        if(sentence[i] != ' '){
            word += sentence[i];
        }
        else{
            if(word.length()>longestWord.length()){
                longestWord = word;
            }
            word = "";
        }
    }

    if(longestWord != ""){
        cout<<"\nlongest word : "<<longestWord<<endl;
        cout<<"length       : "<<longestWord.length()<<endl;
    }
    else{
        cout<<"no words found"<<endl;
    }
    return 0;
}