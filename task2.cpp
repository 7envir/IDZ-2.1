#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream input_file = fstream("docs/in2.dat", ios::in);
    if (!input_file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    } else {
        long long a;
        input_file >> a;
        input_file.close();
        cout << "a is " << a << ", now wait half day =)" << endl;
        a = a * a;
        a = a * a;
        a = a * a;
        a = a * a;
        a = a * a;
        a = a * a;
        cout << "Joke, your num in 64 pow is: " << a << endl;
    }
    return 0;
}