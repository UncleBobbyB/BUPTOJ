#include<bitset>
#include<cassert>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<cctype>
#include<algorithm>
#include<map>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<deque>
#include<algorithm>
#include<set>
// #include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define pli pair<LL, int>
#define pil pair<int, LL>
#define pll pair<LL, LL>
#define vi vector<int>
#define LL long long
#define INF 1e9
#define DINF 1e30
#define LLINF 1e18
#define ULL unsigned long long
#define UI unsigned int
#define eps 1e-9
#define PI acos(-1.0)

#define all(x) (x).begin(), (x).end()
#define ue(x) (x).erase(unique(all((x))), (x).end())

void err() {
  cout << "shit" << endl;
  exit(1);
}

const double TWO_PI = PI * 2;

double torad(double deg) {
  return deg / 180 * PI;
}

inline double dcmp(double d) {
  if(fabs(d) <= eps) return 0;
  return d < 0 ? -1 : 1;
}

inline double dcmp(double a, double b) {
  return dcmp(a - b);
}

struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point(const pii& p) {
	  x = p.first;
	  y = p.second;
  }

} ;

ostream& operator << (ostream& os, const Point& p) {
  os << '(' << p.x << ',' << p.y << ')';
}

istream operator >> (istream& ins, vector<Point>& p) {
  double x, y;
  ins >> x >> y;
  p.pb(Point(x, y));
}

istream& operator >> (istream& ins, Point& p) {
  ins >> p.x >> p.y;
  //p = Point(1, 2);
}

typedef Point Vector;
typedef vector<Point>  Polygon;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x * p, A.y * p); }
Vector operator / (Vector A, double p) { return Vector(A.x / p, A.y /p); }

bool operator < (const Point& a, const Point& b) {
  return dcmp(a.x, b.x) < 0  || (dcmp(a.x, b.x) == 0 && dcmp(a.y, b.y) < 0);
}

bool operator == (const Point& a, const Point& b) {
  return dcmp(a.x, b.x) == 0 && dcmp(a.y, b.y) == 0;
}

double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
double Len(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Len(A) / Len(B)); }
double Angle(Vector v) { return atan2(v.y, v.x); }
double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
double Area2(Point a, Point b, Point c) { return Cross(b - a, c - a); }

Vector Rotate(Vector A, double rad) {
  return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

Vector Normal(Vector A) {
  double len = Len(A);
  assert(dcmp(len) > 0);
  return Vector(-A.y / len, A.x / len);
}

Point getLineIntersection(Point P, Vector v, Point Q, Vector w) {
  Vector u = P - Q;
  assert(dcmp(Cross(v, w)) != 0);
  double t = Cross(w, u) / Cross(v, w);
  return P + v * t;
}

double DistToLine(Point P, Point A, Point B) {
  Vector v1 = B - A, v2 = P - A;
  return fabs(Cross(v1, v2)) / Len(v1);
}

double DistToSegment(Point P, Point A, Point B) {
  if(A == B) return Len(P - A);
  Vector v1 = B - A, v2 = P - A, v3 = P - B;
  if(dcmp(Dot(v1, v2) < 0)) return Len(v2);
  else if(dcmp(Dot(v1, v3)) > 0) return Len(v3);
  return fabs(Cross(v1, v2)) / Len(v1);
}

Point getLineProjection(Point P, Point A, Point B) {
  Vector v = B - A;
  return A + v * (Dot(v, P - A) / Dot(v, v));
}


bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
  double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1);
  double c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
  return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

bool OnSegment(Point P, Point a1, Point a2) {
  return dcmp(Cross(a1 - P, a2 - P)) == 0 && dcmp(Dot(a1 - P, a2 - P)) < 0;
}

double PolygonArea(Point p[], int n) {
  double area = 0;
  for(int i = 1; i < n - 1; i++) {
    area += Cross(p[i] - p[0], p[i + 1] - p[0]);
  }
  return area / 2;
}


