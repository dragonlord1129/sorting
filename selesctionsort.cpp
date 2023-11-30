#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int c;
    c=b;
    b=a;
    a=c;
}

int main(){
    int array[10];
    int i;
    for(i=0; i<5;i++){
        cin >> array[i];
    }
    
    //selection sort
    int current_min;
    for(i=0; i<5; i++){
        current_min = i;
        for(int k=i+1; k<5; k++){
            if (array[k] < array[current_min]){
                current_min = k;
            }
        }
        if (current_min != i){
            swap(array[i], array[current_min]);
        }
    }
    for(i=0; i<5;i++){
        cout<< array[i]<<" ";
    }
}