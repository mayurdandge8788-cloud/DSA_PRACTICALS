#include <iostream>
using namespace std;

int main()
{
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

  
    int last = arr[n - 1];

    
    arr[n - 1] = key;

    int i = 0;

  
    while (arr[i] != key)
        i++;

 
    arr[n - 1] = last;

    
    if (i < n - 1 || arr[n - 1] == key)
        cout << "Element found at index " << i << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}