#include <iostream>
using namespace std;

int main() {
    int cq[100];
    int front = -1, rear = -1, maxSize, choice;

    cout << "Enter size of Circular Queue: ";
    cin >> maxSize;

    do {
        cout << "\n----- CIRCULAR QUEUE MENU -----\n";
        cout << "1. ENQUEUE\n";
        cout << "2. DEQUEUE\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. DISPLAY\n";
        cout << "6. PEEK\n";
        cout << "7. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {   // ENQUEUE
            if ((front == 0 && rear == maxSize - 1) || (rear + 1) % maxSize == front) {
                cout << "Circular Queue is FULL\n";
            } else {
                int val;
                cout << "Enter value: ";
                cin >> val;

                if (front == -1) {   // first element
                    front = rear = 0;
                } else {
                    rear = (rear + 1) % maxSize;
                }

                cq[rear] = val;
                cout << "Inserted\n";
            }
            break;
        }

        case 2: {   // DEQUEUE
            if (front == -1) {
                cout << "Circular Queue is EMPTY\n";
            } else {
                cout << "Deleted: " << cq[front] << endl;

                if (front == rear) {
                    // last element removed
                    front = rear = -1;
                } else {
                    front = (front + 1) % maxSize;
                }
            }
            break;
        }

        case 3: {   // isEmpty
            if (front == -1)
                cout << "Queue is EMPTY\n";
            else
                cout << "Queue is NOT empty\n";
            break;
        }

        case 4: {   // isFull
            if ((front == 0 && rear == maxSize - 1) || (rear + 1) % maxSize == front)
                cout << "Queue is FULL\n";
            else
                cout << "Queue is NOT full\n";
            break;
        }

        case 5: {   // DISPLAY
            if (front == -1) {
                cout << "Circular Queue is empty\n";
            } else {
                cout << "Circular Queue elements: ";
                int i = front;
                while (true) {
                    cout << cq[i] << " ";
                    if (i == rear) break;
                    i = (i + 1) % maxSize;
                }
                cout << endl;
            }
            break;
        }

        case 6: {   // PEEK
            if (front == -1)
                cout << "Queue empty\n";
            else
                cout << "Front element: " << cq[front] << endl;
            break;
        }

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
