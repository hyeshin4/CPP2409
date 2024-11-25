#include <iostream>
#include <string>
#include "user.h"
#include <vector>
using namespace std;

// 맵의 크기
const int mapX = 5;
const int mapY = 5;

void displayMap(const vector<vector<int>>& map, int magicianX, int magicianY, int warriorX, int warriorY) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            // 같은 위치에 두 플레이어가 있는 경우
            if (i == magicianY && j == magicianX && i == warriorY && j == warriorX) {
                cout << "  U   |"; // 두 플레이어가 같은 위치
            }
            // 마법사 위치
            else if (i == magicianY && j == magicianX) {
                cout << "  M   |";
            }
            // 전사 위치
            else if (i == warriorY && j == warriorX) {
                cout << "  W   |";
            }
            // 맵 기본 상태
            else {
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


// 메인 함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    vector<vector<int>> map = { 
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    Magician magician;
    Warrior warrior;
    vector<User*> players = {&magician, &warrior};

    // 각 플레이어의 위치를 저장
    int magicianX = 0, magicianY = 0;
    int warriorX = 0, warriorY = 0; 
    
    int turn = 0;

	// 게임 시작 
   while (true) {
        User* currentPlayer = players[turn % players.size()];
        int& currentX = (turn % players.size() == 0) ? magicianX : warriorX;
        int& currentY = (turn % players.size() == 0) ? magicianY : warriorY;

        cout << "\n" << currentPlayer->getName() << "의 차례입니다. 명령어를 입력하세요 (상, 하, 좌, 우, 지도, 정보, 종료): ";
        string command;
        cin >> command;

        if (command == "상") {
            if(currentPlayer->move(map, *currentPlayer, currentX, currentY, 0, -1, mapX, mapY)) turn++;
        } else if (command == "하") {
            if(currentPlayer->move(map, *currentPlayer, currentX, currentY, 0, 1, mapX, mapY))turn++;
        } else if (command == "좌") {
            if(currentPlayer->move(map, *currentPlayer,currentX, currentY, -1, 0, mapX, mapY))turn++;
        } else if (command == "우") {
            if(currentPlayer->move(map, *currentPlayer,currentX, currentY, 1, 0, mapX, mapY))turn++;
        } else if (command == "지도") {
            displayMap(map, magicianX, magicianY, warriorX, warriorY); // 지도 출력
        } else if (command == "정보") {
            cout << *currentPlayer; // 정보 출력
        } else if (command == "종료") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
            continue;
        }

        if (currentPlayer->checkGoal(map, currentX, currentY)) {
            cout << "목적지에 도착했습니다! 축하합니다!\n게임을 종료합니다." << endl;
            break;
        }

    }


    return 0;
}
