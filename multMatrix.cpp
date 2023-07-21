//
//  multMatrix.cpp
//  Homework13
//
//  Created by Sean Belingheri on 12/1/22.
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
    int**matrix1=NULL;
    int**matrix2=NULL;
    int**product=NULL;
    int matrix1_row, matrix1_column, matrix2_row, matrix2_column, i = 0, g = 0, test;
    char ch;
    string temp;
    
    
    do{ // this do while loop checks to see if the matrix dimensions are compatible. the program will not proceed until they are.
        cout<<"Enter dimensions for first matrix: ";
        cin>>matrix1_row>>matrix1_column;
        cout<<"Enter dimensions for the second matrix: ";
        cin>>matrix2_row>>matrix2_column;
        if(matrix1_column != matrix2_row)
            cout<<"Incompatible matrices, use different dimensions."<<endl;
        
        }while(matrix1_column != matrix2_row);
    
    matrix1=new int*[matrix1_row];
    for(int k = 0; k < matrix1_row; k++)
        matrix1[k] = new int[matrix1_column];
    
    cout<<"Enter Matrix 1 elements:"<<endl;
    for(g; g < matrix1_row; g++)
    {
        i = 0;
        do
        {
            cin>>matrix1[g][i];
            i++;
            ch = cin.get();
        } while(ch != '\n' && i < matrix1_column);

        if(i == matrix1_column && ch != '\n')
            getline(cin, temp);
        else if(i < matrix1_column && ch == '\n')
        {
            for(i; i < matrix1_column; i++)
                matrix1[g][i]=0;
        }
    }
 
    matrix2=new int*[matrix2_row];
    for(int k = 0; k < matrix2_row; k++)
        matrix2[k] = new int[matrix2_column];
    g = 0; //always remember to reset the top level for loop variable to 0 when entering values for multiple matricies/arrays
    
    cout<<"Enter Matrix 2 elements:"<<endl;
    for(g; g < matrix2_row; g++)
    {
        i = 0;
        do
        {
            cin>>matrix2[g][i];
            i++;
            ch = cin.get();
        } while(ch != '\n' && i < matrix2_column);

        if(i == matrix2_column && ch != '\n')
            getline(cin, temp);
        else if(i < matrix2_column && ch == '\n')
        {
            for(i; i < matrix2_column; i++)
                matrix2[g][i]=0;
        }
    }
    
    product=new int*[matrix1_row];
    for(int k = 0; k < matrix1_row; k++)
        product[k] = new int[matrix2_column];
   
    for(int row = 0; row < matrix1_row; ++row)
    {
        for(int column = 0; column < matrix2_column; ++column)
        {
            for(int f = 0; f < matrix2_row; ++f)//this 3rd for loop allows me to cycle through numbers while keeping the variables from the above 2 for loops consistent.
                product[row][column] += matrix1[row][f] * matrix2[f][column];
            /*
             eg: first round is (0,0) += (0,0) * (0,0)
             then               (0,0) += (0,1) * (1,0)
             then               (0,0) += (0,2) * (2,0)
             
             next round is (0,1) += (0,0) * (0,1)
             then          (0,1) += (0,1) * (1,1)
             then          (0,1) += (0,2) * (2,1)
             
             theres really 3 variables: rows, columns, and a variable the is both matrix1 columns and matrix2 rows simultaneously
             */
        }
    }
    
    cout<<"Multiplication Output: "<<endl;
    for(int r = 0; r < matrix1_row; r++)
        for(int j = 0; j<matrix2_column; j++)
        {
            cout<<product[r][j]<<" ";
            if(j == matrix2_column-1)
                cout<<endl;
        }
    
    return 0;
}
