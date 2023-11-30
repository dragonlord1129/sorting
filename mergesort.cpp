#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left +1;
    int n2 = right - mid;

    int i, j, k;
    vector<int> L(n1), R(n2);
    for(i = 0; i<n1; i++){
        L[i]= arr[left +i];
    }
    for(j=0; j<n2; j++){
        R[j]= arr[mid+1+j];
    }
    i =0; j=0; k = left;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        } 
        k++;
    }
    while(i<n1){
        arr[k]= L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]= R[j];
        j++;
        k++;
    }    
}

void mergesort(vector<int>& arr, int left, int right){
    int mid;
    if (left < right){
        mid = left +(right - left)/2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

int main(){
    vector<int> array;
    char ch = 'y'; // Initialize ch to start the loop
    array = {13, 11, 9, 8 , 7, 5, 5, 4, 3, 2, 1};
    mergesort(array, 0, array.size() - 1); // the mergesort needs these parameters (array, lower bound of the array, upper bound of the array)

    cout << "Sorted array: ";
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

