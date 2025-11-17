#include <iostream>
#include <string>
using namespace std;

int main() {
    char stackArr[100];
    int top = -1;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        top++;
        stackArr[top] = s[i];
    }

    cout << "Reversed string: ";
    while (top != -1) {
        cout << stackArr[top];
        top--;
    }

    cout << endl;
    return 0;
}



// Q 3 is in doubt
// Q 4 is in doubt