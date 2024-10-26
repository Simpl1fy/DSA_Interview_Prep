#include<bits/stdc++.h>
using namespace std;

pair<int, int> largest_smallest_element(vector<int> arr) {
    int large=INT_MIN;
    int small=INT_MAX;
    for(auto it : arr) {
        large = max(large, it);
        small = min(small, it);
    }
    pair<int,int> p;
    p.first = large;
    p.second = small;
    return p;
}

pair<int, int> second_largest_smallest(vector<int> arr) {

    if(arr.size() == 0 || arr.size() == 1){
        return {-1, -1};
    }

    int large=INT_MIN, second_large=INT_MIN;
    int small=INT_MAX, second_small=INT_MAX;

    for(auto it : arr) {
        small = min(small, it);
        large = max(large, it);
    }

    for(auto it: arr) {
        if(it > second_large && it != large) {
            second_large = it;
        }
        if (it < second_small && it != small) {
            second_small = it;
        }
    }

    pair<int, int> p = {second_large, second_small};
    return p;
}

bool is_ascending(vector<int> arr) {
    int size = arr.size();
    if (size == 1 || size == 0) {
        return true;
    }

    for(int i=0; i<size; i++) {
        if(arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

// brute force
int remove_duplicates_brute(vector<int>& arr) {
    set<int> st;
    for(auto it : arr) {
        st.insert(it);
    }
    int index = 0;
    for(auto it : st) {
        arr[index] = it;
        index++;
    }
    return (index);
}

// 2 pointer solution
int remove_duplicates_optimum(vector<int>& arr) {
    int i=0;
    for(int j=1; j<arr.size(); j++) {
        if(arr[j] != arr[i]) {
            arr[i+1] = arr[j];
            i++;
        }
    }
    return (i+1);
}


void array_left_rotate(vector<int>& arr) {
    int n = arr[0];
    int size = arr.size();
    for(int i=1; i<size; i++) {
        arr[i-1] = arr[i];
    }
    arr[size-1] = n;
}

int main() {

    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int number;
        cin >> number;
        arr.push_back(number);
    }
    // pair<int, int> result = largest_smallest_element(arr);
    // pair<int, int> result1 = second_largest_smallest(arr);
    // bool result3 = is_ascending(arr);
    // cout << "Largest Element = " << result.first << ", Smallest Element = " << result.second << endl;
    // cout << "Second Largest Element = " << result1.first << ", Second Smallest Element = " << result1.second << endl;
    // cout << "Array Sorted = " << result3 << endl;

    // int result4_index = remove_duplicates_brute(arr);
    // for(int i=0; i<result4_index; i++) {
    //     cout << arr[i] << " ";
    // }
    // int result5_index = remove_duplicates_optimum(arr);
    // for(int i=0; i<result5_index; i++) {
    //     cout << arr[i] << " ";
    // }
    array_left_rotate(arr);
    for(auto it: arr) {
        cout << it << " ";
    }
    return 0;
}