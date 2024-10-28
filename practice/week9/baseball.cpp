#include <iostream>
#include <string>
using namespace std;

// 모든 자릿수가 서로 다른지 확인하는 함수
bool checkNumber(int num) {
    int first = num / 100;
    int second = (num / 10) % 10;
    int third = num % 10;

    // 세 자릿수가 모두 다르면 true 반환
    return (first != second) && (first != third) && (second != third);
}

// 스트라이크와 볼 수를 계산하는 함수
void giveHint(int firstNum, int secondNum, int thirdNum, int guessFirst, int guessSecond, int guessThird, int &strike, int &ball) {
    strike = ball = 0;

    // 스트라이크 확인
    if (guessFirst == firstNum) strike++;
    if (guessSecond == secondNum) strike++;
    if (guessThird == thirdNum) strike++;

    // 볼 확인
    if (guessFirst == secondNum || guessFirst == thirdNum) ball++;
    if (guessSecond == firstNum || guessSecond == thirdNum) ball++;
    if (guessThird == firstNum || guessThird == secondNum) ball++;
}

int main() {
    int randomNum, firstNum, secondNum, thirdNum;

    // 랜덤한 3자리 수 생성 (모든 자릿수가 다를 때까지 반복)
    while (true) {        
        randomNum = rand() % 900 + 100;
        
        if (checkNumber(randomNum)) {
            firstNum = randomNum / 100;
            secondNum = (randomNum / 10) % 10;
            thirdNum = randomNum % 10;
            break;
        }
    }

    int turn = 0;
    while (true) {
        cout << turn + 1 << "번째 시도입니다." << endl;

        int userNumber, guessFirst, guessSecond, guessThird;

        // 사용자가 입력한 세자리 수를 입력받고 유효성 검사
        while (true) {
            cout << "세자리 수를 입력해주세요: ";
            cin >> userNumber;

            if (to_string(userNumber).length() != 3 || !checkNumber(userNumber)) {
                cout << "입력된 숫자가 유효하지 않습니다. 3자리의 모든 수가 다른 숫자를 입력하세요." << endl;
                continue;
            }

            guessFirst = userNumber / 100;
            guessSecond = (userNumber / 10) % 10;
            guessThird = userNumber % 10;
            break;
        }

        int strike = 0, ball = 0;
        
        // 정답과 추측 숫자를 비교하여 힌트 제공
        giveHint(firstNum, secondNum, thirdNum, guessFirst, guessSecond, guessThird, strike, ball);

        cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << " 볼 입니다." << endl;

        if (strike == 3) {
            cout << "정답을 맞췄습니다. 축하합니다!" << endl;
            break;
        }

        turn++;
    }

    return 0;
}
