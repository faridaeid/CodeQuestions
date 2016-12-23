//
//  10557-XYZZY-UVA.cpp
//  ACM Training
//
//  Created by Farida Eid on 12/21/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include "queue"

using namespace std;

struct edge
{
    int front, end, cost;
};

vector<edge> edgeList;
vector<int> dist;
vector<vector<int>> rooms;

int n;

bool bfs(int s, int e)
{
    vector<bool>visited;
    visited.resize(n+1, false);
    
    visited[s] = true;
    
    queue<int> q;
    q.push(s);
    
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        
        if(current == e) return true;
        
        for(int end: rooms[current])
        {
            if(!visited[end])
            {
                visited[end] = true;
                q.push(end);
            }
        }
    }

    return false;
}

bool xyzzy(int s)
{
    dist.assign(n+1, 1e9);
    dist[s] = -100;
    
    for(int i=1; i<n; i++)
    {
        for(edge e:  edgeList)
        {
            if(dist[e.front] + e.cost < min(0,dist[e.end]))
                dist[e.end] = dist[e.front] + e.cost;
            
        }
    }
    
    if(dist[n] < 0) return true;        // didn't exceed the energy limit
    
    // if you reached here then this is a negative cycle
    for(edge e:  edgeList)
    {
        if(dist[e.front] + e.cost < min(0,dist[e.end]))
            if(bfs(s, e.front) && bfs(e.end, n)) return true;
        
    }
    return false;
}


int main()
{
    
    while(cin>>n, n != -1)
    {
        edgeList.clear();
        edgeList.resize(0);
        int weight, v, edgesNumber;
        
        
        vector<int>values;
        values.resize(n+1);
        
        rooms.clear();
        rooms.resize(n+1);
        
        for(int i=1; i<=n; i++)
        {
            cin>>weight;
            values[i] = -weight;
            
            cin>>edgesNumber;
           
            for(int j=0; j<edgesNumber; j++)
            {
                cin>>v;
                
                edge e;
                e.front = i;
                e.end = v;
                edgeList.push_back(e);
                rooms[i].push_back(v);
            }
        
        }
        
        for(int i=0; i<edgeList.size(); i++)
            edgeList[i].cost = values[edgeList[i].end];
    
        if(xyzzy(1))
            cout<<"winnable"<<endl;
        else cout<<"hopeless"<<endl;
        
    }
    
}



