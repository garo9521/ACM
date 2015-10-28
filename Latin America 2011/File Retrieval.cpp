#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

char cadena[MAXN];


int SA[MAXN];
int rank[MAXN];
int tray[MAXN];
int tempSA[MAXN];
int tempRank[MAXN];

void CountingSort(int n, int k){ // O(n)
    int ranks = max(n, 256);
    fill(tray, tray + ranks, 0);
    
    for(int i = 0; i < n; i++)
        if(n <= i + k) tray[0]++;
        else tray[rank[i + k]]++;
        
    for(int i = 0, j = 0; i < ranks; i++)
        j += tray[i], tray[i] = j - tray[i];
        
    for(int i = 0; i < n; i++)
        if(n <= SA[i] + k) tempSA[tray[0]++] = SA[i];
        else tempSA[tray[rank[SA[i] + k]]++] = SA[i];
    copy(tempSA, tempSA + n, SA);
}

void SuffixArray(char* s, int n){ // O(n log n)
    copy(s, s + n, rank);
    for(int i = 0; i < n; i++) SA[i] = i;
    for(int i = 1; i < n; i <<= 1){
        CountingSort(n, i);
        CountingSort(n, 0);
        int ranks = 0;
        tempRank[SA[0]] = 0;
        for(int j = 1; j < n; j++){
            if(rank[SA[j]] != rank[SA[j - 1]] ||
            rank[SA[j]+i] != rank[SA[j-1] + i])ranks++;
            tempRank[SA[j]] = ranks;
        }
        copy(tempRank, tempRank + n, rank);
        if(rank[SA[n - 1]] == n - 1) break;
    }
}

// Starts code for Longest Common Prefix

int LCP[MAXN];
int prev[MAXN];
int plcp[MAXN];

void LongestCommonPrefix(char* s, int n){ // O(n)
    prev[SA[0]] = -1;
    for(int i = 1; i < n; i++)
        prev[SA[i]] = SA[i - 1];
        
    int L = 0;
    plcp[SA[0]] = 0;
    for(int i = 0; i < n; i++){
        if(prev[i] == -1) continue;
        while(prev[i] + L < n && i + L < n
        && s[i + L] == s[prev[i] + L]) L++;
        plcp[i] = L, L = max(L - 1, 0);
    }
    
    for(int i = 0; i < n; i++)
        LCP[i] = plcp[SA[i]];
}


int main(){
	int N;
	int M = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
		scanf("%s", cadena + M);
		for( ; cadena[M]; M++);
		cadena[M++] = '$';
	}
	SuffixArray(cadena, M);
	LongestCommonPrefix(cadena, M);
	string A = cadena;
	for(int i = 0; i < M; i++){
		
		cout << LCP[i] << endl;
		cout << A.substr(SA[i]) << endl;
	}
	return 0;
}