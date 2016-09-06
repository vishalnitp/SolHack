#include<bits/stdc++.h>
using namespace std;

struct node
{
 int data;
 int rankk;
 node *parent;
};
map<int,node> mymap;
map<int,node>::iterator itr,it,itrr;
void makeSet(int data)
{
  node temp;
   temp.data=data;temp.rankk=0;temp.parent=NULL;
   mymap.insert(pair<int,node>(data,temp));
}
void findSet(int data)
{
 it=mymap.find(data);
 if(!it->second.parent)
  cout<<"Representative of "<<data<<" : "<<it->second.data;
 while(it->second.parent)
  {itr=it;it->second.parent=itr->second.parent;}
  cout<<"Representative of "<<data<<" : "<<itr->second.data;
}
void unionOf(int data1,int data2)
{
 it=mymap.find(data1);itr=mymap.find(data2);
 if(it->second.rankk>=itr->second.rankk)
   itr->second.parent=it->second;
}
int main()
{


return 0;
}
