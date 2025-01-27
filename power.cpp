#include <iostream>

using namespace std;

long long naivePower(long long x, int n){
    if (x == 0) return 0;
    if (n == 0) return 1;
    return x * naivePower(x, n-1);
}

long long unoptimiziedDCPower(long long x, int n){
    if (x == 0) return 0;
    if (n == 0) return 1;
    if (n % 2 == 0){
        return unoptimiziedDCPower(x , n/2) * unoptimiziedDCPower(x, n / 2);
    } else {
        return x * unoptimiziedDCPower(x, n / 2) * unoptimiziedDCPower(x, n / 2);
    }
}

long long optimizedDCPower(long long x, int n){
    if (x == 0) return 0;
    if (n == 0) return 1;
    long long temp = optimizedDCPower(x, n / 2);
    if (n % 2 == 0) {
        return temp * temp;
    } else {
        return x * temp * temp;
    }
}

int main(){
    long long x;
    int n;

    cout << "Enter x: ";
    cin >> x;
    cout << "Enter n: ";
    cin >> n;

    cout << "Naive Power: (" <<x<<","<<n<<") = "<<naivePower(x,n) << endl;
    cout << "Unoptimized DC Power: (" <<x<<","<<n<<") = "<<unoptimiziedDCPower(x,n) << endl;
    cout << "Optimized DC Power: (" <<x<<","<<n<<") = "<<optimizedDCPower(x,n) << endl;
    return 0;
}
