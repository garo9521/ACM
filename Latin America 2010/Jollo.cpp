#include <bits/stdc++.h>

using namespace std;

#define MAXN 20

int a[3], b[2];
set<int> s;

void ans(int n) {
	while (n <= 52 && s.find(n) != s.end()) n++;
	printf("%d\n", n > 52 ? -1 : n);
}

int main(){
	while(true){
		scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &b[0], &b[1]);
		if (a[0] == 0) {
			break;
		}
		s.clear();
		s.insert(a[0]);
		s.insert(a[1]);
		s.insert(a[2]);
		s.insert(b[0]);
		s.insert(b[1]);
		sort(a, a + 3);
		sort(b, b + 2);
		reverse(a, a + 3);
		reverse(b, b + 2);
		if (b[1] > a[0]) {
			ans(1);
		} else if (b[0] > a[0]) {
			if (b[1] > a[1]) {
				ans(a[1]);
			} else {
				ans(a[0]);
			}
		} else if (b[0] > a[1]) {
			if (b[1] > a[1]) {
				ans(a[1]);
			} else {
				puts("-1");
			}
		} else {
			puts("-1");
		}
	}
	return 0;
}