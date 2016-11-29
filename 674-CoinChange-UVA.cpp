//
//  674-CoinChange-UVA.cpp
//  ACM Training
//
//  Created by Farida Eid on 11/29/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

long long dp[9000][6];
int coin[5] = {50,25,10,5,1};

long long CoinChange(int c, int i)
{
    if( c == 0) return 1;
    
    long long & ref = dp[c][i];
    
    if(ref != -1)
        return ref;
    
    int ways = 0;
    for(int j=i; j<5; j++)
        if(c >= coin[j])
            ways += CoinChange(c - coin[j], j);

    return ref = ways;
}

int main()
{
    int x;
    memset(dp, -1, sizeof dp);
    while(cin>>x)
    {
        cout<<CoinChange(x,0)<<endl;
    }
    
}
