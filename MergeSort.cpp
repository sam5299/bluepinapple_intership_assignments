#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high){
        
        int size1 = mid-low+1;
        int size2 = high-mid;
        int arr1[size1];
        int arr2[size2];
        for(int i=0;i<size1;i++){
            arr1[i] = arr[i+low];
        }
        for(int i=0;i<size2;i++){
            arr2[i] = arr[i+mid+1];
        }
        int a=0,b=0,k=low;
        while(a<size1 && b<size2){
            if(arr1[a]<arr2[b]){
                arr[k] = arr1[a];
                a++;
                k++;
            }
            else{
                arr[k] = arr2[b];
                b++;
                k++;
            }
        }
            while(a<size1){
                arr[k] = arr1[a];
                a++;
                k++;
            }
            while(b<size2){
                arr[k] = arr2[b];
                b++;
                k++;
            }

    }

void margeSort(int arr[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
       //  cout<<"value of mid"<<mid<<endl;
        margeSort(arr,low,mid);
        margeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}

int main(){
    int n = 0;
    cout<<"Enter length of array:";
    cin>>n;
    int array[n];
    cout<<endl<<"enter array elements:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    margeSort(array,0,n-1);

    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}