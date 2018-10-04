#include <iostream>

using namespace std;

int main(){
    int col;
    cout << "Enter the number of colums: ";
    cin >> col;

    int **matrix = new int* [col];
    for (int i = 0; i < col; i ++){
        int row;
        cout << "Enter the size of the row: ";
        cin >> row;
        matrix[i] = new int[row];
        for(int j = 0; j < row; j++){
            cout << "Enter Elements: ";
            cin >> matrix[i][j];
        }
    }
     
    for (int i = 0; i < col; i++){
        for(int j = 0; j < sizeof(*matrix[i]); j++){
            cout << matrix[i][j]<<" ";
        }

        cout << endl;
    }

    for(int i = 0; i < col; i++){
        delete [] matrix[i];
    }
    
    delete[] matrix;



}

