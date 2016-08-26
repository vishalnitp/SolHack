#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;cin>>t;
    for(int i=0;i<t;i++)
        {
         int n,m,s;
        cin>>n;cin>>m;cin>>s;
        int r=m%n;
        if(s+r>n)
            cout<<s+r-n-1<<"\n";
        else
             cout<<s+r-1<<"\n";
        }
    return 0;
}
