#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define MAXV 1000000
#define LOGV 20
#define lli long long int

vector <int> hola;
hola.begin();

int level[MAXV]; 
int parent[MAXV];
int P[MAXV][LOGV];
long long int dist[MAXV];
vector< pair <int, lli> > E[MAXV];

int logarithm(int v){ // O(log v)
    for(int i = 0; true; i++)
        if(v <= 1 << i) return i;
}

void PreprocessDP(int v){ // O(v log v)
    int log = logarithm(v);
    for(int i = 0; i < v; i++)
        P[i][0] = parent[i];
    for(int j = 1; j <= log; j++)
        for(int i = 0; i < v; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];
}

int LCA(int v, int a, int b){ // O(log v)
    int log = logarithm(v);
    if(level[a] < level[b]) swap(a, b);
    for(int i = log; i >= 0; i--)
        if(level[a] - (1 << i) >= level[b])
            a = P[a][i];
    if(a == b) return a;
    for(int i = log; i >= 0; i--)
        if(P[a][i] != P[b][i])
            a = P[a][i], b = P[b][i];
    return P[a][0];
}

void busca(int nodo, int padre, lli d, int nivel){
	dist[nodo] = d;
	level[nodo] = nivel;
	for(int i = 0; i < E[nodo].size(); i++){
		if(E[nodo][i].first == padre)
			continue;
		busca(E[nodo][i].first, nodo, d + E[nodo][i].second, nivel + 1);
	}
}


int main(){

	while(true){
		int N;
		cin >> N;
		if(N == 0)
			break;
		for(int i = 1; i < N; i++){
			int a;
			lli b;
			cin >> a >> b;
			parent[i] = a;
			E[i].push_back(make_pair(a, b));
			E[a].push_back(make_pair(i, b));
		}
		busca(0, -1, 0, 0);
		PreprocessDP(N);
		int M;
		cin >> M;
		for(int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;
			int c = LCA(N, a, b);
			if(i != 0)
				cout << " "; 
			cout << dist[a] + dist[b] - 2 * dist[c];
		}
		cout << endl;
		for(int i = 0; i < N; i++)
			E[i].clear();
	}
	return 0;
}