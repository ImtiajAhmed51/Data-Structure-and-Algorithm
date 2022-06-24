#include<iostream>
using namespace std;
void matrixMultiplication(int firstMat[][10],int secondMat[][10],int rows1,int rows2,int col1,int col2 ){
    int multiplication[10][10];
    for(int i = 0; i < rows1; ++i)
        for(int j = 0; j < col2; ++j)
            multiplication[i][j]=0;
    for(int i = 0; i < rows1; i++)
        for(int j = 0; j < col2; j++)
            for(int k = 0; k < col1; k++)
                multiplication[i][j] += firstMat[i][k] * secondMat[k][j];
    cout<<"\nMatrix Multiplication\n";
    for(int i = 0; i < rows1; ++i)
        for(int j = 0; j < col2; ++j){
            cout << " " << multiplication[i][j];
            if(j == col2-1)
                cout<<"\n";
        }
}
int main(){
    int firstMat[10][10],secondMat[10][10],rows1,rows2,col1,col2;
    cout<<"Enter first matrix rows: ";
    cin>>rows1;
    cout<<"Enter first matrix columns: ";
    cin>>col1;
    cout<<"Enter second matrix rows: ";
    cin>>rows2;
    cout<<"Enter second matrix columns: ";
    cin>>col2;
    while (col1!=rows2){
        cout<<"First Matrix columns and Second Matrix Rows Not Same.";
    }
    cout <<"\nEnter elements of matrix 1\n\n";
    for(int i = 0; i < rows1; i++)
        for(int j = 0; j < col1; j++)
        {
            cout << "Enter element First Matrix" << i + 1 << j + 1 << " : ";
            cin >> firstMat[i][j];
        }
    cout <<"\nEnter elements of matrix 2\n\n";
    for(int i = 0; i < rows2; i++)
        for(int j = 0; j < col2; j++)
        {
            cout << "Enter element Second Matrix" << i + 1 << j + 1 << " : ";
            cin >> secondMat[i][j];
        }
    matrixMultiplication(firstMat,secondMat,rows1,rows2,col1,col2)
      }
