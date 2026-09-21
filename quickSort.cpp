#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high){

    //CONSIDER LAST ELEMENT AS PIVOT
    int pivot = arr[high];
    int i = low-1;

    //APPLY LOOP FROM LOW TO HIGH-1
    for(int j =low; j<high; j++){
        if(arr[j] <= pivot){
            i ++;
            swap(arr[i], arr[j]);
        }
    }

    //SWAP THE PIVOT TO REACH IT AT THE CORRECT POSITION
    swap(arr[i+1], arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);

        //RECURSIVE CALLS FOR THE NEXT TWO PARTS 
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int a[6] = {10, 7, 8, 9, 1, 5};
    quickSort(a, 0, 5);

    for(int i = 0; i < 6; i++){
    cout << a[i] << " ";
    }
    return 0;
    
}