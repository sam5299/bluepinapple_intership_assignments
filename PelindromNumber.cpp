#include<iostream>
using namespace std;
int main(){
    int number = 0;
    int copyorignal = 0;
    int reversed_number = 0;
    cout<<"Enter number:";
    cin>>number;
    number = abs(number);
    copyorignal = number;
    if(number>=0 && number<=9){
        cout<<"number is pelindrom";
        exit(0);
    }
    while(number>0){
        int rem = number%10;
        reversed_number = reversed_number*10+rem;
        number/=10;
    }
   
    if(copyorignal == reversed_number){
        cout<<"Number is pelindrom:";
    }
    else{
        cout<<"Number is not pelindrom";
    }
}