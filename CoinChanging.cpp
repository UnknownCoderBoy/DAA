#include<iostream>
using namespace std;

int main(){
    int n;
    int amount;
    int count = 0;
    cout<<"Enter Number of Coin Denominations: ";
    cin>>n;
    int coin[n];
    for(int i = 0; i < n; i++){
            cin>>coin[i];
    }
    cout<<"\nEnter Amount: ";
    cin>>amount;
    int i = n-1;
    while(i>=0){
        if(amount<coin[i]){
            i--;
        }
        else{
            amount = amount - coin[i];
            count++;
            cout<<coin[i]<<"\t";
        }
    }

    cout<<"\nCoins: "<<count;
    if(amount == 0)
        cout<<"\nAmount is Achieved";
    else
        cout<<"\nAmount cannot be Achieved with given Denominations";
    return 0;
}