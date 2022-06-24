#include <iostream>
using namespace std;
int Partition(int A[],int start,int end){
    int i=start+1;
    int piv=A[start];
    int temp;
    for (int j = start+1; j <=end; j++)
        if(A[j]<piv){
            temp=A[j];
            A[j]=A[i];
            A[i]=temp;
            i++;
        }
    temp=A[start];
    A[start]=A[i-1];
    A[i-1]=temp;
    return i-1;
}
void Quick_Sort(int A[],int start,int end){
    if(start<end){
        int piv_pos= Partition(A,start,end);
        Quick_Sort(A,start,piv_pos-1);
        Quick_Sort(A,piv_pos+1,end);
    }
}
int main() {
    int A[]={6,10,8,7,4,8,90,34,12,3};
    int size=sizeof (A)/sizeof (A[0]);
    Quick_Sort(A,0,size-1);
    for (int i = 0; i < size; i++)
        cout<<A[i]<<", ";
}