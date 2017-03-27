//
//  polynomial.cpp
//  CSC340HW4
//
//  Created by Abigail Chin on 3/24/17.
//  Copyright © 2017 Abigail Chin. All rights reserved.
//

#include <iostream>
#include "Polynomial.h"

Polynomial::Polynomial(){//default constructor
    coef.resize(200);
    exp.resize(200);
    coef[0] = 0.0;
    exp[0]= 0;
}
Polynomial::Polynomial(int deg){//indicates the highest degree allowed of a given polynomial
    int i = 0;
    while(exp.size()){
        if(exp[i]<=deg){
            i++;
        }else{
            break;
        }
    }
}

int Polynomial::getDeg() const{//gets highest exponent
    int deg = 0;
    int i = 0;
    while(exp.size()){ //loop through exp vector
        deg = exp[i];
        i++;
    }
    return (deg);
}

double Polynomial::getCoeff(int power) const{//returns coeff with specified exp
    double coeff = 0;
    int i = 0;
    
    while(exp.size()){
        if(exp[i] == power){
            coeff = coef[i];
            break;
        }else{
            i++;
        }
    }
    return coeff;
}

void Polynomial::setPoly(double c, int p){//set polynomial by user input
    int terms = 0;
    cout<<"How many terms are in your polynomial?"<<endl;
    cin>>terms;
    
    for(int i = 0; i < terms; i++){
        cout<<"Please type in the coefficient of the current term"<<endl;//first second third arr
        cin>>c;
        
        coef[i] = c;
    
        cout<<"Please type in the exponent of the current term"<<endl;
        cin>>p;
        
        exp[i] = p;
    }
}

void Polynomial::setCoeff(int power, double newCoefficient){//finds power and replaces the coefficient
    int i = 0;
    while(exp.size()){
        if(exp[i] == power){
            coef[i] = newCoefficient;
            break;
        }else{
            i++;
        }
    }
}

Polynomial Polynomial:: operator/(int &scal){
    Polynomial result = *this;
    int i = 0;
    
    while(coef.size()){
        coef[i] = coef[i]/scal;
        i++;
    }
    
    return result;
}

Polynomial Polynomial::operator-(){
    Polynomial result = *this;
    int i = 0;
    
    while (coef.size()) {
        coef[i] = coef[i]/-1;
        i++;
    }
    
    return result;
}

Polynomial Polynomial::operator+(const Polynomial &right){
    Polynomial result = *this;
    
    return result;
}

