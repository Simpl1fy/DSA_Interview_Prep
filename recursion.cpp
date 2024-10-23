#include <bits/stdc++.h>
using namespace std;

void recursion_reverse(int i, int arr[], int size) {
    if (i >= size/2) {
        return;
    }
    swap(arr[i], arr[size-i-1]);
    recursion_reverse(i+1, arr, size);
}

bool recursion_palindrome(int i, int l, string s) {
    if (i >= l) {
        return true;
    }
    if (s[i] != s[l]) {
        return false;
    }
    return recursion_palindrome(i+1, l-1, s);
}

int fib(int x) {
    if((x == 1) || (x == 0)) {
        return(x);
    }
    return (fib(x-1) + fib(x-2));
}

int main() {
    int t;
    cin >> t;


    /*
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    recursion_reverse(0, arr, n);

    for (int i=0; i<n; i++) {
        cout <<  arr[i] << " ";
    }
    */

    while(t--) {
        int n, i=0;
        cin >> n;
        while (i < n) {
            cout << fib(i) << " ";
            i++;
        }
        cout << endl;
    }
    return 0;
}