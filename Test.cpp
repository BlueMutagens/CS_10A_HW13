//
//  Test.cpp
//  Homework13
//
//  Created by Sean Belingheri on 12/5/22.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    string str0 = "Megalovania";
    cout<<str0.length()<<endl;
    
    for(int i = 0; i < str0.length(); i++)
     if(str0[i] == 'e' || str0[i] == 'a')
         str0[i] = 'o';
    
    cout<<str0<<endl;
    
    cout<<(~112)<<endl;
    return 0;
}
