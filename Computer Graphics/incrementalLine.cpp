#include<iostream>
#include <cmath>
using namespace std;
void incrementalLine(int x1, int y1, int x2, int y2){
    float m=(float)(y2-y1)/(float)(x2-x1);
    float y=(float)y1;
    float x=(float)x1;
    if(m<1)
        while (x1<=x2){
            cout<<"|"<<x1++<<","<<round(y)<<"| y= "<<y<<"\n";
            y+=m;
        }
    else if(m==1)
        while (x1<=x2)
            cout <<"|"<< x1++<< "," << y1++ << "|\n";
    else
        while (y1<=y2){
            cout<<"|"<<round(x)<<","<<y1++<<"| x= "<<x<<"\n";
            x=x+1/m;
        }
}
int main(){
    incrementalLine(10, 2, 19, 8);
}

// Output

// |10,2| y= 2
// |11,3| y= 2.66667
// |12,3| y= 3.33333
// |13,4| y= 4
// |14,5| y= 4.66667
// |15,5| y= 5.33333
// |16,6| y= 6
// |17,7| y= 6.66667
// |18,7| y= 7.33333
// |19,8| y= 8