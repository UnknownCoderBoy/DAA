#include <bits/stdc++.h>
using namespace std;

int getrandom(int low, int high){
	return low + rand()%(high - low + 1);
}


int binarysearch(int arr[], int key, int low, int high) {
    if (low <= high) {
        int mid = getrandom(low, high);
        if (key == arr[mid]) 
			return mid;
        else if (key < arr[mid]) {
            return binarysearch(arr, key, low, mid - 1);
        } else {
            return binarysearch(arr, key, mid + 1, high);
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
    cout << "\nBinary Search Element Found At " << binarysearch(arr, key, 0, num - 1);
}
