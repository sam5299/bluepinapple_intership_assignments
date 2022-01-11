#include<iostream>
using namespace std;
int main(){
    int number = 0;
    cout<<"Enter value of number till which you want to print perfect number:";
    cin>>number;
    int sum = 0;

    if(number<=1){
        exit(0);
    }
    int half = int(number/2);
    cout<<"List of perfect numbers:";
    for(int i=2;i<number;i++){
        sum = 0;
        for(int j=1;j<int(i/2)+1;j++){
            if(i%j==0){
                sum+=j;
            }
        }
        if(sum==i){
            cout<<" "<<i;
        }
    }

}