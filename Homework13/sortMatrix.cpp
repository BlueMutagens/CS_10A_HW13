//
//  main.cpp
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
    int**arr=NULL;
    int size_row, size_column, i = 0, g = 0;
    char ch;
    string temp;
    
    
    
    cout<<"Enter Matrix dimensions: ";
    cin>>size_row>>size_column;
    
    arr=new int*[size_row];
    for(int k = 0; k < size_row; k++)
        arr[k] = new int[size_column];
    
    cout<<"Enter Matrix elements:"<<endl;
    for(g; g < size_row; g++)
    {
        i = 0;
        do
        {
            cin>>arr[g][i];
            i++;
            ch = cin.get();
        } while(ch != '\n' && i < size_column);

        if(i == size_column && ch != '\n')
            getline(cin, temp);
        else if(i < size_column && ch == '\n')
        {
            for(i; i < size_column; i++)
                arr[g][i]=0;
        }
    }
   
    
    for(int s = 0; s<size_row; s++)
        for(int d = 0; d<size_column-1; d++)
        {
            if(arr[s][d] < arr[s][d+1])
            {
                arr[s][d+1] += arr[s][d];
                arr[s][d] = arr[s][d+1] - arr[s][d];
                arr[s][d+1] -= arr[s][d];
                d = -1;
            }
        }

    
    for(int s = 0; s<size_column; s++)
        for(int d = 0; d<size_row-1; d++)
        {
            if(arr[d][s] < arr[d+1][s])
            {
                arr[d+1][s] += arr[d][s];
                arr[d][s] = arr[d+1][s] - arr[d][s];
                arr[d+1][s] -= arr[d][s];
                d = -1;
            }
        }
    cout<<"Sorted Matrix:"<<endl;
    for(int s = 0; s<size_row; s++)
        for(int d = 0; d<size_column; d++)
        {
            cout<<arr[s][d]<<" ";
            if(d==size_column-1)
                cout<<endl;
        }
    
    return 0;
}
