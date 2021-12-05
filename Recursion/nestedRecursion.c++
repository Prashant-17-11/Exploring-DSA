#include <iostream>

using namespace std;

int fun(int n) {
    if(n>100) {
        cout<<n<<"\n";
        return n-10;
    }
    cout<<n<<"\n";
    return fun(fun(n+11));
}

int main() {
    int s = fun(95);
    cout<<s<<endl;
    return 0;
}