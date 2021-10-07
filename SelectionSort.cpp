#include <iostream>
using namespace std;
class Selection {
public:
    int arr[10],n=-1;

    int Size=sizeof(arr)/sizeof(arr[0]);
    int index,temp;

    bool isFull(){
        if(n==Size-1){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(n==-1){
            return true;
        }
        return false;
    }

    void insert(int val){
        if(isFull()){
            cout<<"\nArray Full\n";
            return;
        }
        n++;
        arr[n]=val;
        cout<<"\nInsert -> "<<val<<" Successfully\n\n";
    }

    void selectionSort(){
        if(n==-1){
            cout<<"\nSorting Unsuccessfully\n";
            return;
        }
        for (int i=0;i<n;i++) {
            index=i;
            for (int j=i+1;j<=n;j++) {
                if(arr[index]>arr[j]){
                    index=j;
                }
            }
            if(index!=i){
                temp=arr[i];
                arr[i]=arr[index];
                arr[index]=temp;
            }
        }
        cout<<"Sorting Successfully\n";
    }
    void showAll(){
        if(isEmpty()){
            cout<<"\nEmpty Array\n";
            return;
        }
        cout<<"\nElement: ";
        for (int i = 0; i <=n; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }


};
int main() {
    Selection Obj;
    bool choice=true;
    while(choice){
        int Case,val;
        cout<<"\nInsert Element Press-1\n";
        cout<<"Selection Sort Press-2\n";
        cout<<"Show All Press-3\n";
        cout<<"Exit Press-4\n";
        cin>>Case;
        switch (Case) {
            case 1:
                cout<<"\nEnter Your Value: ";
                cin>>val;
                Obj.insert(val);
                break;
            case 2:
                Obj.selectionSort();
                break;
            case 3:
                Obj.showAll();
                break;
            case 4:
                choice= false;
                break;
            default:
                cout<<"\nPress Try Again, Choice (1-4)\n";
        }
    }
}