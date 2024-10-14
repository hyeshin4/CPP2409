#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str) {
    for (char &c : str) {
        if ('A' <= c && c <= 'Z') {
            c += 32; // 대문자 -> 소문자로 변환
        }
    }
    return str;
}

string toUpperStr(string str) {
    for (char &c : str) {
        if ('a' <= c && c <= 'z') {
            c -= 32; // 소문자 -> 대문자로 변환
        }
    }
    return str;
}

int calcHammingDist(string s1, string s2) {
    s1 = toLowerStr(s1); // 대소문자 구분 없이 비교하기 위해 소문자로 변환
    s2 = toLowerStr(s2);

    int count = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            count++;
        }
    }
    
    return count;
}

int main() {
    string s1, s2;

    // 문자열 길이가 같을 때까지 입력을 반복
    while (true) {
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;

        if (s1.length() != s2.length()) {
            cout << "오류: 문자열의 길이가 다릅니다. 다시 입력하세요." << endl;
        } else {
            break; // 길이가 같으면 반복 종료
        }
    }

    // 해밍 거리 계산
    int count = calcHammingDist(s1, s2);
    cout << "해밍 거리는 " << count << endl;

    return 0;
}
