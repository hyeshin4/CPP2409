#include <iostream>
using namespace std;

int main()
{
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    if (a > b && a > c)
        largest = a;    
    else if (b > c) // if 부분에서 이미 a는 고려할 필요가 없기 때문에 b와 c만 비교해주었습니다.
        largest = b;    
    else
        largest = c;    
    // 5 5 3 을 입력하는 경우 기존의 코드에서는 바로 else문으로 넘어가버려서 가장 큰 수가 3으로 나오는 오류가 발생한다고 생각합니다.
    cout << "가장 큰 정수는"<< largest << endl;
    return 0;
}