//
//  TOPOSORT-DFS-SPOJ.cpp
//  ACM Training
//
//  Created by Farida Eid on 12/23/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Topological sort BFS -- DFS/ Recursive --*/

int n;

bool topologicalSort(const vector<vector<int>>& adjList, vector<int>& order,int st, vector<int>& visited)
{
    visited[st] = -2;   //grey area
    
    for(int node : adjList[st])
    {
        if(visited[node] == -2)
            return false;
        else if(visited[node] == -1)
            if(!topologicalSort(adjList, order, node, visited))
                return false;
    }
    
    order[st] = n;
    n--;
    visited[st] = 1;
    return true;
}

int main()
{
    int m,x,y;
    
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
    
    order.resize(n);
    vector<int> visiter;
    visiter.resize(n, -1);
    
    int ntemp = n;
    n--;
    bool stop= false;
    for(int i=0; i<ntemp; i++)
    {
        if(visiter[i] == -1)
            if(!topologicalSort(adjList, order, i, visiter))
               {
                  printf("Sandro fails.\n");
                   stop = true;
                   break;
               }

    }
        
    if(!stop)
        for(int i=0; i<order.size(); i++)
            printf("%d%c", order[i]+1, " \n"[i == order.size()-1]);
}
