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

void array_left_rotate_d(vector<int> arr, int d) {
    int n = arr.size();
    d = d%n;
    
    // creating a temporary array to store the first d variables
    vector<int> temp;
    for(int i=0; i<d; i++) {
        temp.push_back(arr[i]);
    }

    // Now shifting the elements in the original array
    for(int i=d; i<n; i++) {
        arr[i-d] = arr[i];
    }
    // Now inserting the elements in temp array to the end of the array
    for(int i=n-d; i<n; i++) {
        arr[i] = temp[i-(n-d)];
    }
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void reverse_array(vector<int>& arr, int start, int end)
{
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void array_left_rotate_optimal(vector<int> arr, int d, int n) {
    reverse_array(arr, 0, d-1);
    reverse_array(arr, d, n-1);
    reverse_array(arr, 0, n-1);

    for(auto it : arr) {
        cout << it << " ";
    }
}

void array_right_rotate_brute(vector<int> arr, int d, int n) {
    if (n == 1 || n == 0) {
        return;
    }
    d = d%n;
    if(d>n) {
        return;
    }
    vector<int> temp;
    for(int i=n-d; i<n; i++) {
        temp.push_back(arr[i]);
    }
    for(int i=n-d-1; i>=0; i--) {
        arr[i+d] = arr[i];
    }
    for(int i=0; i<d; i++) {
        arr[i] = temp[i];
    }

    // printing the array
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void array_right_rotate_optimal(vector<int> arr, int d, int n) {
    reverse_array(arr, n-d, n-1);
    reverse_array(arr, 0, d);
    reverse_array(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void array_move_zeros_end_brute(vector<int> arr, int n) {
    if (n == 0 || n == 1) {
        return;
    }
    vector<int> temp;
    for(int i=0; i<n; i++) {
        if(arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }
    int nz = temp.size();
    for(int i=0; i<nz; i++) {
        arr[i] = temp[i];
    }
    for(int i=nz; i<n; i++) {
        arr[i] = 0;
    }

    // printing the new array
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void array_move_zeros_end_optimal(vector<int> arr, int n) {
    int j = -1;
    for(int i=0; i<n; i++) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }
    if(j == -1) {
        return;
    }
    for(int i=j+1; i<n; i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    // printing
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

int linear_search(vector<int> arr, int n, int x) {
    for(int i=0; i<n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
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
    // array_left_rotate(arr);
    // for(auto it: arr) {
    //     cout << it << " ";
    // }

    array_left_rotate_d(arr, 3);
    cout << endl;
    array_left_rotate_optimal(arr, 3, arr.size());
    cout << endl;
    array_right_rotate_brute(arr, 3, arr.size());
    cout << endl;
    array_right_rotate_optimal(arr, 2, arr.size());
    cout << endl;
    cout << "Array after putting the zeros in the end = " << endl;
    array_move_zeros_end_brute(arr, arr.size());
    cout << endl;
    array_move_zeros_end_optimal(arr, arr.size());
    cout << endl;
    int ls_result = linear_search(arr, arr.size(), 15);
    if(ls_result == -1) {
        cout << "Element not present" << endl;
    } else {
        cout << "Elment found at index = " << ls_result << endl;
    }
    return 0;
}