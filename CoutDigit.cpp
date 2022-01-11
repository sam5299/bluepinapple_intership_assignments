#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    int number = 0;
    cout<<"Enter number:";
    cin>>number;
    if(number <= 0){
        number = abs(number);
    }
    cout<<"Absoute value of entered number:"<<number<<endl;
    int digit_count = 0;
    do{
        digit_count+=1;
        number/=10;
    }while(number>0);
    cout<<"Number of digit in input number:"<<digit_count;
}