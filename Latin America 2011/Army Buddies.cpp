#include <bits/stdc++.h>

using namespace std;

set <int> A;
set <int> :: iterator it;

int main(){
	int N, M;
	while(true){
		cin >> N >> M;
		if(N == 0 && M == 0)
			break;
		for(int i = 1; i <= N; i++)
			A.insert(i);
		for(int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;
			it = A.lower_bound(a);
			int ant;
			while(*it <= b && it != A.end()){
				ant = *it;
				it++;
				A.erase(ant);
			}
			if(it == A.begin())
				cout << "* "; 
			else{
				it--;
				cout << *it  << " ";
				it++;
			}
			if(it == A.end())
				cout << "*\n";
			else cout << *it << endl;
			
		}
		cout << "-\n";
	}
	return 0;
}