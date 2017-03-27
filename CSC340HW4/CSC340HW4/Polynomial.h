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
    vector<double> coef;//coefficient
    vector<int> exp;//exponent
public:
    
    //constructors
    Polynomial();//default constructor
    Polynomial(int deg); //indicates highest degree allowed of a given polynomial
    
    //getters (read only)
    int getDeg() const; //returns highest degree of expression
    double getCoeff(int power) const; //returns coefficient of term x^(power)
    
    //setters
    void setPoly(double c, int p); //obtain polynomial from keyboard
    void setCoeff(int power, double newCoefficient); //sets coefficient of the term x^(pow) to newCoefficient
    
    //overloaded operators
    Polynomial operator/ (int& scal);
    Polynomial operator- ();
    Polynomial operator+(const Polynomial& right);

    friend Polynomial operator<<(ostream& left, const Polynomial& right);
    
};

#endif /* Polynomial_h */
