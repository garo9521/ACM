#include <bits/stdc++.h>

using namespace std;

#define MAXN 100050
#define lld long long int

lld N, M, MOD, B;

lld BIT[MAXN];
lld base[MAXN];
lld num[MAXN];

void update(int i, lld x){
	for(; i <= N; i += i & -i)
		BIT[i] = (BIT[i] + x) % MOD;
}

lld query(int i){
	lld sum = 0;
	for(; i; i -= i & -i)
		sum = (BIT[i] + sum) % MOD;
	return sum;
}


lld range(int a, int b){
	return (query(b) - query(a - 1) + MOD) % MOD;
}

lld POW(lld a, lld b){
	lld ans = 1;
	while(b){
		if(b & 1)
			ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b /= 2;
	}
	return ans;
}

int main(){
	while(true){
		cin >> B >> MOD >> N >> M;
		if(B == 0 && MOD == 0 && N == 0 && M == 0)
			break;
		for(int i = 0; i <= N; i++)
			BIT[i] = num[i] = 0;
		base[N] = 1 % MOD;
		for(int i = N - 1; i > 0; i--)
			base[i] = (base[i + 1] * B) % MOD;
		for(int i = 0; i < M; i++){
			char c;
			cin >> c;
			if(c == 'E'){
				lld a, b;
				cin >> a >> b;
				update(a, ((b * base[a]) % MOD - num[a] + MOD) % MOD);
				num[a] = (b * base[a]) % MOD;
			}else{
				int a, b;
				cin >> a >> b;
				cout << (range(a, b) * POW(base[b], MOD - 2)) % MOD << endl;
			}
		}
		cout << "-\n";
	}
	return 0;
}