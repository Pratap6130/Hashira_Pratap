#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

long long baseToDecimal(const string& str, int base) {
    long long result = 0;
    for(char c : str) {
        int val;
        if ('0' <= c && c <= '9') val = c - '0';
        else if ('a' <= c && c <= 'z') val = 10 + c - 'a';
        else if ('A' <= c && c <= 'Z') val = 10 + c - 'A';
        else return -1;
        if (val >= base) return -1;
        result = result * base + val;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        int base; string val;
        cin >> base >> val;
        y[i] = baseToDecimal(val, base);
    }
    double result = 0.0;
    for(int i=0; i<k; ++i) {
        double term = y[i];
        for(int j=0; j<k; ++j) {
            if(i != j)
                term *= -x[j] / double(x[i] - x[j]);
        }
        result += term;
    }
    cout << llround(result) << endl;
    return 0;
}
