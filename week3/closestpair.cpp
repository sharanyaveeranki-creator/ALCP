#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool compareX(Point a, Point b) {
    return a.x < b.x;
}

bool compareY(Point a, Point b) {
    return a.y < b.y;
}

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}

double closestPair(vector<Point>& points, int left, int right) {
    if (right - left <= 2) {
        double minDist = DBL_MAX;

        for (int i = left; i <= right; i++) {
            for (int j = i + 1; j <= right; j++) {
                minDist = min(minDist, distance(points[i], points[j]));
            }
        }

        return minDist;
    }

    int mid = (left + right) / 2;

    double leftDist = closestPair(points, left, mid);
    double rightDist = closestPair(points, mid + 1, right);

    double minDist = min(leftDist, rightDist);

    vector<Point> strip;

    int midX = points[mid].x;

    for (int i = left; i <= right; i++) {
        if (abs(points[i].x - midX) < minDist)
            strip.push_back(points[i]);
    }

    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() &&
             (strip[j].y - strip[i].y) < minDist; j++) {
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }

    return minDist;
}

int main() {
    int n;

    cout << "Enter number of points: ";
    cin >> n;

    vector<Point> points(n);

    cout << "Enter x and y coordinates of each point:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Enter point " << i + 1 << ": ";
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), compareX);

    double result = closestPair(points, 0, n - 1);

    cout << "Minimum distance between closest pair = " << result << endl;

    return 0;
}