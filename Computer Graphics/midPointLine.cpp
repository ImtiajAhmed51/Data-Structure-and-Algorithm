#include<iostream>
#include <cmath>
using namespace std;
void midPointLine(int x1, int y1, int x2, int y2){
    int dy = y2-y1;
    int dx = x2-x1;
    int initPk=(2*dy)-dx;
    float m=(float)dy/float(dx);
    if(m<1)
        while(x1<=x2){
            int y3=y1;
            if(initPk>0)
                cout<<"|"<<x1++<<","<<y1++;
            else
                cout<<"|"<<x1++<<","<<y1;
            cout<<"| "<<initPk<<" | "<<x1<<","<<y1<<"|\n";
            initPk=initPk+(2*dy)-(2*dx)*(y1-y3);
        }
    else if(m==1)
        while(x1<=x2){
            cout<<"|"<<x1++<<","<<y1++<<"|\n";
        }
}
int main(){
     midPointLine(10, 2, 19, 8);
}