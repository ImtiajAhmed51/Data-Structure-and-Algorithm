#include <iostream>
using namespace std;
class Queue {
public:
    int queue[10],front=-1,rear=-1;
    int size=sizeof(queue)/sizeof(queue[0]);
    bool isFull(){
        if(front==0&&rear==size-1){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(front==-1)
            return true;
        else
            return false;
    }
    void enQueue(int value){
        if(isFull()){
            cout <<"\nQueue is Full!!\n";
            return;
        }
        front = 0;
        rear++;
        queue[rear]=value;
        cout<<"\nInsert -> "<<value<<"\n";
    }
    void deQueue(){
        int value;
        if(isEmpty()){
            cout<<"\nQueue is Empty!!\n";
            return;
        }
        value=queue[front];
        if(front>=rear){
            front=-1;
            rear=-1;
        }
        else {
            front++;
        }
        cout <<"\nDeleted -> "<<value<<"\n";

    }
    void ShowQueue()
    {
        if(isEmpty()) {
            cout <<"\nQueue is Empty!!\n";
            return;
        }
        cout <<"\nFront = "<< front;
        cout << "\nQueue elements : ";
        for(int i=front;i<=rear;i++)
            cout<<queue[i]<<" ";
        cout<<"\nRear = "<<rear<<"\n";
    }
};
int main()
{
    Queue Obj;
    bool choice=true;
    while(choice){
        cout<<"\nEnqueue Element Press-1\n";
        cout<<"Dequeue Element Press-2\n";
        cout<<"ShowAll Press-3\n";
        cout<<"Exit Than Press-4\n\n";
        int Case,val;
        cin>>Case;
        switch (Case) {
            case 1:
                cout<<"Enter Value: ";
                cin>>val;
                Obj.enQueue(val);
                break;
            case 2:
                Obj.deQueue();
                break;
            case 3:
                Obj.ShowQueue();
                break;
            case 4:
                choice= false;
                break;
            default:
                cout<<"Please Try Again! Press Enter (1-4)\n\n";
        }
    }
    return 0;
}