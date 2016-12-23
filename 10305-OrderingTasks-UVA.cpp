//
//  10305-OrderingTasks-UVA.cpp
//  ACM Training
//
//  Created by Farida Eid on 12/23/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

void topologicalSort(const vector<vector<int>>adjList, vector<int>& order, vector<int>& inDegree)
{
    queue<int> Q;
    
    for(int i=0; i<inDegree.size(); i++)
        if(inDegree[i] == 0) Q.push(i);
    
    while(!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        
        order.push_back(curr);
        
        for(int node: adjList[curr])
        {
            if(--inDegree[node] == 0)
                Q.push(node);
        }
    }
}

int main()
{
    int n, m, x, y;
    cin>>n>>m;
    
   do
   {
       
    vector<vector<int>>adjList;
    adjList.resize(n);
    
    vector<int>inDegree;
    inDegree.resize(n, 0);
    
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        x--;
        y--;
        
        adjList[x].push_back(y);
        inDegree[y]++;
    }
    
    vector<int>order;
    topologicalSort(adjList, order, inDegree);
    
    for(int value : order)
        printf("%d%c", value+1, ' ');
       
       cout<<endl;
     
    cin>>n>>m;
       
       
   }while(n || m);
    
}
