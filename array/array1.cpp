#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, ch;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {

        case 1:
            cout << "Enter size of array: ";
            cin >> n;
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            break;

        case 2:
            cout << "Array elements: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;

        case 3: {
            int pos, val;
            cout << "Enter position to insert: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;

        
            for (int i = n; i > pos; i--)
                arr[i] = arr[i - 1];

            arr[pos] = val;
            n++;
            break;
        }

        case 4: {
            int pos;
            cout << "Enter position to delete: ";
            cin >> pos;

          
            for (int i = pos; i < n - 1; i++)
                arr[i] = arr[i + 1];

            n--;
            break;
        }

        case 5: {
            int value, found = -1;
            cout << "Enter value to search: ";
            cin >> value;

            for (int i = 0; i < n; i++) {
                if (arr[i] == value) {
                    found = i;
                    break;
                }
            }

            if (found != -1)
                cout << "Found at index " << found << endl;
            else
                cout << "Not found\n";

            break;
        }

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (ch != 6);

    return 0;
}
