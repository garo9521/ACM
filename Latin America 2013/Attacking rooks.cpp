#include <bits/stdc++.h>

using namespace std;

#define MAXN 205

char mapa[MAXN][MAXN];
int hor[MAXN][MAXN];
int ver[MAXN][MAXN];
int N;
vector <int> E[MAXN * MAXN];

#define MAXV MAXN * MAXN
 
int match[MAXV];
bool visited[MAXV];
 
int AlternatingPath(int u){ // O(v + e)
    if(u == -1) return 1;
    if(visited[u]) return 0;
    
    visited[u] = true;
    vector<int>::iterator v;
    for(v = E[u].begin(); v != E[u].end(); v++){
        if(AlternatingPath(match[*v])){
            match[*v] = u;
            return 1;
        }
    }
    return 0;
}
 
int MaximumBipartiteMatching(int L, int R){
    int matching = 0;
    fill(match, match + L + R, -1);
    for(int u = 0; u < L; u++){
        fill(visited, visited + L, false);
        matching += AlternatingPath(u);
    }
    return matching;
} // O(v^2 + ve)

int main(){
	while(cin >> N){
		int A, B;
		for(int i = 0; i < N; i++)
			cin >> mapa[i];
		int cont = 0;
		for(int i = 0; i < N; i++){
			int pos = 0;
			
			while(mapa[i][pos] == 'X'){
				hor[i][pos] = -1;
				pos++;
			}
			while(pos < N){
				while(mapa[i][pos] == '.'){
					hor[i][pos] = cont;
					pos++;
				}
				cont++;
				while(mapa[i][pos] == 'X'){
					hor[i][pos] = -1;
					pos++;
				}
			}
		}
		A = cont;
		for(int i = 0; i < N; i++){
			int pos = 0;
			
			while(mapa[pos][i] == 'X'){
				ver[pos][i] = -1;
				pos++;
			}
			while(pos < N){
				while(mapa[pos][i] == '.'){
					ver[pos][i] = cont;
					pos++;
				}
				cont++;
				while(mapa[pos][i] == 'X'){
					ver[pos][i] = -1;
					pos++;
				}
			}
		}
		B = cont - A;
		for(int i = 0; i < N; i++){
			int pos = 0;
			
			while(pos < N){
				while(mapa[i][pos] == '.'){
					E[hor[i][pos]].push_back(ver[i][pos]);
					pos++;
				}
				while(mapa[i][pos] == 'X')
					pos++;
				
			}
		}
		for(int i = 0; i < N; i++){
			int pos = 0;
			while(pos < N){
				while(mapa[pos][i] == '.'){
					E[ver[pos][i]].push_back(hor[pos][i]);
					pos++;
				}
				cont++;
				while(mapa[pos][i] == 'X')
					pos++;
				
			}
		}
		cout << MaximumBipartiteMatching(A, B) << endl;
		for(int i = 0; i < cont; i++)
			E[i].clear();
	}
	
	return 0;
}