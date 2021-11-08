#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
} *head = NULL;

void insertAtBeginning(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    cout<<"\nInserted successfully at beginning\n";
}

void insertAtEnd(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL)
        head = newNode;
    else{
        struct Node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    cout<<"\nInserted successfully at end\n";
}
void insertPosition(int value, int pos){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else {
        struct Node *temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp-> next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    cout<<"\n"<<pos<<"- Position Inserted successfully\n";
}
void removeBeginning(){
    if(head == NULL)
        cout<<"\n\nList is Empty";
    else{
        struct Node *temp = head;
        if(head->next == NULL){
            head = NULL;
            free(temp);
        }
        else{
            head = temp->next;
            free(temp);
            cout<<"\nDeleted at the beginning\n\n";
        }
    }
}

void removeEnd(){
    if(head == NULL){
        cout<<"\nList is Empty\n";
    }
    else{
        struct Node *temp1 = head,*temp2;
        if(head->next == NULL)
            head = NULL;
        else{
            while(temp1->next != NULL){
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = NULL;
        }
        free(temp1);
        cout<<"\nDeleted at the end\n\n";
    }
}

void removePosition(int pos){
    int flag = 1;
    if (head==NULL)
        cout<<"List is empty";
    else {
        struct Node *temp1 = head, *temp2;
        if (pos == 0) {
            head = temp1->next;
            free(temp1);
            cout<<"\n"<<pos<<"-position value deleted\n\n";
        }
        else {
            for (int i = 0; i < pos; i++){
                if (temp1 -> next != NULL) {
                    temp2 = temp1;
                    temp1 = temp1 -> next;
                }
                else {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                temp2 -> next = temp1 -> next;
                free(temp1);
                cout<<"\n"<<pos<<"-position value deleted\n\n";
            }
            else {
                cout<<pos<<"-Position Value Not Found. Please try again";
            }
        }
    }
}

void search(int key){
    while (head != NULL){
        if (head->data == key){
            cout<<"Found in the list\n";
            return;
        }
        head = head->next;
    }
    cout<<"Not found in the list\n";
}

void display(){
    if(head == NULL){
        cout<<"\nList is Empty\n";
    }
    else{
        struct Node *temp = head;
        cout<<"\n\nList elements are - \n";
        while(temp->next != NULL){
            cout<<temp->data<<"--> ";
            temp = temp->next;
        }
        cout<<temp->data<<"--> NULL";
    }
}
int main(){
    int choice,value,pos,key;
    bool choice1= true;
    while(choice1){
        cout<<"\n\nSingly Linked List \n";
        cout<<"1. Insert at beginning\n";
        cout<<"2. Insert at End\n";
        cout<<"3. Insert at location\n";
        cout<<"4. Delete at beginning\n";
        cout<<"5. Delete at End\n";
        cout<<"6. Delete at location\n";
        cout<<"7. Search\n";
        cout<<"8. Display\n";
        cout<<"9. Exit\n\n";
        cout<<"Enter your choice:  ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter Your Value: ";
                cin>>value;
                insertAtBeginning(value);
                break;
            case 2:
                cout<<"Enter Your Value: ";
                cin>>value;
                insertAtEnd(value);
                break;
            case 3:
                cout<<"Enter Your Value: ";
                cin>>value;
                cout<<"Enter Your Position: ";
                cin>>pos;
                insertPosition(value,pos);
                break;
            case 4:
                removeBeginning();
                break;
            case 5:
                removeEnd();
                break;
            case 6:
                cout<<"Enter Your Position: ";
                cin>>pos;
                removePosition(pos);
                break;
            case 7:
                cout<<"Enter Your Value: ";
                cin>>key;
                search(key);
                break;
            case 8:
                display();
                break;
            case 9:
                choice1= false;
                break;
            default:
                cout<<"\nWrong Choice, Please try again (1-9)\n\n";
        }
    }
}