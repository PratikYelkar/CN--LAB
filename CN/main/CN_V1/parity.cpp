//#include<iostream>
//#include<string>
//#include<ctime>
# include <bits/stdc++.h>
using namespace std;

class Parity{
    int senderbits[8];
    int receiverbits[8];

    public:
    void input();
    void sender(string);
    void change();
    void receiver(string);
    void check();
    void display(string,int);
};

void Parity::input(){
    cout<<"Enter Seven Bits: ";

    int i = 0;
    while(i<7){
        int temp;
        cout<<"\n\tEnter "<<i<<" Bit: ";
        cin>>temp;

        if(temp == 0 || temp == 1)
        {
            senderbits[i] = temp;
            receiverbits[i] = temp;
            i++;
        }
        else{
            cout<<"Invalid Entary!!!";
            cout<<endl<<"Please enter either 1 or 0";
        }
    }
}

void Parity::sender(string p){
    int count = 0;
    for(int i = 0; i<7; i++){
        if(senderbits[i] == 1){
            count ++;
        }
    }

    if(p == "even"|| p == "Even"){
        if(count % 2 == 0){
            senderbits[7] = 0;
        }
        else{
            senderbits[7] = 1;
        }
    }
    else{
        if(count % 2 ==0){
            senderbits[7] = 1;
        }
        else{
            senderbits[7] = 0;
        }
    }
}

void Parity::receiver(string p){
    int count = 0;
    for(int i = 0; i<7; i++){
        if(receiverbits[i] == 1){
            count ++;
        }
    }

    if(p == "even"|| p == "Even"){
        if(count % 2 == 0){
            receiverbits[7] = 0;
        }
        else{
            receiverbits[7] = 1;
        }
    }
    else{
        if(count % 2 ==0){
            receiverbits[7] = 1;
        }
        else{
            receiverbits[7] = 0;
        }
    }
}

void Parity::change(){
    for(int m =1; m<=4;m++){
        srand(time(0));
        int randomNumber1 = rand()%7;
        int randomNumber2 = rand()%2;

        receiverbits[randomNumber1]=randomNumber2;
    }
}

void Parity::check(){
    if(senderbits[7] == receiverbits[7]){
        cout<<endl<<"NO Error While Transmiting";
    }
    else{
        cout<<endl<<"Error While Transmiting";
    }
}

void Parity::display(string p, int n){
    if(p == "senderbits"){
        for(int i =0; i<n;i++)
        {
            cout<<senderbits[i]<<" ";
        }
    }
    else{
        for(int i=0; i<n; i++)
        {
            cout<<receiverbits[i]<<" ";
        }
    }
}


int main()
{
    while(true){
        Parity P;
        P.input();

        int ch;
        cout<<endl<<"Select: "<<endl<<"1.Even Parity"<<endl<<"2.Odd Parity";
        cin>>ch;
        cout<<endl;
        
        switch(ch){
            case 1:
            {
                P.sender("Even");
                cout<<endl<<"Bits Entered At Sender Side: ";
                P.display("senderbits",8);
                P.change();
                cout<<endl<<"Change Bits: ";
                P.display("recevierbits",7);
                P.receiver("Even");
                cout<<endl<<"Bits Recived At Reciver Side: ";
                P.display("recevierbits",8);
                P.check();
                break;
            }

            case 2:
            {
               P.sender("Odd");
                cout<<endl<<"Bits Entered At Sender Side: ";
                P.display("senderbits",8);
                P.change();
                cout<<endl<<"Change Bits: ";
                P.display("recevierbits",7);
                P.receiver("Odd");
                cout<<endl<<"Bits Recived At Reciver Side: ";
                P.display("recevierbits",8);
                P.check();
                break; 
            }
            default:cout<<"Wrong Choice";
        }
        char c;
        cout<<endl<<"Do you want to continuoue(y/n): ";
        cin>>c;

        if(c == 'n'){
            break;
        }
    }
    return 0;
}

