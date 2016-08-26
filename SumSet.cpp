#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k,i,j;
    cin<<n>>k;
    vector<int> a(n);
    vector<int> vec;
    for(i=0;i<n;i++)
         cin>>a[i];
    for(i=0;i<n;i++)
    {
         for(j=i+1;j<n;j++)
              {
               if((a[i]+a[j])%k!=0)
               {vec.push_back(a[i]);vec.push_back(a[j]);}
              }
    }

    list<int> x;

  vector<int>::const_iterator it;
  for(it = vec.begin();it < vec.end();it++)
    if(find(x.begin(),x.end(),abs(*it)) == x.end())
             x.push_back(abs(*it));
  cout<<x.size();

    return 0;
}
