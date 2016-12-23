//
//  11060-Beverages-UVA.cpp
//  ACM Training
//
//  Created by Farida Eid on 12/23/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map> 
#include <queue>

using namespace std;

void topologicalSort(const vector<vector<int>>& adjList, vector<int>& inDegree, vector<int>& order)
{
    
    priority_queue<int> Q;
    
    for(int i=0; i<inDegree.size(); i++)
        if(!inDegree[i])
            Q.push(-i);
    
    while(!Q.empty())
    {
        int curr = -Q.top();
        Q.pop();
        
        order.push_back(curr);
        
        for(int node: adjList[curr])
            if(--inDegree[node] == 0)
                Q.push(-node);
    }
    
}

int main()
{
    int N, M, x, y;
    string beverage, b1, b2;
    
    map<string, int> refernces;
    map<int, string> references2;
    
    int k = 1;
 
    while(scanf("%d", &N) == 1)
    {
        
        vector<int>inDegree;
        vector<vector<int>> adjList;
        vector<int> order;
        
        adjList.resize(N);
        inDegree.resize(N, 0);
        
        for(int i=0; i<N; i++)
        {
            cin>>beverage;
            refernces[beverage] = i;
            references2[i] = beverage;
        }
        
        scanf("%d", &M);
        
        for(int i=0; i<M; i++)
        {
            cin>>b1>>b2;
            
            x = refernces[b1];
            y = refernces[b2];
            
            adjList[x].push_back(y);
            inDegree[y]++;
        }
        
        topologicalSort(adjList, inDegree, order);
        
        printf("Case #%d: Dilbert should drink beverages in this order: ", k++);
        
        for(int i=0; i<order.size(); i++)
        {
            cout<<references2[order[i]];
            if(i == order.size()-1) cout<<".\n\n";
            else cout<<' ';
        }
        
    }
    
}
