#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005
#define lld long long int

lld mapa[MAXN][MAXN];
int vis[MAXN][MAXN];
lld dp[MAXN][MAXN];
int cont;
int N;



void LOL(){
    puts("");
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++)
			printf("%d ", mapa[i][j]);
		puts("");
	}
}

lld area(int y, int x, int y2, int x2){
	return mapa[y2][x2] - mapa[y - 1][x2] - mapa[y2][x - 1] + mapa[y - 1][x - 1];
}

lld f(int x, int y){
	if(vis[x][y] == cont)
		return dp[x][y];
	vis[x][y] = cont;
	if(x == 0 || y == 0)
		return dp[x][y] = 0;
	lld now = f(x - 1, y);
	now = max(now, f(x , y - 1) + area(1, y, x, y));
	return dp[x][y] = now;
}

int main(){
	while(true){
		scanf("%d", &N);
		if(N == 0)
			break;
		for(int i = 0; i <= N; i++)
			for(int j = 0; j <= N; j++)
				mapa[i][j] = 0;
		for(int i = 1; i <= N; i++){
			for(int j = i; j > 0; j--){
				scanf("%lld", &mapa[j][N - i + j]);
			}
		}
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				mapa[i][j] += mapa[i][j - 1];
			}
		}
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				mapa[i][j] += mapa[i - 1][j];
		cont++;
		printf("%lld\n", f(N,N));
	}
	return 0;
}
