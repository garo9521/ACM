#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int BIT[MAXN];
int num[MAXN];
int N, M;

void update(int i, int x){
	for( ; i < MAXN; i += i & (-i))
		BIT[i] += x;
}

int query(int i){
	int sum = 0;
	for(; i ; i -= i & (-i))
		sum += BIT[i];
	return sum;
}

int range(int a, int b){
	return query(b) - query(a - 1);
}

int main(){
	while(cin >> N >> M){
		for(int i = 1; i < MAXN ;i++)
			BIT[i] = 0;
		for(int i = 1; i <= N; i++){
			cin >> num[i];
			if(num[i] < 0)
				update(i, 1), num[i] = 1;
			else if(num[i] > 0)
				num[i] = 0;
			else if(num[i] == 0)
				update(i, 1 << 20), num[i] = 1 << 20;
		}
		while(M--){
			char c;
			int a, b;
			cin >> c >> a >> b;
			if(c == 'P'){
				int ans = range(a, b);
				if(ans >= N)
					cout << "0";
				else if(ans % 2)
					cout << "-";
				else 
					cout << "+";
			}else{
				if(b > 0)
					b = 0;
				else if(b < 0)
					b = 1;
				else if(b == 0)
					b = 1 << 20;
				update(a, b - num[a]);
				num[a] = b;
			}
		}
		puts("");
	}
	return 0;
}