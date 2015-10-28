#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

char cadena[MAXN];

char Mayus(char x){
	if(x >= 'A' && x <= 'Z')
		return x;
	return x - 'a' + 'A';
}

int main(){
	while(true){
		gets(cadena);
		if(cadena[0] == '*')
			break;
		char letra = Mayus(cadena[0]);
		bool can = true;
		for(int i = 1; cadena[i]; i++){
			if(cadena[i - 1] == ' '){
				if(Mayus(cadena[i]) != letra){
					can = false;
					break;
				}
			}
		}
		if(can) puts("Y");
		else puts("N");
	}
	return 0;
}