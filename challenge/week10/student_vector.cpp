#include <iostream>
#include <vector>
using namespace std;

class Student
{
public:
    int x;
    Student()
    {
        x = 0;
    }
    Student(int x)
    {
        this->x = x;
    }
};

int main()
{
    int a =0;
    int ave;
    vector<Student> score;
    while(a != -1){
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> a;
        if (a!= -1){
            score.push_back(Student(a));
        }
    }
    if (!score.empty()) {
        int sum = 0;
        for (const auto &s : score) {
            sum += s.x;
        }
        double average = static_cast<double>(sum) / score.size();
        cout << "입력한 성적의 평균: " << average << endl;
    } else {
        cout << "입력된 성적이 없습니다." << endl;
    }
    return 0;
}