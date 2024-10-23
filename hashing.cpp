#include<bits/stdc++.h>
using namespace std;

/*
    Number hashing
*/
void count_number_frequency(int hash_array[], int arr[], int n) {
    for(int i=0; i<n; i++) {
        hash_array[arr[i]] += 1;
    }
}


void count_character_frequency(int hash_array[], string s) {
    for(int i=0; i<s.length(); i++) {
        hash_array[s[i]] += 1;
    }
}

// count number frequency using map STL library
void count_number_frequency_map(unordered_map<int, int>& mpp, int arr[], int n) {
    for(int i=0; i<n; i++) {
        mpp[arr[i]]++;
    }
}

void count_character_frequency_map(unordered_map<char, int>& mpp, string s) {
    for(int i=0; i<s.length(); i++) {
        mpp[s[i]]++;
    }
}


int main() {
    // For Number hashing
    /*
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int hash_array[13] = {0};

    // Calling the function
    count_number_frequency(hash_array, arr, n);

    for(int i=0; i<13; i++) {
        cout << hash_array[i] << " ";
    }
    cout << endl;

    int q;
    cin >> q;
    while(q--) {
        int number;
        cin >> number;
        cout << hash_array[number] << endl;
    }
    */

    // For String hashing
    /*
    string s;
    cin >> s;

    int hash_array[256] = {0};

    count_character_frequency(hash_array, s);
    
    int q;
    cin >> q;
    while(q--) {
        char ch;
        cin >> ch;
        cout << hash_array[ch] << endl;
    }
    */

    // counting number frequency of array using map
    /*
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> mpp;

    // Calling the function
    count_number_frequency_map(mpp, arr, n);

    for(auto it: mpp) {
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    cin >> q;
    while(q--) {
        int number;
        cin >> number;
        cout << mpp[number] << endl;
    }
    cout << endl;
    */

    // Counting string character frequency using map
    
    /*
    string s;
    cin >> s;

    unordered_map<char, int> mpp;
    count_character_frequency_map(mpp, s);

    for(auto it: mpp) {
        cout << it.first << "->" << it.second << endl;
    }
    */


    // Finding the lowest and the highest frequency element
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> mpp;

    // Calling the function
    count_number_frequency_map(mpp, arr, n);

    for(auto it: mpp) {
        cout << it.first << "->" << it.second << endl;
    }

    int max = 0;
    int min = INT_MAX;

    pair<int, int> max_pair;
    pair<int, int> min_pair;


    for(auto it: mpp) {
        if(it.second > max){
            max = it.second;
            max_pair = make_pair(it.first, it.second);
        }
        if (it.second < min) {
            min = it.second;
            min_pair = make_pair(it.first, it.second);
        }
    }

    cout << "Max Pair key is = " << max_pair.first << " with frequency " << max_pair.second << endl;
    cout << "Min Pair key is = " << min_pair.first << " with frequency " << min_pair.second << endl;

    return 0;
}