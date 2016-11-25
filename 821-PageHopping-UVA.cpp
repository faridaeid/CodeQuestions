//
//  821-PageHopping-UVA.cpp
//  ACM Training
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int matrix[105][105];
int Max;
double c;

double sumFloydWarshall()
{
    for(int k=0; k<=Max; k++)
        for(int i=0; i<=Max; i++)
            for(int j=0; j<=Max; j++)
                if(matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
    
    double sum = 0;
    for(int i=0; i<=Max; i++)
        for(int j=0; j<=Max; j++)
            if(matrix[i][j] != int(1e9))
            {
                sum += matrix[i][j];
                if(i != j)c++;
            }
    
    return sum;
}

int main()
{
    int x,y;
    cin>>x>>y;
    int k=1;
    
    
    while(x && y)
    {
        
        Max = max(x,y);
        c = 0;
        
        for(int i=0; i<=100; i++)
            for(int j=0; j<=100; j++)
            {
                if(i== j) matrix[i][j] = 0;
                else matrix[i][j] = int(1e9);
            }
        
        do
        {
            matrix[x][y] = 1;
            Max = max(max(x,y), Max);
            cin>>x>>y;
        }
        while(x && y);
        
        
        printf("Case %d: average length between pages = %.3f clicks\n", k++, sumFloydWarshall()/c);
        
        cin>>x>>y;
    };
}
