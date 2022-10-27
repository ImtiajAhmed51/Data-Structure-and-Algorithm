#include<iostream>
#include <cmath>
using namespace std;
void midPointCircle(int x,int y,int r){
    int x1=0;
    int pk=1-r;
    int y1=r;
    while (x1<y1){
        int y2=y1;
        if(pk>=0)
            cout<<"|"<<x+x1<<","<<y+y1--;
        else if(pk<0)
            cout<<"|"<<x+x1<<","<<y+y1;
        x1++;
        cout<<"|"<<pk<<"|"<<x+x1<<","<<y+y1<<"|\n";
        pk=pk+(2*x1)+((y1*y1)-(y2*y2))-(y1-y2)+1;
    }
}
int main(){
    midPointCircle(0,0,9);
}

// Output

// |0,9|-8|1,9|
// |1,9|-5|2,9|
// |2,9|0|3,8|
// |3,8|-9|4,8|
// |4,8|0|5,7|
// |5,7|-3|6,7|
// |6,7|10|7,6|