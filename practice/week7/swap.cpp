#include <iostream>
using namespace std;

/*
void swap(int& x, int& y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
*/

void swap(int* x, int* y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
} //포인터로 할 경우

int main(){
    int a = 100, b = 200;

    cout << "a=" << a << " b=" << b << endl;

    swap(a,b);

    cout << "a=" << a << " b=" << b << endl;

    return 0;
}
