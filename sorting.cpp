#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int min_i = i;
        for(int j=i; j<n; j++) {
            if (arr[j] < arr[min_i]) min_i = j;
        }
        swap(arr[min_i], arr[i]);
    }
}

void bubble_sort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int flag = 0;
        for(int j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
        if (flag == 1) {
            break;
        }
    }
}


void insertion_sort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int j=i;
        while (j>0 && arr[j-1] > arr[j]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

void recursive_bubble_sort(vector<int> &arr, int n) {
    if (n == 1) {
        return;
    }
    for(int j=0; j<=n-1; j++) {
        if (arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }
    recursive_bubble_sort(arr, n-1);
}

void recursive_insertion_sort(vector<int> &arr, int i, int n) {
    if(i == n) {
        return;
    }
    int j=i;
    while (j > 0 && arr[j-1]>arr[j]) {
        swap(arr[j-1], arr[j]);
        j--;
    }
    recursive_insertion_sort(arr, i+1, n);
}

int main() {
    // int n;
    // cin >> n;
    // int arr[n];
    // for(int i=0; i<n; i++) {
    //     cin >> arr[i];
    // }   
    // // selection_sort(arr, n);
    // // bubble_sort(arr, n);
    // insertion_sort(arr, n);
    // for(int i=0; i<n; i++) {
    //     cout << arr[i] << " ";
    // }


    vector<int> arr;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int number;
        cin >> number;
        arr.push_back(number);
    }
    // recursive_bubble_sort(arr, n-1);
    recursive_insertion_sort(arr, 1, n);
    for(auto it: arr) {
        cout << it << " ";
    }
    return 0;
}