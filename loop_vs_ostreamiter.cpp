#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    // prepare an array
    array<int, 100000> ar;
    iota(ar.begin(), ar.end(), 0);

    // for loop
    clock_t start1 = clock();
    for (int x : ar) {
        cout << x;
    }
    clock_t end1 = clock();

    // ostream_iterator
    clock_t start2 = clock();
    copy(ar.begin(), ar.end(), ostream_iterator<int>(cout));
    clock_t end2 = clock();


    cout << endl;
    cout << "length: 100000" << endl;
    // time with for loop
    cout << "time (for loop): " << (double)(end1 - start1) << "sec." << endl;
    // time with ostream_iterator
    cout << "time (ostream_iterator): " << (double)(end2 - start2) << "sec." << endl;
}