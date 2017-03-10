//
//  main.cpp
//  CSC340HW2
//
//  Created by Abigail Chin on 2/21/17.
//  Copyright © 2017 Abigail Chin. All rights reserved.
//  IDE: XCode
//  Section: 340.01
//  Professor: Hui Yang
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

struct TokenFreq{
    string value;
    int freq;
    
};

vector <TokenFreq> getTokenFreq(string file);
void selectionSort(vector<TokenFreq> & tokFreqVector);
void insertionSort(vector<TokenFreq> & tokFreqVector );
void writeToFile(vector<TokenFreq> &tokFreqV, string outFileName);


vector <TokenFreq> getTokenFreq(string file){
    vector<TokenFreq> token;
    
    /*change all characters to lower-case letters*/
    int i = 0;
    char c = ' ';
    while(file[i]){
        c = file[i];
        file[i] = (tolower(c));
        i++;
    }
    
    /*char array to tokens and push value to token vector*/
    int k = 0;
    i = 0;
    string temp;
    while(file[i]){
        if((isalpha(file[i])) || (file[i] == '\n')){
            temp += file[i];
            i++;
        }else{
            TokenFreq tempval;
            tempval.value = temp;
            token.push_back(tempval);
            cout<<token[k].value<<endl;
            temp = "";
            i++;
            k++;
        }
    }
    
    /*Account for frequency of tokens*/
    int j = 0;
    while(j <= token.size()){
        token[j].freq = 0;
        j++;
    }
    
    i = 0;
    k = 1;
    while(i < token.size()-1){
        if(token[i].value == token[k].value){
            token[i].freq++;
            token[k].freq++;
            k++;
        }else{
            k++;
            if(k >= token.size()){
                k = 1;
                i++;
            }
        }
    }
    
    
    return token;
}
void selectionSort(vector<TokenFreq> & tokFreqVector){
    int minIndex = 0;
    int tmp = 0;
    for (int i = 0; i < sizeof(tokFreqVector) - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < sizeof(tokFreqVector); j++){
            if (tokFreqVector[j].freq < tokFreqVector[minIndex].freq){
                minIndex = j;
            }
        }
        if (minIndex != i) {
            tmp = tokFreqVector[i].freq;
            tokFreqVector[i].freq = tokFreqVector[minIndex].freq;
            tokFreqVector[minIndex].freq = tmp;
        }
    }
}

void insertionSort(vector<TokenFreq> & tokFreqVector ){
    int j = 0;
    int tmp = 0;
    for (int i = sizeof(tokFreqVector); i > 1; i--) {
        j = i;
        while (j > 0 && (tokFreqVector[j + 1].freq > tokFreqVector[j].freq)) {
            tmp = tokFreqVector[j].freq;
            tokFreqVector[j].freq = tokFreqVector[j + 1].freq;
            tokFreqVector[j + 1].freq = tmp;
            j++;
        }
    }
}
void writeToFile(vector<TokenFreq> &tokFreqV, string outFileName){
    ofstream myFile;
    myFile.open(outFileName);
    
    int i = 0;
    while(i < tokFreqV.size()){
        myFile << tokFreqV[i].value << " : " << tokFreqV[i].freq << endl;
        i++;
    }
    myFile.close();
    
}
int main() {
    ifstream inFile;
    string linestr;
    string file;
    
    //    string textFile;
    //
    //    cout<<"What text file would you like to analyze?"<<endl;
    //    cin >> textFile;
    
    inFile.open("/Users/abigailchin/Documents/SFSU/CSC\ 340/CSC340HW2/CSC340HW2/speech.txt");
    
    if(inFile.fail()){
        cout<< "Failed to open the file. \n";
        exit(-1);
    }
    
    while(!inFile.eof() ){
        getline(inFile, linestr);
        file += linestr;
    }
    
    getTokenFreq(file);
    
    //    vector<TokenFreq> temp = getTokenFreq(file);
    vector <TokenFreq> sstemp = getTokenFreq(file);
    vector<TokenFreq> istemp = getTokenFreq(file);
    
    selectionSort(sstemp);
    
    insertionSort(istemp);
    
    //    writeToFile(temp, "/Users/abigailchin/Desktop/testing");
    
    writeToFile(sstemp, "/Users/abigailchin/Desktop/ascendingOrderTxtFile");
    
    writeToFile(istemp, "/Users/abigailchin/Desktop/descendingOrderTxtFile");
    
    inFile.close();
    
    return 0;
}
