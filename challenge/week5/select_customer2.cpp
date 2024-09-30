#include <iostream>
#include <string>
using namespace std;

int main()
{          
    const int maxPeople =5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i =0; i <maxPeople; i++){
        cout << "사람 " << i+1 <<"의 이름: ";
        cin >> names[i];
        cout << "사람 " << i+1 <<"의 나이: ";
        cin >> ages[i];
    }
    int max= 0;
    string oldPeople[maxPeople];
    string maxName;
    int min= ages[0];
    string youngPeople[maxPeople];
    string minName;
    for (int i = 0; i < maxPeople; i++){
        if (ages[i] >= max){
            max = ages[i];
            maxName = names[i];
        }
        if (ages[i] <= min){
            min = ages[i];
            minName = names[i];
    }
        if (ages[i] == max)
            oldPeople[i] += ages[i];
        if (ages[i] == min)
            youngPeople[i] += ages[i];

    }

    int choice;
    do {
        cout <<"메뉴를 선택하세요 (1. 나이가 가장 많은 사람 , 2. 나이가 가장 적은 사람 , 3. 종료): ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << maxName<< " (" << max << "세) "<< endl;
                break;
            case 2:
                cout << minName<< " (" << min << "세) "<< endl;
                break;
            case 3:
                cout <<"프로그램 종료" << endl;
                break;
            default:
                cout <<"잘못된 선택" << endl;
                break;
        }
    } while (choice != 3 );


   
}
