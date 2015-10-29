#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define MAXN 105
#define PI M_PI
#define ERROR 1e-12
#define RAD (PI / 180)

bool equal(double a, double b){ // O(1)
    return fabs(a - b) < ERROR;
}

struct Point{
    double x, y;
    bool operator <(Point cmp) const{
        if(equal(x, cmp.x))
            return y < cmp.y;
        return x < cmp.x;
    }
};



Point P(double x, double y){ // O(1)
   Point p;
   p.x = x;
   p.y = y;
    return p;
}


Point Vector(Point o, Point p){ // O(1)
    return P(p.x - o.x, p.y - o.y);
}

double Cross(Point u, Point v){ // O(1)
    return u.x * v.y - v.x * u.y;
}


bool Collinear(Point p, Point q, Point r){ // O(1)
    return equal(Cross(Vector(p, q), Vector(p, r)), 0);
}

struct Line{
    Point p, q;
    double a, b, c;
};

Line L(Point p, Point q){ // O(1)
    if(q < p) return L(q, p);
    Line* l = new Line();
    l->p = p, l->q = q;
    l->c = Cross(p, q);
    l->a = p.y - q.y;
    l->b = q.x - p.x;
    return *l;
}

Point Intersection(Line l, Line m){ // O(1)
    double div = m.a * l.b - l.a * m.b;
    double x = m.b * l.c - l.b * m.c;
    double y = m.a * l.c - l.a * m.c;
    return P(x / div, y / -div);
}



Point puntos[MAXN];
map<Point, int> cubeta;

Point Circuferencia(Point A, Point B, Point C){
	Point Pm = P((A.x + B.x) / 2.0, (A.y + B.y) / 2.0);
	Line linea1;
	linea1.a = B.y - A.y;
	linea1.b = B.x - A.x;
	linea1.c = Pm.x * (A.x - B.x) - Pm.y * (B.y - A.y);
	Pm = P((B.x + C.x) / 2.0, (B.y + C.y) / 2.0);
	Line linea2;
	linea2.a = B.y - C.y;
	linea2.b = B.x - C.x;
	linea2.c = Pm.x * (C.x - B.x) - Pm.y * (B.y - C.y);
	return Intersection(linea1, linea2);
}

int main(){
	while(true){
		int N;
		cin >> N;
		if(N == 0)
			break;
		for(int i = 0; i < N; i++)
			cin >> puntos[i].x >> puntos[i].y;
		int ans = 2;
		if(N > 2){
			for(int i = 0; i < N; i++){
				for(int j = i + 1; j < N; j++){
					
					cubeta.clear();
					for(int k = 0; k < N; k++){
						if(i == k || j == k)
							continue;
						if(Collinear(puntos[i], puntos[j], puntos[k]))
							continue;
						Point centro = Circuferencia(puntos[i], puntos[j], puntos[k]);
						cubeta[centro]++;
						ans = max(ans, cubeta[centro] + 2);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}