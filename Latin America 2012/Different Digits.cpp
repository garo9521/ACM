#include <bits/stdc++.h>

using namespace std;

#define MAXN 5001

int ans[MAXN];
map <int, int> C;

int main(){
	for(int i = 1; i < MAXN; i++){
		int a = i;
		C.clear();
		int can = 1;
		while(a){
			if(C[a % 10]){
				can = 0;
				break;
			}
			C[a % 10] = 1;
			a /= 10;
		}
		ans[i] = ans[i - 1] + can;
	}
	int a, b;
	while(cin >> a >> b)
		cout << ans[b] - ans[a - 1] << endl;
	
	return 0;
}