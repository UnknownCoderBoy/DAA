#include <bits/stdc++.h>
using namespace std;

int selection_end, cab;

struct Persons
{
    int number;
    int start;
    int end;
    bool travel = false;
};

bool compare(Persons a, Persons b){
    return a.end<b.end;
}

int selection(Persons data[], int n){
    cout<<"\n\n\tSelected Persons For "<<cab+1<<" Cab";
    cout<<"\nPerson\t\tStart Time\tEnd Time";
    int i = 0;
    while(data[i].travel == true){
            i++;
    }
    int j = i + 1;
    cout<<"\n"<<data[i].number<<"\t\t"<<data[i].start<<"\t\t"<<data[i].end;
    data[i].travel = true;
    selection_end--;
    while(j<n){
        if(data[j].travel == false){
            if(data[i].end <= data[j].start){
                data[j].travel = true;
                cout<<"\n"<<data[j].number<<"\t\t"<<data[j].start<<"\t\t"<<data[j].end;
                selection_end--;
                i = j;
            }
        }
        j++;
    }
    return 0;
}

int main(){
    int n;
    cout<<"Enter Number of Person: ";
    cin>>n;
    selection_end = n;
    Persons P[n];
    for(int i = 0; i < n; i++){
        P[i].number = i+1;
        cout<<"Start Time For "<<i+1<<" Person: ";
        cin>>P[i].start;
        cout<<"End Time For "<<i+1<<" Person: ";
        cin>>P[i].end;
    }

    sort(P, P+n, compare);

    cout<<"\n\nPerson\t\tStart Time\tEnd Time";
    for(int i = 0; i < n; i++){
        cout<<"\n"<<P[i].number<<"\t\t"<<P[i].start<<"\t\t"<<P[i].end;
    }

    while(selection_end){
        selection(P, n);
        cab++;
    }

    cout<<"\n\nNumber of Cabs Requires are: "<<cab;
    cin>>n;
    return 0;
}
