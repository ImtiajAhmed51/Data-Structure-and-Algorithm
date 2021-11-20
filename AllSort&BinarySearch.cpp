#include<iostream>
using namespace std;
class Student{
private:
    string name;
    double cgpa,age;
public:
    Student(){
    }
    Student(string name,double cgpa,double age){
        this->name=name;
        this->cgpa=cgpa;
        this->age=age;
    }
    void setName(string name){
        this->name=name;
    }
    string getName(){
        return this->name;
    }
    void setCgpa(double cgpa){
        this->cgpa=cgpa;
    }
    double getCgpa(){
        return this->cgpa;
    }
    void setAge(double age){
        this->age=age;
    }
    double getAge(){
        return this->age;
    }
    void StudentShowAll(){
        cout<<"\nName: "<<getName();
        cout<<"\nCgpa: "<<getCgpa();
        cout<<"\nAge: "<<getAge()<<"\n";
    }
};
class Sort {
private:
    Student arr[5];
    int n=-1,l;
    int Size=sizeof(arr)/sizeof(arr[0]);
    int index;
    int counter=0;
    Student temp;
public:
    Sort(){
    }
    bool isFull(){
        if(n==Size-1)
            return true;
        return false;
    }
    bool isEmpty(){
        if(n==-1)
            return true;
        return false;
    }
    void insert(Student val){
        if(isFull()){
            cout<<"\nArray Full\n";
            return;
        }
        arr[++n]=val;
        counter=0;
        cout<<"\nInsert Successfully\n";
        val.StudentShowAll();
    }
    void insertionSort(){
        if(isEmpty()){
            cout<<"\nInsertion Sorting Unsuccessfully.\n";
            return;
        }
        for (int i=1;i<=n;i++){
            temp=arr[i];
            l=i-1;
            while (l>=0&&arr[l].getAge()>temp.getAge()){
                arr[l+1]=arr[l];
                l=l-1;
            }
            arr[l+1]=temp;
        }
        counter++;
        cout<<"\nInsertion Sorting Successfully!\n";
        for (int k=0;k<=n;k++)
            arr[k].StudentShowAll();
    }
    void bubbleSort(){
        if(isEmpty()){
            cout<<"\nBubble Sorting Unsuccessfully.\n";
            return;
        }
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n-i-1;j++)
                if (arr[j].getAge()>arr[j+1].getAge()){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
        counter++;
        cout<<"\nBubble Sorting Successfully!\n";
        for (int i=0;i<=n;i++)
            arr[i].StudentShowAll();
    }
    void selectionSort(){
        if(isEmpty()){
           // n==-1
            cout<<"\nSelection Sorting Unsuccessfully\n";
            return;
        }
        for (int i=0;i<n;i++){
            index=i;
            for (int j=i+1;j<=n;j++){
                if(arr[index].getAge()>arr[j].getAge())
                    index=j;
            }
            if(index!=i){
                temp=arr[i];
                arr[i]=arr[index];
                arr[index]=temp;
            }
        }
        counter++;
        cout<<"Selection Sorting Successfully\n";
        for (int i=0;i<=n;i++)
            arr[i].StudentShowAll();
    }
    void binarySearch(double search){
        int first=0,last=n+1,mid,found=0;
        if(isEmpty()){
            cout<<"\nEmpty Array\n";
            return;
        }
        else if(counter==0){
            cout<<"\nNot Sorted\n";
            return;
        }
        while(last>=first){
            mid=(first+last)/2;
            if(arr[mid].getAge()==search){
                cout<<endl<<"Item found at index: ["<<mid<<"]"<<endl;
                arr[mid].StudentShowAll();
                found++;
                break;
            }
            if(arr[mid].getAge()>search)
                last=mid-1;
            else
                first=mid+1;
        }
        if(found==0)
            cout<<"\nNot Found\n";
    }
};
int main(){
    Student obj;
    //Student obj2("Imtiaj Ahmed",3.85,19);
    Sort obj1;
    string name;
    double age,cgpa;
    int choice1,choice2;
    bool choice=true;
    while (choice){
        cout<<"\n\n||Insertion Sort, Bubble Sort, Selection Sort, Binary Search||\n";
        cout<<"\tInsert Than Press-1\n";
        cout<<"\tSort Than Press-2\n";
        cout<<"\tBinary Search Than Press-3\n";
        cout<<"\tExit Than Press-4\n";
        cout<<"Enter Your Choice: ";
        cin>>choice1;
        switch (choice1){
            case 1:
                cout<<"\nEnter Your Name: ";
                //getline(cin,name);
                cin>>name;
                obj.setName(name);
                cout<<"Enter Your Cgpa: ";
                cin>>cgpa;
                if(cgpa<=4.00&&cgpa>=2.50)
                    obj.setCgpa(cgpa);
                else{
                    cout<<"\nYour CGPA Invalid\n";
                    break;
                }
                cout<<"Enter Your Age: ";
                cin>>age;
                obj.setAge(age);
                obj1.insert(obj);
                //obj1.insert(obj2);
                break;
            case 2:
                cout<<"\n\tInsertion Sort Than Press-1\n";
                cout<<"\tBubbleSort Than Press-2\n";
                cout<<"\tSelection Sort Than Press-3\n";
                cout<<"Enter Your Choice: ";
                cin>>choice2;
                if(choice2==1)
                    obj1.insertionSort();
                else if(choice2==2)
                    obj1.bubbleSort();
                else if(choice2==3)
                    obj1.selectionSort();
                else
                    cout<<"\nWrong Input, Please try Again (1-3)\n";
                break;
            case 3:
                cout<<"Enter Your Age: ";
                cin>>age;
                obj1.binarySearch(age);
                break;
            case 4:
                choice=false;
                break;
            default:
                cout<<"\nPlease Try Again! Choice(1-4)\n";
        }
    }
}