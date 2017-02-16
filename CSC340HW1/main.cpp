//
//  CSC340HW1.cpp
//
//
//  Name: Abigail Chin
//  ID: 916280162
//  Email: achin2@mail.sfsu.edu
//

#include <iostream>
#include <string>
#include <vector>


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
    
    getLetterFreq(s);
    strToToken(s);
    
    return (0);
}

void getLetterFreq(string s){
    //lower case letters a-z are in ascii code 97-122
    int freq[26] = {};//initialize array of 26 ints
    char letter[26] = {'a','b','c', 'd', 'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    for(int i = 0; i < s.size(); ){
        if((s[i] >= 'a') || (s[i] <= 'z')){
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

        }
    }
    for(int j = 0; j< 26; j++){
        cout << "'"<<letter[j]<<"': "<<freq[j]<< ", ";
    }
//    while(cnt <= 0){
//        if(s[i] != letter[k]){
//            k++;
//            getLetterFreq(s);
//        }else if(s[i] == letter[k]){
//            freq[i]++;
//            cout << "'"<<letter[i]<<"': "<<freq[i]<< ", ";
//            cnt++;
//        }
//    }
//    for(int i = 0; i < s.size(); i++){
//            while(s[i] != letter[k]){
//                k++;
//            }
//            if(s[i] == letter[k]){
//                cnt++;
//                freq[i] =cnt;
//                cout << "'"<<letter[i]<<"': "<<freq[i]<< ", ";
//            }
//        }
    }

void strToToken(string s){
    
    //    if(s.length == 0){
    //        return list;
    //    }
}

