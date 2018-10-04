#include <iostream>

using namespace std;
int main(){
    int size;
    cout << "Enter array size: "; 
    cin >> size;

    int *arr = new int[size];

    for(int i = 0; i < size; i++){
        cout << "Enter element of index " << i << ": ";
        int element;
        cin >> element;
        arr[i] = element; 
    }

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    
    cout << "\n";

    delete [] arr;
}
