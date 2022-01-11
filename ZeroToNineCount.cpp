#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    int n = 0;
    cout<<"Enter value of n:";
    cin>>n;
    n = abs(n);
    cout<<"value of n:"<<n;
    int array[10];
    for(int i=0;i<10;i++){
        array[i] = 0;
    }
    while(n>0){
        int rem = n%10;
        array[rem] = array[rem]+1;
        n /= 10;
    }

    cout<<"occurance of each digit "<<endl;

    for(int i=0;i<10;i++){
        cout<<i<<":"<<array[i]<<",";
    }
}