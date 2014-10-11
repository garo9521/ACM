#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

struct trie{
	map <char, int> hijos;
	bool finPal;
};

trie dic[MAXN];
char cadena[100];
int cont;
double ans;
int N;
double n;

double busca(int nodo){
	if(dic[nodo].hijos.begin() == dic[nodo].hijos.end())
		return 1.0;
	double hijos = 0.0;
	int cont = 0;
	for(map <char, int> :: iterator it = dic[nodo].hijos.begin(); it != dic[nodo].hijos.end(); it++){
		cont++;
		hijos += busca(it -> second);
	}
	if(cont > 1 || dic[nodo].finPal || nodo == 1)
		ans += hijos;
	if(dic[nodo].finPal)
		hijos += 1.0;
	return hijos;
}

int main(){
	while(scanf("%d", &N) != EOF){
		cont = 1;
		ans = 0.0;
		for(int i = 0; i < N; i++){
			scanf("%s", cadena);
			int nodo = 1;
			for(int j = 0; cadena[j]; j++){
				if(dic[nodo].hijos.find(cadena[j]) == dic[nodo].hijos.end()){
					dic[nodo].hijos[cadena[j]] = ++cont;
					nodo = cont;
				}else{
					nodo = dic[nodo].hijos[cadena[j]];
				}
			}
			dic[nodo].finPal = 1;
		}
		busca(1);
		ans /= (double)(N);
		printf("%.2lf\n", ans);
		for(int i = 1; i <= cont; i++){
			dic[i].hijos.clear();
			dic[i].finPal = 0;
		}
	}
	return 0;
}