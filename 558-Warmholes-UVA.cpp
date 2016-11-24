//
//  558-Warmholes-UVA.cpp
//  StudyFall16
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int n,m;

struct edge {
    int fr, end, c;
    edge(int x, int y, int z)
    {
        fr = x;
        end = y;
        c = z;
    }
};

vector<edge> edgeList;
vector<int> dist;

bool belmanFord(int s)
{
    dist[s] = 0;
    
    for(int i=1; i<=n; i++)
    {
        for(edge curr : edgeList)
        {
            if(dist[curr.fr] + curr.c < dist[curr.end])
            {
                if(i == n) return true;        // this is a negative cycle, relaxing all the iterations
                dist[curr.end] = dist[curr.fr] + curr.c;
            }
        }
    }
    
    return false;
    
}

int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        cin>>n>>m;
        dist.assign(n, 1e9);
        edgeList.clear();
        
        int x,y,z;
       
        while(m--)
        {
            cin>>x>>y>>z;
            edgeList.push_back(edge(x,y,z));
        }
        
        if(belmanFord(0)) cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;
        
    }
}
