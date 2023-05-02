#include<iostream>
using namespace std;

int min(int a, int b){
    if(a>b)
        return b;
    else
        return a;
}

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

    int V[n][amount+1];

    for (int i = 0; i < n; i++)
    {
        V[i][0] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coin[i]-j>0)
            {
            	if(i==0){
            		V[i][j] = 0;
            		continue;
            	}
                V[i][j] = V[i-1][j];
            }
            else{
            	if(i==0){
            		V[i][j] = 1 + V[i][j-coin[i]];
            		continue;
				}
            		
                V[i][j] = min(V[i-1][j], 1 + V[i][j-coin[i]]);
            }
            
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            cout<<V[i][j]<<"\t";
        }

        cout<<"\n";
    }
    
    int i = n-1;
    int j = amount;
    cout<<"\nNo of Coins Required are "<<V[i][j];
    cout<<"\n";
    
    int noofcoins = V[i][j];
    while(amount>0 && noofcoins!=0){
	    while(V[i][j]==V[i-1][j] && i>0){
	        i--;
	    }
	    while(V[i][j]==V[i][j-1]){
	        j--;
	    }
	    amount = amount - coin[i];
	    cout<<coin[i]<<" "; 
	    noofcoins--;
	    int temp = j; 
	    while(j>0){
	        if(V[i][temp]==noofcoins){
	            j = temp;
	        }
	        temp--;
	    }
	    i--; 
	}
    return 0;
}
