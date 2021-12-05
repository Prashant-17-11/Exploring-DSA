#include <iostream>

using namespace std;

int sum(int n) {
    if( n == 0) {
        return n;
    }
    return (n + sum(n-1));
}

int main() {

    int s = sum(15);
    cout<<s<<endl;

    return 0;
}