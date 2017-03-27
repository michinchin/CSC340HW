//
//  Polynomial.h
//  CSC340HW4
//
//  Created by Abigail Chin on 3/24/17.
//  Copyright © 2017 Abigail Chin. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h
#include <iostream>
#include <vector>

using namespace std;

class Polynomial{
private:
    vector<double> coef;//coefficient vector with indexes exponents
public:
    
    //constructors
    Polynomial();//default constructor
    Polynomial(int deg); //indicates highest degree allowed of a given polynomial
    
    //getters (read only)
    int getDeg() const; //returns highest degree of expression
    double getCoeff(int power) const; //returns coefficient of term x^(power)
    
    //setters
    void setPoly(int terms); //obtain polynomial from keyboard
    void setCoeff(int power, double newCoefficient); //sets coefficient of the term x^(pow) to newCoefficient
    
    //overloaded operators
    Polynomial operator/ (const int& scal);
    Polynomial operator- ();
    Polynomial operator+(const Polynomial& right);

    friend ostream& operator<<(ostream& put, const Polynomial& right);
    
};

#endif /* Polynomial_h */
