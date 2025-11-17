// logic kesa hai
// read n
// read array elements

// for i from 0 to n-1:
//     for j from i+1 to n-1:
//         if arr[i] == arr[j]:
//             shift arr[j+1 ... n-1] to left by 1
//             n = n - 1
//             j = j - 1   (because elements shifted)
            
// print array (unique elements)
#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {

                
                
                for (int k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];

                n--;   
                j--;    
            }
        }
    }

    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}
