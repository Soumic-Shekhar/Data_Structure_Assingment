#include <iostream>

using namespace std;

int main(){
    int row;
    int col;

    cout << "Enter number of rows: ";
    cin >> row;

    cout << "Enter number of col: ";
    cin >> col;

    char **arr = new char* [row];

    for(int i = 0; i < row; i++){
        arr[i] = new char [col];
        for(int j = 0; j < col; j++){
            cout << "Enter element for index "<< j << " :";
            cin >> arr[i][j]; 
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j]; 
        }

        cout << endl;
    }

    for(int i = 0; i < row; i++){
        delete [] arr[i];
    }
    
    delete[] arr;

}
