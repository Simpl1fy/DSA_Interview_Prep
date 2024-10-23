#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int i = 0;
    int l = s.size() - 1;

    while (i < l) {
        if (s[i] != s[l]) {
            return false;
        }
        i++; l--;
    }
    return true;
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

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower); 

        if(recursion_palindrome(0, s.size()-1, s)) {
            cout << "Is Palindrome\n";
        } else {
            cout << "Is not palindrome\n";
        }
    }
    return 0;
}