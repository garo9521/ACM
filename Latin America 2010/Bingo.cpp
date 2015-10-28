#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005

int num[MAXN];

bool checa(int x, int N){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if(abs(num[i] - num[j]) == x)
				return true;
	return false;
}

int main(){
	while(true){
		int N, M;
		cin >> N >> M;
		if(N == 0 && M == 0)
			break;
		for(int i = 0; i < M; i++)
			cin >> num[i];
		bool can = true;
		for(int i = 0; i <= N; i++){
			if(!checa(i, M)){
				can = false;
				break;
			}
		}
		if(can)
			puts("Y");
		else puts("N");
	}
	return 0;
}