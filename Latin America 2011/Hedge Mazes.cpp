#include <bits/stdc++.h>

using namespace std;

#define MAXV 100000

set<int> ArticulationPoints;   // Result
set< pair<int, int> > Bridges; // Result

int low[MAXV];
int num[MAXV];
int rootChild = 0;
int vertexCount = 1;
vector<int> E[MAXV];

void ArticulationPointsAndBridges(int u, int p){
    vector<int>::iterator v;
    low[u] = num[u] = vertexCount++;
    for(v = E[u].begin(); v != E[u].end(); v++){
        if(num[*v] == 0){
            if(p == -1) rootChild++;
            ArticulationPointsAndBridges(*v, u);
            if(num[u] <= low[*v])
                ArticulationPoints.insert(u);
            if(num[u] < low[*v])
                Bridges.insert(make_pair(u, *v));
            low[u] = min(low[*v], low[u]);
        } else if(*v != p)
            low[u] = min(num[*v], low[u]);
    }
    if(p == -1 && rootChild < 2)
        ArticulationPoints.erase(u);
} // O(v + e)

struct Union{
    int sets;
    int* parent;
    int* members;
    
    void init(int n){ // O(v)
        sets = n;
        parent = new int[n];
        members = new int[n];
        for(int i = 0; i < n; i++)
            parent[i] = i, members[i] = 1;
    }
    
    int find(int a){ // O(1)
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
    
    int setsize(int a){ // O(1)
        return members[find(a)];
    }
    
    bool joined(int a, int b){ // O(1)
        return find(a) == find(b);
    }
    
    void join(int a, int b){ // O(1)
        if(joined(a, b)) return;
        members[find(b)] += members[find(a)];
        parent[find(a)] = find(b);
        sets--;
    }
};


int main(){
	int N, M, Q;
	while(true){
		cin >> N >> M >> Q;
		
		for(int i = 0; i < N; i++)
			E[i].clear();
		Bridges.clear();
		for(int i = 0; i < N; i++){
			num[i] = 0;
			low[i] = 0;
		}
		
		if(N == 0 && M == 0 && Q == 0)
			break;
		for(int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;
			a--, b--;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		for(int i = 0; i < N; i++){
			if(num[i] == 0){
				
				vertexCount = 1;
				rootChild = 0;
				ArticulationPointsAndBridges(i, -1);
			}
		}
		Union grafo;
		grafo.init(N);
		for(set<pair<int, int> > :: iterator it = Bridges.begin(); it != Bridges.end(); it++)
			grafo.join(it -> first, it -> second);
		
		while(Q--){
			int a, b;
			cin >> a >> b;
			a--, b--;
			if(grafo.joined(a, b))
				puts("Y");
			else puts("N");
		}
		puts("-");	
	}

	return 0;
}