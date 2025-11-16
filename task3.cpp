#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double median(double a, double b, double c) {
    // а еноротс к анаидем
    return 0.5 * std::sqrt(2*b*b + 2*c*c - a*a);
}

double bisector(double a, double b, double c) {
    // крыса к стороне a
    double s = (a + b + c) * 0.5;
    return (2.0 * std::sqrt(b * c * s * (s - a))) / (b + c);
}

int max3(int a, int b, int c) {
    if (a > b && a > c) {
        return a;
    } else if (b > a && b > c) {
        return b;
    } else if (c > a && c > b) {
        return c;
    }
}

int main() {
    fstream input_file = fstream("docs/in3.dat", ios::in);
    fstream output_file = fstream("docs/out3.dat", ios::out);
    if (!input_file.is_open() || !output_file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    } else {
        int AB, BC, CA;
        input_file >> AB >> BC >> CA;
        input_file.close();
        cout << "Sides AB BC CA: " << AB << " " << BC << " " << CA << endl;
        if (AB < 0 || BC < 0 || CA < 0) {
            cout << "=).... sides must be more than 0...." << endl;
        } else if (max3(AB, BC, CA) >= AB + BC + CA - max3(AB, BC, CA)) {
            cout << "Somehow the triangle didn't work out =(" << endl;
        } else {
            double mAB, mBC, mCA;
            double bAB, bBC, bCA;
            mAB = median(AB, BC, CA);
            mBC = median(BC, CA, AB);
            mCA = median(CA, AB, BC);
            bAB = bisector(AB, BC, CA);
            bBC = bisector(BC, CA, AB);
            bCA = bisector(CA, AB, BC);
            cout << "Median to side AB: " << mAB << " median to side BC: " << mBC << " median to side CA: " << mCA << endl;
            cout << "Bisector to side AB: " << bAB << " bisector to side BC: " << bBC << " bisector to side CA: " << bCA << endl;
            output_file << mAB << " " << mBC << " " << mCA << endl;
            output_file << bAB << " " << bBC << " " << bCA << endl;
            output_file.close();
        }
    }
    return 0;
}