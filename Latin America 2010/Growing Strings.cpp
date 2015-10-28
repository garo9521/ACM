#include <bits/stdc++.h>

using namespace std;

#define MAXN 2000000

int SA[MAXN];
int rank[MAXN];
int tray[MAXN];
int tempSA[MAXN];
int tempRank[MAXN];
char cadena[MAXN];
int tam[MAXN];
int palabra[MAXN];
string entrada[20000];
vector < pair<int, int> > sorteo;

void CountingSort(int n, int k){ // O(n)
    int ranks = max(n, 256);
    fill(tray, tray + ranks, 0);

    for(int i = 0; i < n; i++)
        if(n <= i + k) tray[0]++;
        else tray[rank[i + k]]++;

    for(int i = 0, j = 0; i < ranks; i++)
        j += tray[i], tray[i] = j - tray[i];

    for(int i = 0; i < n; i++)
        if(n <= SA[i] + k) tempSA[tray[0]++] = SA[i];
        else tempSA[tray[rank[SA[i] + k]]++] = SA[i];
    copy(tempSA, tempSA + n, SA);
}

void SuffixArray(char* s, int n){ // O(n log n)
    copy(s, s + n, rank);
    for(int i = 0; i < n; i++) SA[i] = i;
    for(int i = 1; i < n; i <<= 1){
        CountingSort(n, i);
        CountingSort(n, 0);
        int ranks = 0;
        tempRank[SA[0]] = 0;
        for(int j = 1; j < n; j++){
            if(rank[SA[j]] != rank[SA[j - 1]] ||
            rank[SA[j]+i] != rank[SA[j-1] + i])ranks++;
            tempRank[SA[j]] = ranks;
        }
        copy(tempRank, tempRank + n, rank);
        if(rank[SA[n - 1]] == n - 1) break;
    }
}

// Starts code for Longest Common Prefix

int LCP[MAXN];
int prev[MAXN];
int plcp[MAXN];

void LongestCommonPrefix(char* s, int n){ // O(n)
    prev[SA[0]] = -1;
    for(int i = 1; i < n; i++)
        prev[SA[i]] = SA[i - 1];

    int L = 0;
    plcp[SA[0]] = 0;
    for(int i = 0; i < n; i++){
        if(prev[i] == -1) continue;
        while(prev[i] + L < n && i + L < n
        && s[i + L] == s[prev[i] + L]) L++;
        plcp[i] = L, L = max(L - 1, 0);
    }

    for(int i = 0; i < n; i++)
        LCP[i] = plcp[SA[i]];
}

vector <int> E[10005];
stack <pair <int, int> > pila;

int vis[MAXN];
int dp[MAXN];
int cont;
int f(int nodo){
	if(vis[nodo] == cont)
		return dp[nodo];
	vis[nodo] = cont;
	dp[nodo] = 0;
	for(int i = 0; i < E[nodo].size(); i++)
		dp[nodo] = max(dp[nodo], f(E[nodo][i]));
	dp[nodo]++;
	return dp[nodo];

}

struct trie{
	map <char, int> hijos;
	bool fin;
};

trie dic[MAXN];
int T;

int main(){
	while(true){
		int N, M = 0;
		cin >> N;
		if(N == 0)
			break;
		T = 1;
		sorteo.clear();
		for(int i = 1; i <= N; i++){
			cin >> entrada[i];
			int nodo = 1;
			for(int j = 0; j < entrada[i].size(); j++){
				if(dic[nodo].hijos.find(entrada[i][j]) == dic[nodo].hijos.end()){
					dic[nodo].hijos[entrada[i][j]] = ++T;
					nodo = T;
				}else{
					nodo = dic[nodo].hijos[entrada[i][j]];
				}
			}
			if(!dic[nodo].fin){
				sorteo.push_back(make_pair(entrada[i].size(), i));
				dic[nodo].fin = true;
			}

		}

		sort(sorteo.begin(), sorteo.end());

		reverse(sorteo.begin(), sorteo.end());

		for(int i = 0; i < sorteo.size(); i++){
			for(int j = 0; j < entrada[sorteo[i].second].size(); j++){
				palabra[M] = sorteo[i].second;
				cadena[M++] = entrada[sorteo[i].second][j];

			}
			tam[sorteo[i].second] = entrada[sorteo[i].second].size();
			cadena[M++] = '$';
		}
		SuffixArray(cadena, M);
		LongestCommonPrefix(cadena, M);
		for(int i = N; i < M; i++){
			while(!pila.empty() && LCP[i] < pila.top().first)
				pila.pop();

			if(!pila.empty()){
				E[pila.top().second].push_back(palabra[SA[i]]);
			}
			if(SA[i] == 0 || cadena[SA[i] - 1] == '$')
				pila.push(make_pair(tam[palabra[SA[i]]], palabra[SA[i]]));
		}
		while(!pila.empty())
			pila.pop();
		cont++;
		int ans = 0;
		for(int i = 1; i <= N; i++)
			ans = max(ans, f(i));
		cout << ans << endl;
		for(int i = 0; i <= N; i++){
			E[i].clear();
		}
		for(int i = 0; i <= M; i++){
			palabra[i] = 0;
			LCP[i] = 0;
			cadena[i] = 0;
			tam[i] = 0;
			prev[i] = 0;
			plcp[i] = 0;
			rank[i] = 0;
			tray[i] = 0;
			tempSA[i] = 0;
			tempRank[i] = 0;
			dic[i].fin = 0;
			dic[i].hijos.clear();
		}
		M = 0;

	}
	return 0;
}
