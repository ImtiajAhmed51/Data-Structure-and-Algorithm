#include <iostream>
using namespace std;
void CountingSort (int array[],int size) {
    int output[size];
    int maxVal = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > maxVal)
            maxVal = array[i];
    int counterArr[maxVal+1];
    for (int i = 0; i<sizeof(counterArr)/sizeof(counterArr[0]);i++)
        counterArr[i] = 0;
    for (int i = 0; i <size ; i++) 
        counterArr[array[i]]++;
    for (int i = 1; i <=maxVal; i++)
        counterArr[i]+=counterArr[i-1];
    for (int i = size-1; i>=0; i--) {
        output[counterArr[array[i]]-1]=array[i];
        counterArr[array[i]]--;
    }
    for (int i = 0; i < size; i++)
        array[i]=output[i];
}
void Show(int array[],int size){
    for(int i=0;i<size;i++)
        cout<<array[i]<<", ";
}
int main() {
    int n,val;
    cout<<"Enter Your Input Size: ";
    cin>>n;
    int array[n];
    //int size=sizeof(array)/sizeof(array[0]);
    for (int i = 0; i <n; i++) {
        cout<<"Array["<<i<<"]= ";
        cin>>val;
        array[i]=val;
    }
    CountingSort(array,n);
    cout<<"Ascending Order: ";
    Show(array,n);
}