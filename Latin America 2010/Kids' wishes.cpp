	#include <bits/stdc++.h>

using namespace std;

#define lld long long int

struct DS {

	int sets;
	int parent[200001];
	int members[200001];
	
	void init(int n) {
		sets = n;
		for (int i = 0; i < n; i++)
			parent[i] = i, members[i] = 1;
	}
	
	int find(int a) {
		if (a == parent[a]) return a;
		return parent[a] = find(parent[a]);
	}
	
	int setsize(int a) {
		return members[find(a)];
	}
	
	bool joined(int a, int b) {
		return find(a) == find(b);
	}
	
	void join(int a, int b) {
		if (joined(a, b)) return;
		members[find(b)] += members[find(a)];
		parent[find(a)] = find(b);
		sets--;
	}
	
};

set< lld > s;
map< int, int > c;
map< int, int > m;
DS ds;
int a, b, k, w, i;
bool ans;

lld h(int a, int b) {
	if (a > b)
		return (lld)b * 1000000000LL + (lld)a;
	return (lld)a * 1000000000LL + (lld)b;
}

int main() {	
	while(true) {
		scanf("%d%d", &k, &w);
		if (k == 0) break;
		ds.init(w * 2);
		s.clear();
		c.clear();
		m.clear();
		i = 0;
		ans = true;
		while (w--) {
			scanf("%d%d", &a, &b);
			if (c.find(a) == c.end()) {
				c[a] = i++;
			}
			if (c.find(b) == c.end()) {
				c[b] = i++;
			}
			if (s.find(h(a, b)) == s.end()) {
				s.insert(h(a, b));
				if (m.find(a) == m.end())
					m[a] = 0;
				if (m.find(b) == m.end())
					m[b] = 0;
				m[a]++;
				m[b]++;
				if (m[a] == 3 || m[b] == 3) {
					ans = false;
				}
				if (ds.joined(c[a], c[b]) && ds.setsize(c[a]) != k) {
					ans = false;
				} else {
					ds.join(c[a], c[b]);
				}
			}
		}
		puts(ans ? "Y" : "N");
	}
	return 0;
}