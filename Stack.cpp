#include <iostream>
using namespace std;
class Stack {
public:
    int stack[10],top=-1;
    int size=sizeof(stack)/sizeof(stack[0]);
    bool isFull(){
        if(top==size-1){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }
    void Push(int value){
        if(isFull()){
            cout <<"\nQueue is Full!!\n";
            return;
        }
        top++;
        stack[top]=value;
        cout<<"\nInsert -> "<<value<<"\n";
    }
    void Pop(){
        if(isEmpty()){
            cout<<"\nQueue is Empty!!\n";
            return;
        }
        int val=stack[top];
        cout <<"\nDeleted -> "<<val<<"\n";
        top--;

    }
    int Peek(){
        if(isEmpty()){
            cout<<"\nQueue is Empty!!\n";
            return 1;
        }
        return stack[top];
    }

    void showStack()
    {
        if(isEmpty()) {
            cout<<"\nStack is Empty!!\n";
            return;
        }
        cout<<"Stack Element: ";
        for(int i=0;i<=top;i++) {
            cout<<stack[i]<<" ";
        }
        cout<<"\n\n";
    }
};
int main() {
    Stack Obj;
    bool choice=true;
    while(choice){
        cout<<"\n.....Stack.....\n";
        cout<<"Push Element Press-1\n";
        cout<<"Pop Element Press-2\n";
        cout<<"Peek Element Press-3\n";
        cout<<"ShowAll Press-4\n";
        cout<<"Exit Than Press-5\n";
        int Case,val;
        cin>>Case;
        switch (Case) {
            case 1:
                cout<<"Enter Value: ";
                cin>>val;
                Obj.Push(val);
                break;
            case 2:
                Obj.Pop();
                break;
            case 3:
               cout<<"\nTop Element Stack -> "<<Obj.Peek()<<"\n";
                break;
            case 4:
                Obj.showStack();
                break;
            case 5:
                choice= false;
            default:
                cout<<"Please Try Again! Press Enter (1-5)\n\n";
        }
    }
}