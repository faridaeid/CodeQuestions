#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int S, N;
int dp [2005][2005];
vector<pair<int, int>> items;

int Knapsack(int c, int i)
{
	if(c < 0) return -1e9;
	if(c == 0 || i== N) return 0;
	
	
	int & ref = dp[c][i];
	if(ref != -1)
		return ref;
		
	return ref = max(Knapsack(c- items[i].first, i+1) + items[i].second, 
			Knapsack(c, i+1));
		
}

int main() {
	cin>>S>>N;
	int x,y;
	
	memset (dp, -1, sizeof dp);
	for(int i=0; i<N; i++)
	{
		cin>>x>>y;
		items.push_back(make_pair(x,y));
	}
	
	cout<<Knapsack(S, 0)<<endl;

	return 0;
}
