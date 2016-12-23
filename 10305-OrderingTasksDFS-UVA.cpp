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

vector<vector<int>> adjList;
vector<int> order;
vector<bool> visisted;

int n;


void topologicalSort(int s)
{
    visisted[s] = true;
    
    for(int node: adjList[s])
    {
        if(!visisted[node])
            topologicalSort(node);
    }
    
    order[s] = n;
    n--;
    
}

int main()
{
    int m, x, y;
    cin>>n>>m;
    
    do
    {
        
        adjList.clear();
        visisted.clear();
        order.clear();
        
        adjList.resize(n);
        visisted.resize(n, false);
        order.resize(n);
        
        vector<int> answer;
        answer.resize(n);
        
        
        
        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            x--;
            y--;
            
            adjList[x].push_back(y);
        }
        
        int ntemp = n;
        n--;
        
        for(int i=0; i<ntemp; i++)
        {
            if(!visisted[i])
                topologicalSort(i);
        }
        
        for(int i=0; i<order.size(); i++)
            answer[order[i]] = i;
        
        
        for(int value : answer)
            printf("%d%c", value+1, ' ');
        
        cout<<endl;
        
        cin>>n>>m;
        
        
    }while(n || m);
    
}
