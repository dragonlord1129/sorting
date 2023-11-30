#include<iostream>
#include<vector>
using namespace std;

void countsort(vector<int> &arr){
    int i, k;
    int n= arr.size();
    int b[n];

    k=arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] > k) {
            k = arr[i];
        }
    }

    int count[k+1];
    for(i=0;i<=k;i++){//initializes the elements of count to be zero to be incremented later on
        count[i]=0;
    }
    for(i=0;i<n;i++){//increments the value of the count
        ++count[arr[i]];
    }
    for(i=1;i<=k;i++){//initializes the elements of count to be zero to be incremented later on
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--){//puts the elements to the new array b
        b[--count[arr[i]]]=arr[i];
    }
    for(i=0;i<n;i++){
        arr[i]=b[i];
    }
}

void PrintArray(vector<int> &arr){//prints the array
        cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int> arr;
    char ch = 'y'; // Initialize ch to start the loop

    while (ch != 'n' && ch != 'N') {
        int new_element;
        cout << "Add another element? (y/n): ";
        cin >> ch;
        if (ch != 'n' && ch != 'N') {
            cout << "Enter element: ";
            cin >> new_element;
            arr.push_back(new_element); // Add the new element to the vector
        }
    }

    countsort(arr);
    PrintArray(arr);
    return 0;
}