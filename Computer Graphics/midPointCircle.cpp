#include<iostream>
#include <cmath>
using namespace std;
void incrementalLine(int x1, int y1, int x2, int y2){
    float m=(float)(y2-y1)/(float)(x2-x1);
    float y=(float)y1;
    float x=(float)x1;
    if(m<1)
        while (x1<=x2){
            cout<<"|"<<x1<<","<<round(y)<<"| y= "<<y<<"\n";
            y+=m;
            x1++;
        }
    else if(m==1)
        while (x1<=x2) {
            cout <<"|"<< x1 << "," << y1 << "|\n";
            x1++;
            y1++;
        }
    else
        while (y1<=y2){
            cout<<"|"<<round(x)<<","<<y1<<"| x= "<<x<<"\n";
            x=x+1+1/m;
            y1++;
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