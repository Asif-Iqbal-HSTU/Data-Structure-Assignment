#include <bits/stdc++.h>
using namespace std;


int main()
{
    cout<<"\n#####TASK 2.1#####\n";
    string s = "PEOPLE";
    int comp = 0 , ic = 0;

    for(int i=0; i+1<6; i++){
        for(int j=0; j+i+1<6; j++){
            comp++;
            if(s[j] >= s[j+1]){
                swap(s[j], s[j+1]);
                ic++;
            }
        }
    }
    cout<<"Sorted string: "<<s<<endl;
    cout<<"Comparisons: "<<comp<<"\n"<<"Interchanges: "<<ic<<endl;

    cout<<"\n#####TASK 2.2######\n";

    int data[] = {11, 22, 30, 33, 40, 44, 55, 60, 66, 77, 80, 88, 99};

    int n;
    cout<<"Enter item to be searched: ";
    cin>>n;

    int begin = 0, end = 13, mid;
    bool found = false;

    while(begin<=end){
        mid = (begin+end)/2;
        if(data[mid] == n){
            cout<<n<<" is found at position: "<<mid+1<<endl;
            found = true;
            break;
        }
        else if(data[mid] > n) end = mid - 1;
        else begin = mid + 1;
    }

    if(found == false) cout<<n<<" is not present in data!"<<endl;

    return 0;
}


