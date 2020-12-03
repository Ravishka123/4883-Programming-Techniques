

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namepsace std;

struct Point {
    double x;
    double y;
};


void Intersect(Point &A, Point &B, Point &C, Point &D, Point &E) 
{ 
    
    double a1 = B.y - A.y; 
    double b1 = A.x - B.x; 
    double c1 = a1*(A.x) + b1*(A.y); 
  
    
    double a2 = D.y - C.y; 
    double b2 = C.x - D.x; 
    double c2 = a2*(C.x) + b2*(C.y); 
  
    
    double determinant = a1*b2 - a2*b1; 

    double x = (b2*c1 - b1*c2)/determinant; 
    double y = (a1*c2 - a2*c1)/determinant; 
    E.x = x;
    E.y = y;
} 

bool RevSort(const Point& lhs, const Point& rhs) {
    return lhs.x > rhs.x;
}

double Distance(Point &a, Point &b) {
    return Hypoteneuse(a.x - b.x, a.y - b.y);
}



int main(int argc, char** argv) {
    int tests;
    double Meter = 0;
    Point Maximum = {0.0, 0.0};

    bool first = true;
    cin >> tests;

    while(tests--) {
        vector<Point> coordinates;

        int MyPairs;
        cin >> MyPairs;
        
        while(MyPairs--) {
            double x;
            double y;
            cin >> x >> y;

            coordinates.push_back({x, y});
        }

        sort(coordinates.begin(), coordinates.end(), RevSort);

        

        for (vector<Point>::size_type i = 1; i < coordinates.size(); i += 2) {

            if (coordinates[i].y > Maximum.y) {
                if (first) {
                    Meter += Distance(coordinates[i], coordinates[i - 1]);
                    first = false;
                }
                else {
                    Point inter = {0.0, 0.0};
                    Point p3 = {coordinates[i].x, Maximum.y};
                    Intersect(coordinates[i], coordinates[i-1], Maximum, p3, inter);

                    Meter += Distance(coordinates[i], inter);
                }
                
                Maximum = coordinates[i];
            }
        }

        cout << setprecision(2) << setiosflags(fixed) << Meter << endl;
    }
    return 0;
}
