#include <iostream>
using namespace std;
class LinkedList{
private:
    int val,size;
    LinkedList*next,*prev,*head,*tail;
public:
    LinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    LinkedList(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
    void insertEnd(int val){
        LinkedList* newNode=new LinkedList(val);
        if(tail==NULL){
            head=newNode;
            tail=newNode;
            head->prev=NULL;
            head->tail=NULL;
            size++;
        }
        else{
            tail->next= newNode;
            newNode->prev=tail;
            tail=newNode;
            size++;
        }
    }
    void insertAnyPos(int pos,int val){
        LinkedList* newNode=new LinkedList(val);
        LinkedList* temp = head;
        if(pos==0)
            insertFront(val);
        else if(pos>size)
            insertEnd(val);
        else{
            for(int i = 1; i < pos; i++)
                if(temp != NULL)
                    temp = temp->next;
            if(temp != NULL) {
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                if(newNode->next != NULL)
                    newNode->next->prev = newNode;
                size++;
            } else
                cout<<"\nThe previous node is null.";
        }
    }
    void insertFront(int val){
        LinkedList* newNode=new LinkedList(val);
        if(tail==NULL){
            head=newNode;
            tail=newNode;
            head->prev=NULL;
            head->tail=NULL;
            size++;
        }
        else{
            newNode->prev=NULL;
            newNode->next= head;
            head->prev=newNode;
            head= newNode;
            size++;
        }
    }
    void removePositionItem(int position){
        LinkedList* temp = head;
        for (int i = 0; i < size; i++) {
            if(i==position){
                removeNode(temp);
                size--;
            }
            temp=temp->next;
        }
    }
    void removeNode(LinkedList* node){
        LinkedList* temp = node;
        if(temp->prev==NULL)
            head=temp->next;
        else
            temp->prev->next=temp->next;
        if(temp->next==NULL)
            tail=temp->prev;
        else
            temp->next->prev=temp->prev;
    }
    void removeItem(int value){
        LinkedList* temp = head;
        while (temp!=NULL){
            if(temp->val==value){
                removeNode(temp);
                size--;
                return;
            }
            temp=temp->next;
        }
        cout<<"\nNot Found "<<value<<" value.";
    }
    void removeLastItem(){
        if(tail!=NULL){
            removeNode(tail);
            size--;
        }
    }
    void removeFirstItem(){
        if(head!=NULL){
            removeNode(head);
            size--;
        }
    }
    void printList(){
        LinkedList* linkedList=head;
        cout<<"\nDoubly Linked List: ";
        cout<<"Null <--> ";
        while (linkedList!=NULL){
            cout<<linkedList->val<<" <--> ";
            linkedList=linkedList->next;
        }
        cout<<"Null";
        cout<<"\nSize: "<<size<<endl;
    }
};
int main() {
    LinkedList obj;
    obj.insertFront(11);
    obj.printList();
//    Output
//    Doubly Linked List: Null <--> 11 <--> Null
//    Size: 1
    obj.insertFront(21);
    obj.printList();
//    Output
//    Doubly Linked List: Null <--> 21 <--> 11 <--> Null
//    Size: 2
    obj.insertEnd(31);
    obj.printList();
//    Output
//    Doubly Linked List: Null <--> 21 <--> 11 <--> 31 <--> Null
//    Size: 3
    obj.insertAnyPos(2,41);
    obj.printList();
//    Output
//    Doubly Linked List: Null <--> 21 <--> 11 <--> 41 <--> 31 <--> Null
//    Size: 4
    obj.removePositionItem(2);
    obj.printList();
//    Output
//    Doubly Linked List: Null <--> 21 <--> 11 <--> 31 <--> Null
//    Size: 3
    obj.removeLastItem();
    obj.printList();
//    Output
//    Doubly Linked List: Null <--> 21 <--> 11 <--> Null
//    Size: 2
    obj.removeFirstItem();
    obj.printList();
//    Output
//    Doubly Linked List: Null <--> 11 <--> Null
//    Size: 1
    obj.removeItem(11);
    obj.printList();
//    Output
//    Doubly Linked List: Null <--> Null
//    Size: 0
}

