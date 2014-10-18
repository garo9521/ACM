#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

string braile[3];

					
map <string, int> mapeo;
char cadena[MAXN];
string busca[MAXN];

int main(){
	braile[0] = ".**.*.*****.*****..*";
	braile[1] = "**..*....*.**.*****.";
	braile[2] = "....................";
	for(int j = 0; j < 10; j++){
		string a = "";
		for(int i = 0; i < 3; i++){
			a += braile[i][j * 2];
			a += braile[i][j * 2 + 1];
		}
		mapeo[a] = j;	
	}
	int N;
	while(true){
		cin >> N;
		if(N == 0)
			break;
		char c;
		cin >> c;
		if(c == 'S'){
			cin >> cadena;
			for(int j = 0; j < 3; j++){
				bool chosto = false;
				for(int i = 0; cadena[i]; i++){
					int num = cadena[i] - '0';
					if(chosto)
						cout << " ";
					chosto = true;
					cout << braile[j][num * 2] << braile[j][num * 2 + 1];
				}
				cout << endl;
			}
		}else{
			for(int i = 0; i < N; i++)
				busca[i] = "";
			for(int j = 0; j < 3; j++){
				for(int i = 0; i < N; i++){
					string a;
					cin >> a;
					busca[i] += a[0];
					busca[i] += a[1];
				}
			}
			for(int i = 0; i < N; i++)
				cout << mapeo[busca[i]];
			cout << endl;
		}
	}
	return 0;
}