#include <bits/stdc++.h>

#define MAXN 1000

using namespace std;

struct DisjointSet{
	int sets;
	int* parent;
	int* members;
	
	void init(int n){ // O(n)
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

char C[MAXN];
int a, b, c, d;
                         
int main(){
    DisjointSet ds;
	int N;
	
	while(scanf("%d", &N) != EOF){
		int lim = N * 2 + 1;
		ds.init(lim * (lim - 1));
		for(int i = 1; i < N * 2; i++){
			scanf("%s", C);
			for(int j = 1; C[j - 1]; j++){ 
				a = (i - 1) * lim + j * 2 - 1;
				b = a  + 1;
				c = i * lim + j * 2 - 1;
				d = c + 1;
				if(i % 2 == 0){
					a++;
					b++;
					c++; 
					d++;
				}   
				if(C[j - 1] == 'H'){
					ds.join(a - 1, b - 1);
					ds.join(c - 1, d - 1);
				}else{
					ds.join(a - 1, c - 1);
					ds.join(b - 1, d - 1);
				}
			}
		} 
		for(int i = 1; i < lim;i += 2){
			ds.join(i, i + 1);
			ds.join(i + (lim - 2) * lim, i + 1 + (lim - 2) * lim);
			
		} 
		for(int i = 1; i < N * 2; i += 2){
			if(((i + 1) * lim + 1) <= lim * N * 2)
				ds.join(i * lim, (i + 1) * lim);
			ds.join(i * lim -1, (i + 1) * lim - 1); 
		}  
		printf("%d\n", ds.sets - 1);
	}
    return 0;
}
