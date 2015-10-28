#include <bits/stdc++.h>

using namespace std;

#define MAXN 20

int X;
int vis[MAXN][MAXN][2];
long long int dp[MAXN][MAXN][2];
int cont;
int num[MAXN];
int N;
long long int ans[MAXN];


long long int f(int pos, long long int k, int flag){
	if(vis[pos][k][flag] == cont)
		return dp[pos][k][flag];
	vis[pos][k][flag] = cont;
	dp[pos][k][flag] = 0;
	if(pos == N)
		return dp[pos][k][flag] = k;
	if(flag){
		for(int i = 0; i < num[pos]; i++){
			dp[pos][k][flag] += f(pos + 1, k + ((i == X) ? 1 : 0), 0);
		}
		dp[pos][k][flag] += f(pos + 1, k + ((num[pos] == X) ? 1 : 0), 1);
	}else{
		for(int i = 0; i < 10; i++){
			dp[pos][k][flag] += f(pos + 1, k + ((i == X) ? 1 : 0), 0);
		}
	}
	return dp[pos][k][flag];
}

void reset(){
	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < MAXN; j++)
			dp[i][j][0] = dp[i][j][1] = 0;
	cont++;
}

long long int ceros(int x){
	int pot = 1;
	while(x >= pot)
		pot *= 10;
	pot /= 10;
	long long int sum = 0;
	while(pot > 0){
		sum += pot;
		pot /= 10;
	}
	
	return sum;
}

int main(){
	while(true){
		for(int i = 0; i < 10; i++)
			ans[i] = 0;
		int a, b;
		cin >> a >> b;
		if(a == 0 && b == 0)
			break;
		a--;
		ans[0] -= ceros(b) - ceros(a);
		N = 0;
		while(b){
			num[N++] = b % 10;
			b /= 10;
		}
		reverse(num, num + N);
		
		for(X = 0; X < 10; X++){
			reset();
			ans[X] += f(0, 0, 1);
		}
		N = 0;
		while(a){
			num[N++] = a % 10;
			a /= 10;
		}
		reverse(num, num + N);
		
		for(X = 0; X < 10; X++){
			reset();
			ans[X] -= f(0, 0, 1);
		}
		for(int i = 0; i < 10; i++){
			if(i != 0)
				cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}