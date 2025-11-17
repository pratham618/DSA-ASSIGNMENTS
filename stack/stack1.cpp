#include <iostream>
using namespace std;

int main() {
    int stack[100], top = -1, maxSize, ch;

    cout << "Enter size of stack: ";
    cin >> maxSize;

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. DISPLAY\n";
        cout << "6. PEEK\n";
        cout << "7. EXIT\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {

        case 1: { 
            if (top == maxSize - 1) {
                cout << "Stack is FULL\n";
            } else {
                int val;
                cout << "Enter value: ";
                cin >> val;
                top++;
                stack[top] = val;
                cout << "Pushed\n";
            }
            break;
        }

        case 2: 
            if (top == -1) {
                cout << "Stack is EMPTY\n";
            } else {
                cout << "Popped: " << stack[top] << endl;
                top--;
            }
            break;

        case 3: 
            if (top == -1)
                cout << "Stack is empty\n";
            else
                cout << "Stack is not empty\n";
            break;

        case 4: 
            if (top == maxSize - 1)
                cout << "Stack is full\n";
            else
                cout << "Stack is not full\n";
            break;

        case 5: 
            if (top == -1) {
                cout << "Stack empty\n";
            } else {
                cout << "Stack elements: ";
                for (int i = top; i >= 0; i--)
                    cout << stack[i] << " ";
                cout << endl;
            }
            break;

        case 6: 
            if (top == -1)
                cout << "Stack is empty\n";
            else
                cout << "Top element: " << stack[top] << endl;
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (ch != 7);

    return 0;
}

