#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width, height;
    int CalcArea()
    {
        return width * height;
    }
};

int main()
{
    Rectangle obj;
    Rectangle obj2;
    obj.width = 3;
    obj.height = 4;
    obj2.width = 10;
    obj2.height = 10;
    int area = obj.CalcArea();
    int area2 = obj2.CalcArea();
    cout << "첫 번째 사각형의 넒이: " << area << endl;
    cout << "두 번째 사각형의 넒이: " << area2 << endl;
    return 0;
}