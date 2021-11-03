#include <iostream>
using namespace std;
class Counter{
    string date,ticket,type,carNum;
    int charge;
public:
    Counter(){
    }
    Counter(string date,string carNum,string ticket){
        this->date=date;
        this->carNum=carNum;
        this->ticket=ticket;
    }
    void setDate(string date){
        this->date=date;
    }
    string getDate(){
        return date;
    }
    void setCarNum(string carNum){
        this->carNum=carNum;
    }
    string getCarNum() {
        return carNum;
    }
    void setTicket(string ticket){
        this->ticket=ticket;
    }
    string getTicket() {
        return ticket;
    }
    void setType(string type){
        this->type=type;
    }
    string getType(){
        return this->type;
    }
    void setCharge(int charge){
        this->charge=charge;
    }
    int getCharge(){
        return this->charge;
    }
    void ShowAll(){
        cout<<getType()<<"-Duty\n";
        cout<<"Date: "<<this->getDate()<<"\n";
        cout<<"Car No: "<<this->getCarNum()<<"\n";
        cout<<"Ticket No: "<<this->getTicket()<<"\n";
    }
};
class HeavyCounter:public Counter{
public:
    //int charge;
    HeavyCounter(){
        setType("Heavy");
        setCharge(800);
    }
    ~HeavyCounter(){
        setType("");
        setCharge(0);
    }
    HeavyCounter(string date,string carNum,string ticket){
        setDate(date);
        setTicket(ticket);
        setCarNum(carNum);
        setType("Heavy");
        setCharge(800);
    }

//    void ShowAll(){
//        ShowAll();
//        cout<<"Heavy-Duty\n";
//    }
};
class MediumCounter:public Counter{
public:
    //string type;
    //int charge;
    MediumCounter(){
        setType("Medium");
        setCharge(800);
    }
    ~MediumCounter(){
        setType("");
        setCharge(0);
    }
    MediumCounter(string date,string carNum,string ticket){
        setDate(date);
        setTicket(ticket);
        setCarNum(carNum);
        setType("Medium");
        setCharge(500);
    }
//    void ShowAll(){
//        ShowAll();
//        cout<<"Medium-Duty\n";
//
//    }
};
class LightCounter:public Counter{
public:
    //string type;
    //int charge;
    LightCounter(){
        setType("Light");
        setCharge(300);
    }
    ~LightCounter(){
        setType("");
        setCharge(0);
    }
    LightCounter(string date,string carNum,string ticket){
        setDate(date);
        setTicket(ticket);
        setCarNum(carNum);
        setType("Light");
        setCharge(300);
    }
//    void ShowAll(){
//        ShowAll();
//        cout<<"Light-Duty\n";
//    }
};
class Queue{
private:
    Counter HeavyQueue[2];
    Counter MediumQueue[2];
    Counter LightQueue[2];
    Counter CarInfo[6];
    //int infoSize=sizeof (InfoArr)/sizeof(InfoArr[0]);
    int counter=-1;
    int HeavySize=sizeof(HeavyQueue)/sizeof(HeavyQueue[0]);
    int MediumSize=sizeof(MediumQueue)/sizeof(MediumQueue[0]);
    int LightSize=sizeof(LightQueue)/sizeof(LightQueue[0]);
    int heavyFront=0,heavyRear=-1;
    int mediumFront=0,mediumRear=-1;
    int lightFront=0,lightRear=-1;
    int heavyTotalItem=0;
    int mediumTotalItem=0;
    int lightTotalItem=0;
    int heavyEarning=0;
    int mediumEarning=0;
    int lightEarning=0;
public:
    bool isHeavyFull(){
        if(heavyTotalItem==HeavySize)
            return true;
        return false;
    }
    bool isHeavyEmpty(){
        if(heavyTotalItem==0)
            return true;
        return false;
    }
    bool isMediumFull(){
        if(mediumTotalItem==MediumSize)
            return true;
        return false;
    }
    bool isMediumEmpty(){
        if(mediumTotalItem==0)
            return true;
        return false;
    }
    bool isLightFull(){
        if(lightTotalItem==LightSize)
            return true;
        return false;
    }
    bool isLightEmpty(){
        if(lightTotalItem==0)
            return true;
        return false;
    }
    void enqueue(Counter val){
        if(val.getType()=="Heavy"){
            if(isHeavyFull()){
                cout<<"\nSorry! Heavy-Duty Counter is Full.\n";
                return;
            }
            heavyRear=(heavyRear+1)%HeavySize;
            HeavyQueue[heavyRear]=val;
            heavyTotalItem++;
            cout<<"\nEntry Counter\n";
            val.ShowAll();
        }
        else if(val.getType()=="Medium"){
            if(isMediumFull()){
                cout<<"\nSorry! Medium-Duty Counter is Full.\n";
                return;
            }
            mediumRear=(mediumRear+1)%MediumSize;
            MediumQueue[mediumRear]=val;
            mediumTotalItem++;
            cout<<"\nEntry Counter\n";
            val.ShowAll();
        }
        else if(val.getType()=="Light"){
            if(isLightFull()){
                cout<<"\nSorry! Light-Duty Counter is Full.\n";
                return;
            }
            lightRear=(lightRear+1)%LightSize;
            LightQueue[lightRear]=val;
            lightTotalItem++;
            cout<<"\nEntry Counter\n";
            val.ShowAll();
        }
        else{
            cout<< "\nWrong Type\n";
        }
    }
    Counter dequeue(string type){
        if(type=="Heavy"){
            if(!isHeavyEmpty()){
                counter++;
                Counter frontVal=HeavyQueue[heavyFront];
                //queue[front]=0;
                CarInfo[counter]=frontVal;
                heavyFront=(heavyFront+1)%HeavySize;
                heavyTotalItem--;
                heavyEarning+=frontVal.getCharge();
                return frontVal;
            }
            else{
                cout<<"\n"<<type<<"-Duty Counter is Empty\n";
                Counter obj;
                return obj;
            }
        }
        else if(type=="Medium"){
            if(!isMediumEmpty()){
                counter++;
                Counter frontVal=MediumQueue[mediumFront];
                //queue[front]=0;
                CarInfo[counter]=frontVal;
                mediumFront=(mediumFront+1)%MediumSize;
                mediumTotalItem--;
                mediumEarning+=frontVal.getCharge();
                return frontVal;
            }
            else{
                cout<<"\n"<<type<<"-Duty Counter is Empty\n";
                Counter obj;
                return obj;
            }
        }
        else if(type=="Light"){
            if(!isLightEmpty()){
                counter++;
                Counter frontVal=LightQueue[lightFront];
                //queue[front]=0;
                CarInfo[counter]=frontVal;
                lightFront=(lightFront+1)%LightSize;
                lightTotalItem--;
                lightEarning+=frontVal.getCharge();
                return frontVal;
            }
            else{
                cout<<"\n"<<type<<"-Duty Counter is Empty\n";
                Counter obj;
                return obj;
            }
        }
        else{
            cout<< "\nWrong Type\n";
            Counter obj;
            return obj;
        }
    }
    int totalEarning(){
        return heavyEarning+mediumEarning+lightEarning;
    }
    Counter search(string carNum){
        for (int i = 0; i <=counter; i++) {
            if (carNum==CarInfo[i].getCarNum()){
                cout<<"\nFound This Car\n";
                return CarInfo[i];
            }
        }
        cout<<"\nNot Found\n";
        Counter obj;
        return obj;
    }
};
int main() {
    HeavyCounter obj;
    MediumCounter obj1;
    LightCounter obj2;
    Counter ob;
    Queue obj3;
    bool choice= true;
    while (choice){
        cout<<"\n\t...PADMA BRIDGE TOLL...\n";
        cout<<"\t1. Entry Counter.\n";
        cout<<"\t2. Exit Counter.\n";
        cout<<"\t3. Total Toll Amount.\n";
        cout<<"\t4. Car Search.\n";
        cout<<"\t5. Exit/Close\n";
        int Case,Case1;
        string date,carNum,ticket;
        cout<<"Enter Your Input: ";
        cin>>Case;
        switch (Case) {
            case 1:
                cout<<"\n\t1. Heavy-Duty.\n";
                cout<<"\t2. Medium-Duty.\n";
                cout<<"\t3. Light-Duty.\n";
                cout<<"Enter Your Number: ";
                cin>>Case1;
                if(Case1==1){
                    cout<<"Enter Date: ";
                    cin>>date;
                    cout<<"Enter Car No: ";
                    cin>>carNum;
                    cout<<"Enter Ticket No: ";
                    cin>>ticket;
                    obj.setDate(date);
                    obj.setCarNum(carNum);
                    obj.setTicket(ticket);
                    //obj.setType("Heavy");
                    obj3.enqueue(obj);
                } else if(Case1==2){
                    cout<<"Enter Date: ";
                    cin>>date;
                    cout<<"Enter Car No: ";
                    cin>>carNum;
                    cout<<"Enter Ticket No: ";
                    cin>>ticket;
                    obj1.setDate(date);
                    obj1.setCarNum(carNum);
                    obj1.setTicket(ticket);
                    //obj1.setType("Medium");
                    obj3.enqueue(obj1);
                } else if(Case1==3){
                    cout<<"Enter Date: ";
                    cin>>date;
                    cout<<"Enter Car No: ";
                    cin>>carNum;
                    cout<<"Enter Ticket No: ";
                    cin>>ticket;
                    obj2.setDate(date);
                    obj2.setCarNum(carNum);
                    obj2.setTicket(ticket);
                    //obj2.setType("Light");
                    obj3.enqueue(obj2);
                }
                else{
                    cout<<"Wrong Input\n";
                }
                break;
            case 2:
                cout<<"\n\t1. Heavy-Duty.\n";
                cout<<"\t2. Medium-Duty.\n";
                cout<<"\t3. Light-Duty.\n";
                cout<<"Enter Your Number: ";
                cin>>Case1;
                if(Case1==1){
                    ob=obj3.dequeue("Heavy");
                    if(ob.getCarNum()==""){
                    } else{
                        cout<<"\nExit Counter\n";
                        ob.ShowAll();
                    }
                }
                else if(Case1==2){
                    ob=obj3.dequeue("Medium");
                    if(ob.getCarNum()==""){
                    } else{
                        cout<<"\nExit Counter\n";
                        ob.ShowAll();
                    }
                }else if(Case1==3){
                    ob=obj3.dequeue("Light");
                    if(ob.getCarNum()==""){
                    } else{
                        cout<<"\nExit Counter\n";
                        ob.ShowAll();
                    }
                } else{
                    cout<<"Wrong Input\n";
                }
                break;
            case 3:
                cout<<"\nTotal Amount: "<<obj3.totalEarning()<<" Taka Only.\n";
                break;
            case 4:
                cout<<"Car Number: ";
                cin>>carNum;
                ob=obj3.search(carNum);
                if (ob.getCarNum()==""){
                } else{
                    obj3.search(carNum).ShowAll();
                }
                break;
            case 5:
                choice=false;
                break;
            default:
                cout<<"Wrong Input Please Try Again (1-5)\n";
        }
    }
}