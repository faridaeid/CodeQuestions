//
//  11503_Virtual_Friends_UVA.cpp
//  ACM Training
//
//  Created by Farida Eid on 11/21/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

map<string, int>names;
int grid[200000];
int names_cnt;
vector<int> clusters;
int cluster_ind;

int getIndex(string s)
{
    if(names.find(s) == names.end())
        names[s] = names_cnt++;

     return names[s];
}


int main()
{
    int T, F;
    string f1, f2;
    cin>>T;
    
    while(T--)
    {
        cin>>F;
        memset(grid, -1, sizeof grid);
        clusters.clear();
        clusters.resize(1, 7);
        names.clear();
        names_cnt = 0;
        cluster_ind = 0;
        while(F--)
        {
            cin>>f1>>f2;
            int ind1 = getIndex(f1);
            int ind2 = getIndex(f2);
            
            if(grid[ind1] == -1 && grid[ind2] == -1)    // fresh friendship, no frinds each;
            {
                grid[ind1] = grid[ind2] = ++cluster_ind;
                clusters.push_back(2);
            }
            else if(grid[ind1] == -1)
            {
                grid[ind1] = grid[ind2];
                clusters[grid[ind2]]++;
            }
            else if(grid[ind2] == -1)
            {
                grid[ind2] = grid[ind1];
                clusters[grid[ind1]]++;
            }
            else if(grid[ind1] != grid[ind2])
            {
                clusters[grid[ind1]] += clusters[grid[ind2]];
                int grid2_val = grid[ind2];
                
                for(int i=0; i<names_cnt; i++)
                {
                    if(grid[i] == grid2_val)
                        grid[i] = grid[ind1];
                }
            }
            
            cout<<clusters[grid[ind1]]<<endl;
            
        }
        
        
    }
}
