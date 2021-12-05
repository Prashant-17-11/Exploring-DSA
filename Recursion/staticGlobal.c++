#include <iostream>

using namespace std;

int fun(int n) {
    if (n>0) {
        return fun(n-1) + n;
    }
    return 0;
}

int fun2(int n) {
    static int x = 0;
    if(n>0) {
        x++;
        return fun2(n-1)+x;
    }
    return 0;
}

int y = 0;
int fun3(int n) {
    if(n>0) {
        y++;
        return fun2(n-1)+y;
    }
    return 0;
}


int main() {
    int r ;
    r = fun(5);
    cout<<"fun : "<<r<<endl;
    r = fun(5);
    cout<<"fun : "<<r<<endl;

    r = fun2(5);
    cout<<"fun2 : "<<r<<endl;
    r = fun2(5);
    cout<<"fun2 : "<<r<<endl;

    r = fun3(5);
    cout<<"fun3 : "<<r<<endl;
    r = fun3(5);
    cout<<"fun3 : "<<r<<endl;

    return 0;
}