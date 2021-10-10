#include <iostream>
using namespace std;
class InsertionSort {
public:
    int arr[10];
    int Size=sizeof(arr)/sizeof(arr[0]);
    int j,temp,n=-1;

    bool isEmpty(){
        if(n==-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(n==Size-1){
            return true;
        }
        return false;
    }
    int insert(int val){
        if(isFull()){
            cout<<"\nArray is Full!\n";
            return -1;
        }
        n++;
        arr[n]=val;
        cout<<"\nInsert -> "<<val<<" Successfully\n";
    }
    void insertionSort(){
        if(isEmpty()){
            cout<<"\nInsertion Sorting Unsuccessfully.\n";
            return;
        }
        for (int i = 1; i <=n; i++) {
            temp=arr[i];
            j=i-1;
            while (j>=0&&arr[j]>temp){
                arr[j+1]=arr[j];
                j=j-1;
            }
            arr[j+1]=temp;
        }
        cout<<"\nSorting Successfully!\n";
}
    void showAll(){
        if(isEmpty()){
            cout<<"\nArray Empty!\n";
            return;
        }
        cout<<"Elements: ";
        for (int k = 0; k <=n; k++)
            cout<<arr[k]<<" ";
        cout<<"\n";
    }
};
int main() {
    InsertionSort obj;
    bool choice = true;
    while (choice) {
        int Case, value;
        cout << "\nInsert than Press-1\n";
        cout << "Insertion Sorting than Press-2\n";
        cout << "Show All than Press-3\n";
        cout << "Exit than Press-4\n";
        cin >> Case;
        switch (Case) {
            case 1:
                cout << "Enter Value: ";
                cin >> value;
                obj.insert(value);
                break;
            case 2:
                obj.insertionSort();
                break;
            case 3:
                obj.showAll();
                break;
            case 4:
                choice = false;
                break;
            default:
                cout << "\nPlease Try again!(1-4)\n";
        }
    }
}