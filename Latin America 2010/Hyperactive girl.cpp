#include <bits/stdc++.h>

using namespace std;

#define MAXN 105
#define MOD 100000000

pair <int, int> tareas[MAXN];

int vis[MAXN][MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];
int cont;
int N, M;

int f(int pos, int ant, int ant2){
	if(vis[pos][ant][ant2] == cont)
		return dp[pos][ant][ant2];
	vis[pos][ant][ant2] = cont;
	if(tareas[ant].second == N + 1)
		return dp[pos][ant][ant2] = 1;
	if(tareas[ant].second < tareas[pos].first - 1 || pos > M + 1)
		return dp[pos][ant][ant2] = 0;
	dp[pos][ant][ant2] = f(pos + 1, ant, ant2);
	if(tareas[ant].second < tareas[pos].second && tareas[pos].first > tareas[ant2].second + 1)
		dp[pos][ant][ant2] += f(pos + 1, pos, ant);
	return dp[pos][ant][ant2];
}

int main() {
	while(true) {

		scanf("%d%d", &N, &M);
		if (N == 0) break;
		for (int i = 2; i <= M + 1; i++){
			scanf("%d%d", &tareas[i].first, &tareas[i].second);
			tareas[i].first++;
			tareas[i].second++;
		}

		sort(tareas + 2, tareas + M + 2);
		int ans = 0;
		cont++;
		if(M == 1 && tareas[2].first == 1 && tareas[2].second == N + 1)
			ans = 1;
		for(int i = 2; i <= M + 1; i++){
			for(int j = i + 1; j <= M + 1; j++){
				if(tareas[i].second < tareas[j].second && tareas[i].second < tareas[j].first - 1 && tareas[i].first == 1)
					ans += f(j + 1, j, i);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
