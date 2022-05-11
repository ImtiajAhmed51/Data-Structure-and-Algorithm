#include <iostream>
using namespace std;
void merge (int A[],int start,int mid,int end){
    int i=start,j=mid+1;
    int B[end-start+1],k=0;
    for (int z = start; z <=end; z++) {
        if(i>mid)
            B[k++]=A[j++];
        else if(j>end)
            B[k++]=A[i++];
        else if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for (int p = 0; p < k; p++)
        A[start++]=B[p];
}
void merge_sort(int A[],int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        merge_sort(A,start,mid);
        merge_sort(A,mid+1,end);
        merge(A,start,mid,end);
    }
}
int main() {
    int n,val;
    cout<<"Enter Your Input Size: ";
    cin>>n;
    int array[n];
    int size=sizeof(array)/ sizeof(array[0]);
    for (int i = 0; i < size; i++) {
        cout<<"Array["<<i<<"]= ";
        cin>>val;
        array[i]=val;
    }
    merge_sort(array,0,size-1);
    cout<<"Sorted List: ";
    for (int i = 0; i < size; i++)
        cout<<array[i]<<", ";
}