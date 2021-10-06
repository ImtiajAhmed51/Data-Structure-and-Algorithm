#include <iostream>
using namespace std;
class Insertion{
public:
    int arr[10]={0};
    int size=sizeof(arr)/sizeof(arr[0]);
    bool checkFull(int array[]){
        for(int j=0;j<size;j++){
            if(array[j]==0)
                return false;
        }
        return true;
    }
    void firstPosInsert(int val){
        if(checkFull(arr)){
            cout<<"\nArray is full\n";
            return;
        }
        int index=-1;
        for(int i=0;i<size;i++){
            if(arr[i]==0){
                index=i;
                break;
            }
        }
        for(int i=index;i>0;i--)
            arr[i]=arr[i-1];
        arr[0]=val;
    }
    void anyPosInsert(int val,int pos){
        int counter=0;
        if(checkFull(arr)){
            cout<<"\nArray is full\n";
            return;
        }
        else if(arr[pos]==0)
            arr[pos]=val;
        else{
            for(int i=0;i<pos;i++){
                if(arr[i]==0){
                    for(int j=pos;j>=0;j--){
                        if(arr[j]==0){
                            for(int k=j;k<pos;k++)
                                arr[k] = arr[k+1];
                            counter++;
                            break;
                        }
                    }
                    break;
                }
            }
            if(counter==0){
                for (int i=pos;i<size;i++){
                    if(arr[i]==0){
                        for(int j=i;j>pos;j--)
                            arr[j]=arr[j-1];
                        break;
                    }
                }
            }
            arr[pos]=val;
        }
    }
    void lastPosInsert(int val){
        if(checkFull(arr)){
            cout<<"\nArray is full\n";
            return;
        }
        int index=-1;
        for(int i=size-1;i>=0;i--){
            if(arr[i]==0){
                index=i;
                break;
            }
        }
        for(int i=index;i<size;i++)
            arr[i]=arr[i+1];
        arr[size-1]=val;
    }
    void deletion(int val){
        int counter=0;
        for(int i=0;i<size;i++){
            if(arr[i]==val){
                arr[i]=0;
                counter++;
                break;
            }
        }
        if(counter==0)
            cout<<"\nNot Found\n";
    }
    void ShowAll(){
        for(int i = 0; i<size; i++)
            if(arr[i]!=0)
                cout<<arr[i]<<" ";
        cout<<"\n\n";
    }
};
int main() {
    Insertion obj;
    bool choice=true;
    while(choice){
        int Check;
        cout<<"\n\tFirst Position than press-1\n\tAny Position than press-2\n\tLast Position than press-3\n\tDelete than Press-4\n\tExit Than Press-5\n";
        cin>>Check;
        switch(Check){
            case 1:
                int val1;
                cout<<"Insert Value: ";
                cin>>val1;
                if(0<val1){
                    obj.firstPosInsert(val1);
                    obj.ShowAll();
                }
                else
                    cout<<"0 less than\n";
                break;
            case 2:
                int val2,pos;
                cout<<"Insert Value: ";
                cin>>val2;
                cout<<"Position Index: ";
                cin>>pos;
                if (0<val2){
                    obj.anyPosInsert(val2,pos);
                    obj.ShowAll();
                }
                else
                    cout<<"0 less than\n";
                break;
            case 3:
                int val3;
                cout<<"Insert Value: ";
                cin>>val3;
                if (0<val3) {
                    obj.lastPosInsert(val3);
                    obj.ShowAll();
                }
                else
                    cout<<"0 less than\n";
                break;
            case 4:
                int val4;
                cout<<"Delete Value: ";
                cin>>val4;
                if(0<val4){
                  obj.deletion(val4);
                  obj.ShowAll();
                }
                else{
                  cout<<"0 less than\n";
                }
                break;
            case 5:
                choice=false;
                break;
            default:
                cout<<"Enter a valid choice(1 to 5)\n";
        }
    }
}