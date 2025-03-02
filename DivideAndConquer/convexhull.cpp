#define NULL 0
#include <vector>
#include <cmath>
#include <cfloat> 
#include <cstdio>
#include <math.h>

using namespace std;

struct point {
	float x, y;
};

struct vec {
	float x, y;
};

float dotProduct(vec v1, vec v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

float magnitude(vec v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

vec diff(point p1, point p2) {
	vec v;
	v.x = p2.x - p1.x;
	v.y = p2.y - p1.y;
	return v;
}

class PointSet
{
	private:
		vector<point> points;
	public:
		PointSet() { points = {}; }
		void insert(float x, float y) {
			point newPoint;
			newPoint.x = x;
			newPoint.y = y;
			points.push_back(newPoint);
		};
		void insert(point p) {
			points.push_back(p);
		}
		PointSet SimpleConvexHull();
		void print();
};

void PointSet::print() {
	int size = points.size();
	for (int i = 0; i < size; i++) {
		printf("Point: %f, %f\n", points[i].x, points[i].y);
	}
}

PointSet PointSet::SimpleConvexHull() {
	int size = points.size();
	if (size < 3) {
		printf("Cannot form a hull with less than 3 points");
		return PointSet();
	}
	PointSet hull = PointSet();
	bool incomplete = true;
	vec seg; // Previous line segment
	seg.x = 0.0;
	seg.y = -1.0;
	float largestRad = 0.0;
	point location = points[0];
	for (int i = 0; i < size; i++)  {
		if (points[i].x < location.x) {
			location = points[i];
		}
	}
	hull.insert(location);
	point start = location;
	float maxRadians;
	while (incomplete) {
		maxRadians = FLT_MIN;
		point next;
		vec newShift;
		for (int i = 0; i < size; i++) {
			vec shift = diff(location, points[i]);
			float rad = acos(dotProduct(shift, seg) / (magnitude(shift) * magnitude(seg)));
			if (rad > maxRadians && rad <= M_PI) {
				maxRadians = rad;
				next = points[i];
				newShift = shift;
			}
		}
		if (next.x == start.x && next.y == start.y) {
			incomplete = false;
		} else {
			hull.insert(next);
			location = next;
			newShift.x = -newShift.x;
			newShift.y = -newShift.y;
			seg = newShift;
		}
	}
	return hull;
}

int main() {
	PointSet points = PointSet();
	points.insert(1.0, 0.0);
	points.insert(2.0, 1.0);
	points.insert(3.0, 4.0);
	points.insert(4.0, 3.0);
	points.insert(2.0, 5.0);
	points.insert(1.0, 3.0);
	points.insert(5.0, 5.0);
	points.insert(2.0, 0.0);
	points.insert(3.0, 0.0);
	points.insert(-1.0, 4.0);
	points.insert(5.0, 0.0);
	PointSet hull = points.SimpleConvexHull();
	hull.print();
	return 0;
}
