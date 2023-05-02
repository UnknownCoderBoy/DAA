#include <bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int key, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key == arr[mid]) 
			return mid;
        else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int binarysearchR(int arr[], int key, int low, int high) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (key == arr[mid]) 
			return mid;
        else if (key < arr[mid]) {
            return binarysearchR(arr, key, low, mid - 1);
        } else {
            return binarysearchR(arr, key, mid + 1, high);
        }
    }
    return -1;
}

int main() {
    int num;
    cout << "Enter the Number of Elements: ";
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++) {
        cin>> arr[i];
    }
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "\nSorted Array is: \n";
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    int key;
    cout << "\n\nEnter the Key Element: ";
    cin >> key;
    cout << "\nIterative Binary Search Element Found At " << binarysearch(arr, key, 0, num - 1);
    cout << "\nRecursive Binary Search Element Found At " << binarysearchR(arr, key, 0, num - 1);
}
