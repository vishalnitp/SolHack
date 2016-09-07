#include<bits/stdc++.h>
using namespace std;

struct node
{
 int data;
 int rankk;
 node *parent;
 node(int data)
 {data=data;rankk=0;parent=NULL;}
};
map<int,node*> mymap;
map<int,node*>::iterator itr,it,itrr;
void makeSet(int data)
{
  node *temp=new node(data);
   mymap.insert(pair<int,node*>(data,temp));
}
void findSet(int data)
{
 it=mymap.find(data);
 if(it->second->parent!=NULL)
  cout<<"\nRepresentative of "<<data<<" : "<<it->second->data;
 while(it->second->parent)
  {itr=it;it->second=itr->second->parent;}
  cout<<"\nRepresentative of "<<data<<" : "<<itr->second->data;
}
void unionOf(int data1,int data2)
{
 it=mymap.find(data1);itr=mymap.find(data2);
 if(it->second->rankk=itr->second->rankk)
   {itr->second->parent=it->second->parent;it->second->rankk++;return;}
 if (it->second->rankk>itr->second->rankk)
   {it->second->parent=itr->second->parent;return;}
 if (it->second->rankk<itr->second->rankk)
   {itr->second->parent=it->second->parent;return;}
}
int main()
{
  cout<<"Creating a new set:";
  makeSet(1),makeSet(2),makeSet(3),makeSet(4),makeSet(5),makeSet(6);
  findSet(1),findSet(2),findSet(3),findSet(4),findSet(5),findSet(6);


return 0;
}
