#include <bits/stdc++.h>

using namespace std;

#define MAXN 105
#define MOD 1000000007


long long int pascal[MAXN][MAXN];
long long int dp[21][MAXN][MAXN][22];
int vis[22][MAXN][MAXN][22];
int dig[MAXN];
int cont;

long long int f(int pos, int pares, int impares, int mod){

	if(vis[pos][pares][impares][mod] == cont)
		return dp[pos][pares][impares][mod];
	vis[pos][pares][impares][mod] = cont;
	if(pos == 10)
		return dp[pos][pares][impares][mod] = mod == 0 ? 1 : 0;
	long long int now = 0;
	for(int i = 0; i <= dig[pos]; i++){
		int j = dig[pos] - i;
		if(pares - i < 0 || impares - j < 0)
			continue;
		long long int combi = (pascal[pares][i] * pascal[impares][j]) % MOD;
		int modulo =  (mod + i * pos + j * (11 - pos)) % 11;
		now = (((f(pos + 1, pares - i, impares - j, modulo) * combi) % MOD) + now) % MOD;
	}
	return dp[pos][pares][impares][mod] = now;
}

int main(){
	pascal[0][0] = 1;
	for(int i = 1; i < MAXN; i++){
		pascal[i][0] = 1;
		for(int j = 1; j < MAXN; j++){
			pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % MOD;
		}
	}
	
	string a;
	while(cin >> a){
		for(int i = 0; i < 10; i++)
			dig[i] = 0;
		cont++;
		for(int i = 0; i < a.size(); i++)
			dig[a[i] - '0']++;
		long long int ans = 0;
		for(int i = 1; i < 10; i++){
			if(dig[i] == 0)
				continue;
			dig[i]--;
			cont++;
			ans = (ans + f(0, a.size()/ 2, (a.size() - 1) / 2, (a.size() & 1) ? i : (11 - i))) % MOD;
			dig[i]++;
		}
		cout << ans << endl;
	}
	return 0;
}