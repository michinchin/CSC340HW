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
    coef[0] = 0.0;
}
Polynomial::Polynomial(int deg){//indicates the highest degree allowed of a given polynomial
    //    while(i < coef.size()){
    //        if(i <=deg){
    //            i++;
    //        }else{
    //            break;
    //        }
    //    }
    coef.resize(deg);
}

int Polynomial::getDeg() const{//gets highest exponent
    int deg = 0;
    int i = 0;
    
    while(i < coef.size()){ //loop through exp vector
        if(i >= deg && coef[i]!= 0){
            deg = i;
            i++;
        }else{
            i++;
        }
    }
    
    return deg;
}

double Polynomial::getCoeff(int power) const{//returns coeff with specified exp
    double coeff = 0;
    int i = 0;
    
    while(i < coef.size()){
        if(i == power){
            coeff = coef[i];
            break;
        }else{
            i++;
        }
    }
    return coeff;
}

void Polynomial::setPoly(int terms){//set polynomial by user input
    double c = 0;
    int p = 0;
    int i = 0;
    
    while(i<terms){
        
        cout<<"Please type in the exponent of the current term"<<endl;
        cin>>p;
        
        cout<<"Please type in the coefficient of the current term"<<endl;//first second third arr
        cin>>c;
        
        coef[p] = c;
        
        i++;
        
    }
}

void Polynomial::setCoeff(int power, double newCoefficient){//finds power and replaces the coefficient
    int i = 0;
    while(i < coef.size()){
        if(i == power){
            coef[i] = newCoefficient;
            break;
        }else{
            i++;
        }
    }
}

Polynomial Polynomial:: operator/(const int &scal){
    Polynomial result = *this;
    
    int i = 0;
    
    while(i<result.coef.size()){
        result.coef[i] = result.coef[i]/scal;
        i++;
    }
    
    return result;
}

Polynomial Polynomial::operator-(){
    Polynomial result = *this;
    int i = 0;
    
    while (i<result.coef.size()) {
        result.coef[i] = result.coef[i]/-1;
        i++;
    }
    
    return result;
}

Polynomial Polynomial::operator+(const Polynomial &right){
    Polynomial result = *this;
    int i = 0;
    
    while(i<result.coef.size()){
        result.coef[i] = right.coef[i] + coef[i];
        i++;
    }
    
    return result;
}

ostream& operator<<(ostream& put, const Polynomial& right){
    int i = 0;
    put<< "p1 = ";
    while(i < right.coef.size()){
        if(right.coef[i] != 0){
            put<<right.coef[i]<<"*x^"<<i;
            
        }
        i++;
        if(right.coef[i] != 0){
            put<<" + ";
        }
    }
    return put;
}