double PolygonArea(vector<Point> p) {
  double area = 0;
  int n = p.size();
  for(int i = 1; i < n - 1; i++) {
    area += Cross(p[i] - p[0], p[i + 1] - p[0]);
  }
  return area / 2;

struct Line {
  Point p;
  Vector v;
  double ang;
  Line(Point p, Vector v):p(p),v(v) { ans = atan2(v.y, v.x); }
  bool operator < (cosnt Line& other) {
    return ang < other.ang;
  }
  Point point(double t) {
    return p + v*t;
  }
  Line move(double d) {
    return Line(p + Normal(v)*d, v);
  }

struct Circle {
  Point c;
  double r;
  Circle(Point c, double r):c(c),r(r) {}
  Point point(double a) {
    return Point(c.x + cos(a)*r, c.y + sin(a)*r);  
  }
};

Point GetLineIntersection(Line a, Line b) {
  return getLineIntersection(a.p, a.v, b.p, b.v);
}

int getLineCircleIntersection(Line L, Circle C, double& t1, double& t2, vector<Point>& sol){
  double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
  double e = a*a + c*c, f = 2*(a*b + c*d), g = b*b + d*d - C.r*C.r;
  double delta = f*f - 4*e*g; // 判别式
  if(dcmp(delta) < 0) return 0; // 相离
  if(dcmp(delta) == 0) { // 相切
    t1 = t2 = -f / (2 * e); sol.push_back(L.point(t1));
    return 1;
  }
  // 相交
  t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(L.point(t1));
  t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(L.point(t2));
  return 2;
}

int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol) {
  double d = Len(C1.c - C2.c);
  if(dcmp(d) == 0) {
    if(dcmp(C1.r - C2.r) == 0) return -1; // 重合，无穷多交点
    return 0;
  }
  if(dcmp(C1.r + C2.r - d) < 0) return 0;
  if(dcmp(fabs(C1.r-C2.r) - d) > 0) return 0;

  double a = Angle(C2.c - C1.c);
  double da = acos((C1.r*C1.r + d*d - C2.r*C2.r) / (2*C1.r*d));
  Point p1 = C1.point(a-da), p2 = C1.point(a+da);

  sol.push_back(p1);
  if(p1 == p2) return 1;
  sol.push_back(p2);
  return 2;
}

int isPointInPolygon(Point p, Polygon poly) {
  int wn = 0;
  int n = poly.size();
  for(int i = 0; i < n; i++) {
    if(OnSegment(p, poly[i], poly[(i + 1) % n])) return -1;
    int k = dcmp(Cross(poly[(i + 1) % n] - poly[i], p - poly[i]));
    int d1 = dcmp(poly[i].y, p.y);
    int d2 = dcmp(poly[(i + 1) % n].y, p.y);
    if(k > 0 && d1 <= 0 && d2 > 0) wn++;
    if(k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  if(wn != 0) return 1;
  return 0;
}

int ConvexHull(Point p[], int n, Point ch[]) {
  sort(p, p + n);
  int m = 0;
  for(int i = 0; i < n; i++) {
    while(m > 1 && dcmp(Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0) m--;
    ch[m++] = p[i];
  }
  int k = m;
  for(int i = n - 2; i >= 0; i--) {
    while(m > k && dcmp(Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0) m--;
    ch[m++] = p[i];
  }
  if(n > 1) m--;
  return m;
}


vector<Point> ConvexHull(vector<Point> p) {
  sort(all(p));
  ue(p);

  int n = p.size();
  int m = 0;
  vector<Point> ch(n + 1);
  for(int i = 0; i < n; i++) {
    while(m > 1 && dcmp(Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)) m--;
    ch[m++] = p[i];
  }
  int k = m;
  for(int i = n - 2; i >= 0; i--) {
    while(m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
    ch[m++] = p[i];
  }
  if(n > 1) m--;
  ch.resize(m);
  return ch;
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif

  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}


