#include <iostream>
using namespace std;
int arr[10];
int Size=sizeof (arr)/sizeof(arr[0]);
int front=0,rear=-1,totalItem=0;
bool isFull(){
    if(totalItem==Size)
        return true;
    return false;
}
bool isEmpty(){
    if(totalItem==0)
        return true;
    return false;
}
void enQueue(int val){
    if(isFull()){
        cout<<"Sorry! the Queue is Full.\n";
        return;
    }
    rear=(rear+1)%Size;
    arr[rear]=val;
    totalItem++;
    cout<<"Insert Element-> "<<val<<"\n";
}
void deQueue(){
    if(isEmpty()){
        cout<<"Sorry! the Queue is Empty.\n";
        return;
    }
    int frontVal=arr[front];
    arr[front]=0;
    front=(front+1)%Size;
    totalItem--;
    cout<<"Delete Element-> "<<frontVal<<"\n";
}
void ShowAll(){
    if(isEmpty()){
        cout<<"Array is empty\n";
        return;
    }
    if(rear>=front){
        cout<<"\nFront-> "<<front<<"\n";
        cout<<"Circular Queue Element: ";
        for (int j = front; j <=rear; j++)
            cout<<arr[j]<<" ";
        cout<<"\nRear-> "<<rear;
    } else{
        cout<<"\nFront-> "<<front<<"\n";
        cout<<"Circular Queue Element: ";
        for (int k = front; k < Size; k++)
            cout<<arr[k]<<" ";
        for (int l = 0; l <=rear; l++)
            cout<<arr[l]<<" ";
        cout<<"\nRear-> "<<rear;
    }
    cout<<"\n";
}
int main() {
    bool choice = true;
    while (choice) {
        cout << "\n.....Circular Queue.....\n";
        cout << "Enqueue Element Press-1\n";
        cout << "Dequeue Element Press-2\n";
        cout << "ShowAll Press-3\n";
        cout << "Exit Than Press-4\n";
        int Case, val;
        cin >> Case;
        switch (Case) {
            case 1:
                cout << "Enter Value: ";
                cin >> val;
                enQueue(val);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                ShowAll();
                break;
            case 4:
                choice = false;
            default:
                cout << "Please Try Again! Press Enter (1-4)\n\n";
        }
    }
}