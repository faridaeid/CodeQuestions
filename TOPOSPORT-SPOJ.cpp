//
//  TOPOSPORT-SPOJ.cpp
//  ACM Training
//
//  Created by Farida Eid on 12/22/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Topological sort BFS -- Iterative --*/

bool topologicalSort(const vector<vector<int>>& adjList, vector<int>& order, vector<int>& inDegree)
{
    
   // choses priority queue instead of queue because the answer prefers in order
    priority_queue<int> queue;
    
    for(int i=0; i<inDegree.size(); i++)
        if(!inDegree[i]) queue.push(-i);
    
    while(!queue.empty())
    {
        int current = -queue.top();
        queue.pop();
        
        order.push_back(current);
        
        for(int node : adjList[current])
        {
            if(--inDegree[node] == 0)
                queue.push(-node);
        }
    }
    
    for(int node : inDegree)
        if(node) return false;
    
    return true;
}

int main()
{
    int n,m,x,y;
    
    scanf("%d%d", &n, &m);
    
    vector<vector<int>> adjList;
    vector<int> inDegree;
    vector<int> order;
    
    adjList.resize(n);
    inDegree.resize(n, 0);
    
    for(int i=0; i<m; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        adjList[x].push_back(y);
        inDegree[y]++;
    }
    
    if(!topologicalSort(adjList, order, inDegree))
        printf("Sandro fails.\n");
    
    else
        for(int i=0; i<order.size(); i++)
            printf("%d%c", order[i]+1, " \n"[i == order.size()-1]);
}
