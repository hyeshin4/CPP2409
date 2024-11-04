#include <iostream>
#include <string>
#include "user.h"
using namespace std;

// 맵의 크기
const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
void displayMap(int map[][mapX], int user_x, int user_y);
// 맵을 print하는 함수
bool checkXY(int x, int y);
// player가 맵 밖에 있는지 확인하는 함수
bool checkGoal(int map[][mapX], int x, int y);
// 목적지에 도달했는지 확인하는 함수
void handlePositionEffect(int map[][mapX], User &player, int x, int y);
// 아이템-적과 상호작용하는 함수
void movePlayer(int map[][mapX], User &player, int &x, int &y, int dx, int dy);
//사용자를 이동하는 함수

// 메인 함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    int map[mapY][mapX] = { 
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2} 
    };

	// 유저의 위치를 저장할 변수, hp 변수
    int user_x = 0, user_y = 0;
    User player;

	// 게임 시작 
    while (true) { // 사용자에게 계속 입력받기 위해 무한 루프
        // 게임 개선시키기 : 체력 기능 도입
        if (player.GetHP() <= 0) {
            cout << "HP가 0 이하가 되었습니다.\n게임을 종료합니다." << endl;
            break;
        }
		// 사용자의 입력을 저장할 변수
        string user_input;
        // 사용자의 현재 상태와 입력 요청
        cout << "현재 HP: " << player.GetHP() << " 명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
        cin >> user_input;

        // 위치 입력에 따른 상호작용
        if (user_input == "상") movePlayer(map, player, user_x, user_y, 0, -1);
        else if (user_input == "하") movePlayer(map, player, user_x, user_y, 0, 1);
        else if (user_input == "좌") movePlayer(map, player, user_x, user_y, -1, 0);
        else if (user_input == "우") movePlayer(map, player, user_x, user_y, 1, 0);
        // 지도 보여주기 함수 호출
        else if (user_input == "지도") displayMap(map, user_x, user_y);
        
        // 종료를 입력한 경우
        else if (user_input == "종료") {
            cout << "종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다." << endl;
        }

        // 목적지에 도달한 경우
        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!\n게임을 종료합니다." << endl;
            break;
        }
    }
    return 0;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |"; // 양 옆 1칸 공백
            } else {
                switch (map[i][j]) {
                    case 0: cout << "      |"; break; // 6칸 공백
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break; // 양 옆 2칸 공백
                    case 3: cout << " 포션 |"; break; // 양 옆 1칸 공백
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << endl << " -------------------------------- " << endl;
    }
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int x, int y) {
    return (x >= 0 && x < mapX && y >= 0 && y < mapY);
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int x, int y) {
    return (map[y][x] == 4); // 목적지 도착하면 true 반환
}

// 아이템, 적, 포션을 만났을 때
void handlePositionEffect(int map[][mapX], User &player, int x, int y) {
    switch (map[y][x]) {
        case 1: //아이템을 만난 경우
            cout << "아이템이 있습니다." << endl; 
            break;
        case 2: //적을 만난 경우
            cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
            player.DecreaseHP(2);
            //hp -= 2; 
            break;
        case 3: //포션을 만난 경우
            cout << "포션이 있습니다. HP가 2 증가합니다." << endl;
            player.IncreaseHP(2);
            //hp += 2;
            break;
        default: //이외의 경우
            break;
    }
}

//player 이동 함수 (기존 코드의 반복되는 부분을 함수화 했습니다)
void movePlayer(int map[][mapX], User &player, int &x, int &y, int dx, int dy) {
    // 이동한 위치
    int newX = x + dx;
    int newY = y + dy;
    if (checkXY(newX, newY)) {
        x = newX;
        y = newY;
        player.DecreaseHP(1);
        //hp -= 1; // 체력 -1
        displayMap(map, x, y); //맵에 이동한 위치 표기
        handlePositionEffect(map, player, x, y); // 아이템-적과 만났을 때 상호작용
    } else {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl; //맵을 벗어나는 입력을 받은 경우
    }
}
