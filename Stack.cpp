#include <iostream>
using namespace std;
class stack{
public:
    int arr[10];
    int size=sizeof (arr)/sizeof(arr[0]);
    int counter=-1;

    void push(int val){
        if (counter<size-1){
            counter++;
            arr[counter]=val;
            cout<<"Push Item: "<<arr[counter]<<"\n";
        } else{
            cout<<"Stack Full\n";
        }
    }
    void pop(){
        if(counter>=0){
            cout<<arr[counter]<<" Delete Successfully\n";
            counter--;
        } else{
            cout<<"Empty Stack!\n";
        }
    }
    int peek(){
        if(counter>=0){
            return arr[counter];
        }
        cout<<"Empty Stack\n";
    }
    void showall(){
        for (int i = 0; i <=counter; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};
int main() {
    stack Obj;
    bool choice=true;
    while(choice){
        cout<<"Push Element Press-1\n";
        cout<<"Pop Element Press-2\n";
        cout<<"Peek Element Press-3\n";
        cout<<"ShowAll Press-4\n";
        cout<<"Exit Than Press-5\n\n";
        int Case,val;
        cin>>Case;
        switch (Case) {
            case 1:
                cout<<"Enter Value: ";
                cin>>val;
                Obj.push(val);
                break;
            case 2:
                Obj.pop();
                break;
            case 3:
                Obj.peek();
                break;
            case 4:
                Obj.showall();
                break;
            case 5:
                choice= false;
            default:
                cout<<"Please Try Again! Press Enter (1-5)\n\n";
        }
    }

}