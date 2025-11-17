#include <iostream>
using namespace std;

int main() {
    int queue[100];
    int front = -1, rear = -1, maxSize, ch;

    cout << "Enter size of Queue: ";
    cin >> maxSize;

    do {
        cout << "\n----- QUEUE MENU -----\n";
        cout << "1. ENQUEUE\n";
        cout << "2. DEQUEUE\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. DISPLAY\n";
        cout << "6. PEEK\n";
        cout << "7. EXIT\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {

        case 1: {   
            if (rear == maxSize - 1) {
                cout << "Queue is FULL\n";
            } else {
                int x;
                cout << "Enter value: ";
                cin >> x;

                if (front == -1) front = 0; 
                rear++;
                queue[rear] = x;

                cout << "Inserted\n";
            }
            break;
        }

        case 2:     
            if (front == -1 || front > rear) {
                cout << "Queue is EMPTY\n";
                front = rear = -1;
            } else {
                cout << "Deleted: " << queue[front] << endl;
                front++;
            }
            break;

        case 3:     
            if (front == -1 || front > rear)
                cout << "Queue is EMPTY\n";
            else
                cout << "Queue is NOT empty\n";
            break;

        case 4:    
            if (rear == maxSize - 1)
                cout << "Queue is FULL\n";
            else
                cout << "Queue is NOT full\n";
            break;

        case 5:    
            if (front == -1 || front > rear) {
                cout << "Queue empty\n";
            } else {
                cout << "Queue elements: ";
                for (int i = front; i <= rear; i++)
                    cout << queue[i] << " ";
                cout << endl;
            }
            break;

        case 6:   
            if (front == -1 || front > rear)
                cout << "Queue is empty\n";
            else
                cout << "Front element: " << queue[front] << endl;
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
