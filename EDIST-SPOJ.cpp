#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string a, b;
int dp[2005][2005];

int EDIST(int i, int j)
{
	if(i == a.length())
		return b.length()-j;
	if(j == b.length())
		return a.length()-i;
		
	int &ref = dp[i][j];
	if(ref != -1) 
		return ref;
		
	if(a[i] == b[j]) return ref = EDIST(i+1, j+1);
	
	return ref = 1 + min(EDIST(i, j+1), min(EDIST(i+1, j), EDIST(i+1, j+1)));
}

	
int main() {
	int T;
	cin>>T;
	
	while(T--)
	{
		memset(dp, -1, sizeof dp);
		cin>>a>>b;
		cout<<EDIST(0,0)<<endl;
	}
	
}
