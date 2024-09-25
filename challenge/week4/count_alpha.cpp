#include <iostream>
using namespace std;

int main(){
    int vowel = 0;
    int consonant = 0;
    cout << "영문자를 입력하고 ctrl+z를 치세요" << endl; // mac에서는 control D 입니다.

    char ch;

    while (cin >> ch) {
        if (ch >= 'a' && ch <= 'z'){
        switch (ch){
        case 'a': case 'e': case 'i': case 'o': case 'u':
            vowel ++;
            break;        
        default:
            consonant++;
        }
        }
        else {
            cout << "입력이 잘못되었습니다" << endl;
        }
    }
    
    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;
    return 0;
}