#include "user.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h> 
#include <stdexcept>

using namespace std;

const int mapX = 5;
const int mapY = 5;

void displayMap(const vector<vector<int>>& map,int choice, int playerX, int playerY) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == playerY && j == playerX) {
                if( choice == 1){
                    cout << "  M   |";
                }
                else{
                    cout << "  W   |";
                }
            } else {
                switch (map[i][j]) {
                    case 0: cout << "      |"; break;
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break;
                    case 3: cout << " 포션 |"; break;
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << "\n--------------------------------\n";
    }
}

int main() {
    try{
    if (chdir("/Users/Kimhyeshin/Documents/CPP2409/project/week14") != 0) {
        throw runtime_error("디렉토리 변경 실패!");
    }

    vector<vector<int>> map;
    string mapFile = "map.txt"; // 맵 파일 이름

    // 맵 파일 로드
    ifstream file(mapFile);
    if (!file.is_open()) {
        throw runtime_error("파일을 열 수 없습니다: " + mapFile);
    }

    vector<int> row;
    int value;
    while (file >> value) {
        row.push_back(value);

        // 각 행의 길이가 5로 고정되어 있다고 가정
        if (row.size() == 5) {
            map.push_back(row);
            row.clear();
        }
    }

    file.close();

    // 파일의 형식이 올바른지 확인 (모든 행이 동일한 길이인지 체크)
    if (!map.empty() && map[0].size() != 5) {
        throw runtime_error("맵 파일의 형식이 올바르지 않습니다.");
    }

    const int mapY = map.size();
    const int mapX = map.empty() ? 0 : map[0].size();

    User* player;
    cout << "직업을 선택하세요 (1: 마법사, 2: 전사): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        player = new Magician();
    } else if (choice == 2) {
        player = new Warrior();
    } else {
        throw invalid_argument("잘못된 선택입니다.");
    }

    int playerX = 0, playerY = 0;
    while (true) {
        if (player->GetHP() <= 0){
            cout << "HP가 0 이하가 되었습니다.\n게임을 종료합니다." << endl;
            break;
        }
        cout << "\n" << player->getName() << "의 차례입니다. 명령어를 입력하세요 (상, 하, 좌, 우, 지도, 정보, 종료): ";
        string command;
        cin >> command;

        if (command == "상") {
            player->move(map, playerX, playerY, 0, -1, mapX, mapY);
        } else if (command == "하") {
            player->move(map, playerX, playerY, 0, 1, mapX, mapY);
        } else if (command == "좌") {
            player->move(map, playerX, playerY, -1, 0, mapX, mapY);
        } else if (command == "우") {
            player->move(map, playerX, playerY, 1, 0, mapX, mapY);
        } else if (command == "지도") {
            displayMap(map, choice, playerX, playerY);
        } else if (command == "정보") {
            cout << *player;
        } else if (command == "종료") {
            cout << "게임을 종료합니다.\n";
            break;
        } else {
            cout << "잘못된 입력입니다. 다시 입력하세요.\n";
        }

        if (player->checkGoal(map, playerX, playerY)) {
            cout << "목적지에 도착했습니다! 축하합니다!\n게임을 종료합니다.\n";
            break;
        }
    }

    delete player;

    }catch (const runtime_error& e) {
        cerr << "런타임 오류 발생: " << e.what() << endl;
        return 1;
    }catch (const invalid_argument& e) {
        cerr << "잘못된 입력: " << e.what() << endl;
        return 1;
    }catch (...) {
        cerr << "알 수 없는 오류가 발생했습니다." << endl;
        return 1;
    }
    return 0;
}
