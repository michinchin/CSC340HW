//
//  main.cpp
//  CSC340HW4
//
//  Created by Abigail Chin on 3/24/17.
//  Copyright © 2017 Abigail Chin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Polynomial.h"

int main(int argc, const char * argv[]) {
    Polynomial p1;
    Polynomial p2 (2);
    Polynomial p3;
    Polynomial p4;
    
    /*mutators*/
    p1.setPoly(2);
    p1.setCoeff(3, 1.5);
    
    /*accessors*/
    cout<<"Degree of p1: "<<p1.getDeg()<<endl;
    cout<<"Coefficient of p1 with degree 3: "<<p1.getCoeff(3)<<endl;
    
    
    /*test operator div*/
    int a = 3;
    p2 = p1 / a;
    
    /*test negating operator*/
    p3 = -p2;
    
    /*test addition operator*/
    p4 = p3 + p2;
    
    /*test friend ostream*/
    cout<<p1<<endl;
    
    return(0);
}