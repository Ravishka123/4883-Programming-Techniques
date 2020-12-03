#include <iostream>
#include <math.h>
 
const double eps = 1e-6;
 
typedef struct _point
{
	double x, y;
}point;
point M, P1, P2;
 
point new_point(double x, double y)
{
	point p;
	p.x = x;
	p.y = y;
	return p;
}
 
double Distance(point p, point q)
{
	return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}
 
point foot_point(point m, point p, point q) // Ax + by + C = 0
{
	double a = p.x-q.x, b = p.y-q.y, c = (q.y-p.y)*m.y+(q.x-p.x)*m.x;
	double a1 = q.y-p.y, b1 = p.x-q.x, c1 = (q.x-p.x)*p.y+(p.y-q.y)*p.x;
	double x = (c1*b-c*b1)/(a*b1-a1*b);  
   	double y = (c1*a-c*a1)/(a1*b-a*b1);
	return new_point(x, y);
}
 

 
point ClosestPoint(point m, point p, point q)
{
	point p = foot_point(m, p, q);
	if (!Line(p, p, q)) {
		if (Distance(m, p) - Distance(m, q) > eps) {
			return q;
		}else {
			return p;
		}
	}else {
		return p;
	}
}
 
 bool Line(point m, point p, point q)
{
	return (p.x-m.x)*(q.x-m.x) <= eps && (p.y-m.y)*(q.y-m.y) <= eps;
}
int main()
{
	int n;
	while (cin>> M.x >>M.y) {
		cin >>n >>P1.x >>P1.y;
		point  p = P1;
		double mimimum = Distance(M, P1);
		while (n --) {
			cin>>P2.x >> P2.y);
			point Q = ClosestPoint(M, P1, P2);
			if (Distance(M, p) - Distance(M, Q) > eps) {
				p = Q;
			}
			P1 = P2;
		}
		cout <<  p.x<< endl<< p.y <<endl;
	}
	
	return 0;

}
