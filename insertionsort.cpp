#include<iostream>
using namespace std;



int main(){
    
    int array[10];
    int i;
    for(i=0; i<5;i++){
        cin >> array[i];
    }
    cout << endl;
    int temp;

// insertion sort
    for(i=1; i<5; i++){
        int j=i;
        temp = array[j];
        while (j>0 && temp < array[j-1]){
            array[j]=array[j-1];
            j--;
        }
        array[j]= temp;
    }
    for(i=0; i<5;i++){
        cout<< array[i]<<" ";
    }
}