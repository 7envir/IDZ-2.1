#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double pi = acos(-1.0);
    const double inner_radius = 20.0;
    double radius, area;
    cout << "Enter a number: ";
    cin >> radius;
    if (radius <= inner_radius) {
        cout << "Your number is smaller than inner radius" << endl;
        cout << "Bad user D:" << endl;
    } else {
        area = (radius*radius-inner_radius*inner_radius)*pi;
        cout << "The area is " << area << endl;
    }
    return 0;
}