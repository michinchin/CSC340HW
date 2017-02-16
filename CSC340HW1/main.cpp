//
//  CSC340HW1.cpp
//
//
//  Name: Abigail Chin
//  ID: 916280162
//  Email: achin2@mail.sfsu.edu
//  IDE: XCode
//

#include <iostream>
#include <string>


using namespace std;

void getLetterFreq(string s);
void strToToken(string s);

int main(){
    
    string s;
    
    cout << "What string would you like us to evaluate?"<< endl;
    getline(cin, s);
    
    int i = 0;
    char c;
    
    while(s[i]){
        c = s[i];
        s[i] = (tolower(c));
        i++;
        
    }
    cout << "The frequency of each letter is described below: "<< endl;
    getLetterFreq(s);
    strToToken(s);
    
    return (0);
}

void getLetterFreq(string s){
    int freq[26] = {};//initialize array of 26 ints
    char letter[26] = {'a','b','c', 'd', 'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    for(int i = 0; i < s.size(); ){
        if(((s[i] >= 'a') || (s[i] <= 'z')) && s[i]!= ' '){
            for(int k = 0; k < 26;){
                if(s[i] == letter[k]){
                    freq[k]++;
                    i++;
                    break;
                }
                else if (s[i] != letter[k]){
                    k++;
                }
            }
            
        }else{//if s[i] is a space or not a letter
            i++;
        }
    }
    for(int j = 0; j< 26; j++){
        cout << "'"<<letter[j]<<"': "<<freq[j]<< ", ";
    }
}

void strToToken(string s){
    
    char token[] = {};
    int i = 0;
    if(s.size() == 0){
        cout << s << endl;
    }
    
    while(i < s.size()){
        if (s[i] != ' '){
            token[i] = s[i];
            i++;
        }else{
            token[i] = '\n';
            i++;
        }
    }
    cout << "\nThe tokens are (separated by a new line): \n"<< token << endl;
    
}

