//
//  Codeforces 20C Dijkstra ?.cpp
//  StudyFall16
//
//  Created by Farida Eid on 11/20/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;
#define mp(a,b) make_pair(a,b)

vector<vector<pair<int, long long>>>edges;
map<int,pair<int, int>> M;
vector<long long> dist;

void Dikjstra(int st, int end)
{
    priority_queue<pair<long long , int>>Q;
    Q.push(mp(0, st));
    dist[st] = 0;
    M[st] = mp(-1, 0);
    
    while(!Q.empty())
    {
        pair<long long, int> current = Q.top();
        int curr_city = current.second;
        long long curr_weight = -current.first;
        
        Q.pop();
        
        if(curr_city == end) return;
        
        if(curr_weight > dist[curr_city])
            continue;
        
        long long min_val = 1e9;
        int min_city = 0;
        
        for(int i=0; i<edges[curr_city].size(); i++)
        {
            if(dist[edges[curr_city][i].first] > edges[curr_city][i].second + dist[curr_city])
            {
                dist[edges[curr_city][i].first] = edges[curr_city][i].second + dist[curr_city];
                Q.push(mp(- dist[edges[curr_city][i].first], edges[curr_city][i].first));
                
                if(dist[edges[curr_city][i].first] < min_val)
                {
                    min_val = dist[edges[curr_city][i].first];
                    min_city = edges[curr_city][i].first;
                }
                
            }
        }
        
        if(M.find(min_city) == M.end())
            M[min_city] = mp(curr_city, dist[min_city]);
        else if(M[min_city].second > dist[min_city])
            M[min_city] = mp(curr_city, dist[min_city]);
        
    }
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    edges.resize(n);
    dist.resize(n, 1e9);
    for(int i=0; i<m; i++)
    {
        int x, y;
        long long w;
        
        cin>>x>>y>>w;
        x--; y--;
        
        edges[x].push_back(mp(y,w));
        edges[y].push_back(mp(x,w));
    }
    
    Dikjstra(0, n-1);
    
    if(dist[n-1] == 1e9) cout<<-1<<endl;
    
    else
    {
        
    vector<int>path;
    for(map<int, pair<int,int>>::iterator it = M.find(n-1);  it->second.first != -1;)
    {
        path.push_back(it->first);
        it = M.find(it->second.first);
    }
    
    path.push_back(0);
    
    reverse(path.begin(), path.end());
    for(int i=0; i<path.size();i++)
        cout<<path[i]+1<<" ";
    cout<<endl;
    }
}
