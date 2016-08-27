#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  struct node *left;
  struct node *right;
}*root;

/*class Node{
	int data;
	Node *left;
	Node *right;
	public:
	    Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
}*root;*/

node *newnode(int data)
{
  node *nn=new node;
   nn->data=data;nn->left=NULL;nn->right=NULL;
  cout<<"New node created with data="<<data<<"\n";
   return nn;
}
 class BST
 {
  public:
     node* insert_BST(node *,int);
     node* erase_BST(node *,int);
     void  preorder(node *);
     void  postorder(node *);
     void  inorder (node *);
     void levelorder(node *);
     int height(node *);
     int leafNodes(node *);
 };

node* BST::insert_BST(node *root,int data)
{
   node *temp=newnode(data);
   if(!root)
     return root=temp;
    node *current=root,*parent=NULL;
    while(current)
    {
     parent=current;
      if(current->data==data)
        {cout<<"\n Node is already present";return root;}
      if(current->data>data)
          current=current->left;
             //{if(!current) parent->left=temp;return root;}
      else
          current=current->right;
             //if(!current) parent->right=temp;return root;}
    }
   if(parent->data>data)
      {parent->left=temp;return root;}
    else
        {parent->right=temp;return root;}
}
bool leafNode(node *temp)
{
  if(!temp->left&&temp->right) return true;
  else return false;
}

bool haveSingle(node *temp)
{
   if((!root->left&&root->right)||(root->left&&!root->right))  return true;
   else return false;
}
bool haveTwo(node *temp)
{
  if(root->right&&root->left) return true;
  else return false;
}
node *successor(node *temp)
{
  temp=temp->right;
  while(temp) temp=temp->left;

  return temp;
}

node* BST::erase_BST(node *root,int data)
{
   node *temp;
   if(!root)
     return root=temp;
    node *current=root,*parent=NULL;
    while(current->data!=data||!current)
    {
     parent=current;

      if(current->data>data)
          current=current->left;
             //{if(!current) parent->left=temp;return root;}
      else
          current=current->right;
             //if(!current) parent->right=temp;return root;}
    }
    if(!current)
       {cout<<"Node is not present";return root;}


   if(leafNode(current))
      {if(current->data>parent->data)
          {parent->right=NULL;free(current);return root;}
        else
          {parent->left=NULL;free(current);return root;}
      }
   if(haveSingle(current))
    {if(current->data>parent->data)
      {if(current->left) {parent->right=current->left;free(current);return root;}
        else {parent->right=current->right;free(current);return root;}}
     else
       {if(current->left) {parent->left=current->left;free(current);return root;}
        else {parent->left=current->right;free(current);return root;}}
    }
    if(haveTwo(current))
    {
       node *tempp=successor(current);
         int x=tempp->data;tempp->data=current->data;current->data=x;
         current=erase_BST(current,data);
         return root;
    }
}

void BST::preorder(node * root)
{
  node *temp=root;
  if(!temp)
   return;
   cout<<" "<<root->data;
  preorder(temp->left);
  preorder(temp->right);

}

void BST::inorder(node * root)
{
  node *temp=root;
  if(!temp)
   return;

  inorder(temp->left);
  cout<<" "<<temp->data;
  inorder(temp->right);

}
void BST::postorder(node * root)
{
  node *temp=root;
  if(!temp)
   return;

  postorder(temp->left);
  postorder(temp->right);
  cout<<" "<<temp->data;
}

void BST::levelorder(node * root)
{
  node *current;

  if(!root)
   return;
 queue<node *> q;
 q.push(root);//q.push(NULL);
 while(!q.empty())
 {
   current=q.front();q.pop();
   //if(!current)
    //{q.push(NULL);cout<<"\n";}
   //if(current)
   //{
     cout<<current->data<<" ";
     if(current->left)
        q.push(current->left);
     if(current->right)
       q.push(current->right);
   //}
 }
}
int BST::height(node * root)
{
  node *temp=root;
  if(!temp)
   return 0;
  int lh=height(temp->left);
  int rh=height(temp->right);
  return 1+max(lh,rh);
}

int BST::leafNodes(node * root)
{
  node *temp=root;
  if(!temp)
   return 0;
  if(temp->data&&!temp->left&&!temp->right)
   return 1;

  int ln=leafNodes(temp->left);
  int rn=leafNodes(temp->right);
  return ln+rn;
}

int main()
{
 BST bst;
 root=bst.insert_BST(root,40);
 root=bst.insert_BST(root,20);
 root=bst.insert_BST(root,30);
 root=bst.insert_BST(root,10);
 root=bst.insert_BST(root,60);
 root=bst.insert_BST(root,50);
 root=bst.insert_BST(root,70);
 root=bst.insert_BST(root,40);
 cout<<"\nPreorder :";
 bst.preorder(root);
 cout<<"\nInorder:";
 bst.inorder(root);
 cout<<"\nPostorder:";
 bst.postorder(root);
 cout<<"\nLevelorder:";
 bst.levelorder(root);
 cout<<"\nHeight ="<<bst.height(root);
 cout<<"\nNo of Leafnodes="<<bst.leafNodes(root);
 bst.erase_BST(root,55);
 bst.erase_BST(root,70);
 cout<<"\nInorder:";
 bst.inorder(root);

 return 0;
}
