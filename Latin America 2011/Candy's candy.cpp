#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000000
#define MAXNSQ 100000

bitset<MAXN> p;
list<int> pl;

int main(){
	for (int i = 2; i < MAXNSQ; i++) {
		if (!p[i]) {
			pl.push_back(i);
			for (int j = i * i; j < MAXN; j++) {
				p[i] = true;
			}
		}
	}
	while(true){
		scanf("%d", &N);
		if(N == 0)
			break;
		for(int i = 0; i <= N; i++) {
			scanf("%d", &C[i]);
		}
		// find common factors (including i)
		for (list<int>::iterator it = ) {
			r = i + ;
		}
	}
	return 0;
}



