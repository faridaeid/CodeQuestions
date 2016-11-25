//
//  11463-Commandos-UVA.cpp
//  StudyFall16
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int adjMatrix[105][105];
vector<int> status;

int N;

void FloydWarshall()
{
    for(int k=0; k<N; k++)
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
            {
                if(adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j])
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
            }
}

int main()
{
    int T;
    cin>>T;
    int k=0;
    
    while(T--)
    {
        int R, x,y;
        cin>>N>>R;
        
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
            {
                if(i == j)
                    adjMatrix[i][j] = 0;
                else adjMatrix[i][j] = int(1e9);
            }
        
        while(R--)
        {
            cin>>x>>y;
            adjMatrix[x][y] = 1;
            adjMatrix[y][x] = 1;
        }
        
        cin>>x>>y;
        
        FloydWarshall();
        cout<<"Case "<<++k<<": ";
        
        int maxim = 0;
        for(int i=0; i<N; i++)
            maxim = max(maxim, adjMatrix[x][i] + adjMatrix[i][y]);
        
        cout<<maxim<<endl;
    }
    
}
