#include <iostream>
#include <string>
using namespace std;

int main()
{
    float F ;
    float C ;
    cout << "화씨온도: ";
    cin >> F;
    
    cout << "섭씨온도=" << (5.0/9.0)*(F-32) << endl;

    return 0;
}