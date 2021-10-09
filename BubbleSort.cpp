#include <iostream>
using namespace std;
class BubbleSort {
public:
    int arr[10];
    int Size=sizeof(arr)/sizeof(arr[0]);
    int temp,n=-1;
    bool isEmpty(){
        if(n==-1)
            return true;
        return false;
    }
    bool isFull(){
        if(n==Size-1)
            return true;
        return false;
    }
    int insert(int val){
        if(isFull()){
            cout<<"\nArray is Full!\n";
            return -1;
        }
        n++;
        arr[n]=val;
        cout<<"\nInsert -> "<<val<<"\n";
    }
    void bubbleSort(){
        if(isEmpty()){
            cout<<"\nSorting Unsuccessfully.\n";
            return;
        }
        for (int i = 0; i <=n; i++)
            for (int j = 0; j <=n-i-1; j++)
                if(arr[j]>arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
        cout<<"\nSorting Successfully!\n";
}
    void showAll(){
        if(isEmpty()){
            cout<<"\nArray is Empty!\n";
            return;
        }
        for (int i = 0; i <=n; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
    }
};
int main() {
    BubbleSort obj;
    bool choice= true;
    while(choice){
         int Case,value;
        cout<<"\nInsert than Press-1\n";
        cout<<"Bubble Sorting than Press-2\n";
        cout<<"Show All than Press-3\n";
        cout<<"Exit than Press-4\n";
        cin>>Case;
        switch (Case) {
            case 1:
                cout<<"Enter Value: ";
                cin>>value;
                obj.insert(value);
                break;
            case 2:
                obj.bubbleSort();
                break;
            case 3:
                obj.showAll();
                break;
            case 4:
                choice= false;
                break;
            default:
                cout<<"\nPlease Try again!(1-4)\n";
        }
    }
}