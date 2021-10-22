#include <iostream>
using namespace std;
class Student{
    string name;
    float cgpa;
    int credit;
public:
    Student(){
    }
    Student(string name,float cgpa,int credit){
        this->name=name;
        this->cgpa=cgpa;
        this->credit=credit;
    }
    void setName(string name){
        this->name=name;
    }
    string getName(){
        return name;
    }
    void setCgpa(float cgpa){
        this->cgpa=cgpa;
    }
    float getCgpa() {
        return cgpa;
    }
    void setCredit(int credit){
        this->credit=credit;
    }
    int getCredit() {
        return credit;
    }

    void showAll(){
        cout<<"Name: "<<getName()<<"\n";
        cout<<"Cgpa: "<<getCgpa()<<"\n";
        cout<<"Credit: "<<getCredit()<<"\n";
    }
};
class Queue{
private:
    Student *arr;
   // int Size=sizeof (arr)/sizeof(arr[0]);
    int front=0,rear=-1,totalItem=0,maxsize,count=0;
public:
    Queue(){
    }
    Queue(int ArrSize){
        cout<<"Array Initial Size: "<<ArrSize<<"\n";
        maxsize=ArrSize;
        arr=new Student[maxsize];
    }
    ~Queue(){
        delete[]arr;
    }
    bool isFull(){
        if(maxsize==totalItem)
            return true;
        return false;
    }
    bool isEmpty(){
        if(totalItem==0)
            return true;
        return false;
    }
    void enQueue(Student val){
        if(isFull()){
            if(count==0){
                    Student *tempArr=new Student[maxsize*2];
                    for (int i = 0; i < maxsize; i++) {
                        tempArr[i]=arr[i];
                    }
                    maxsize*=2;
                    arr=tempArr;
                    count++;
            }
            else {
                cout << "\n\nArray already Increased:" << ".\n\n";
                return;
            }
        }
        rear=(rear+1)%maxsize;
        arr[rear]=val;
        totalItem++;
        cout<<"\nInserted\n";
        val.showAll();
    }
    void deQueue(){
        if(isEmpty()){
            cout<<"Sorry! the Queue is Empty.\n";
            return;
        }
        Student frontVal=arr[front];
        //arr[front]=0;
        front=(front+1)%maxsize;
        totalItem--;
        cout<<"\nDeleted\n";
        frontVal.showAll();
    }
    void ShowAll(){
        if(isEmpty()){
            cout<<"Array is empty\n";
            return;
        }
        if(rear>=front){
            cout<<"\nFront-> "<<front<<"\n";
           // cout<<"Circular Queue Element: ";
            for (int j = front; j <=rear; j++)
                arr[j].showAll();
            cout<<"\nRear-> "<<rear;
        } else{
            cout<<"\nFront-> "<<front<<"\n";
            cout<<"Circular Queue Element: ";
            for (int k = front; k < maxsize; k++)
                arr[k].showAll();
            for (int l = 0; l <=rear; l++)
                arr[l].showAll();
            cout<<"\nRear-> "<<rear;
        }
        cout<<"\n";
    }

};
int main() {
    int size;
    cout<<"Array Size: ";
    cin>>size;
    Queue q(size);
    Student s;
    string name;
    float cgpa;
    int credit;
    //Student s1(name,cgpa,credit);
    bool choice = true;
    while (choice) {
        cout << "\n.....Circular Queue.....\n";
        cout << "Enqueue Element Press-1\n";
        cout << "Dequeue Element Press-2\n";
        cout << "ShowAll Press-3\n";
        cout << "Exit Than Press-4\n";
        int Case;
        cin >> Case;
        switch (Case) {
            case 1:
                cout<<"Enter Your Name: ";
                cin>>name;
                s.setName(name);
                cout<<"Enter Your Cgpa: ";
                cin>>cgpa;
                s.setCgpa(cgpa);
                cout<<"Enter Your Credit: ";
                cin>>credit;
                s.setCredit(credit);
               // q.enQueue(s1);
                q.enQueue(s);
                break;
            case 2:
                q.deQueue();
                break;
            case 3:
                q.ShowAll();
                break;
            case 4:
                choice = false;
            default:
                cout<<"Please Try Again! Press Enter (1-4)\n\n";
        }
    }
}