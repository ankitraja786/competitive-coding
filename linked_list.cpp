#include<bits/stdc++.h>
using namespace std;

struct node
{
 int  number;
 node* next;
};
node* insert(int t,node* b)
{
 node* x=new node;
 x->number=t;
 x->next=NULL;
return x;
}

void deleteit(int t,node* start)
{
 start=start->next;
 node* pre=new node;
 node* i=new node;
 pre=start;
 i=pre->next;
 for(;i!=NULL;i=i->next)
{
 if(i->number==t)
  {
    pre->next=i->next;
  }
  pre=pre->next;
}
}

void traverse(node* start)
{
 start=start->next;
 node* i=new node;
 i=start->next;
   // cout<<i->number<<endl;
 for(;i!=NULL;i=i->next)
 {
  cout<<i->number<<" ";
 }
}

int main()
{
 struct node* start=new node;
 struct node* head=new node;
 start->next=head;
head->next=NULL;
  while(true)
 {
  cout<<endl;
  cout<<"1 for inset a element"<<endl;
  cout<<"2 for delete a element"<<endl;
  cout<<"3 for list showing"<<endl;
  cout<<"4 for exit"<<endl;
  int x,t;
  cin>>x;
  switch(x)
  {
   case 1:
    cout<<"give a number: ";
    cin>>t;
    head->next=insert(t,head);
    head=head->next;
    break;

   case 2:
    cout<<"enter the number you want to delete: ";
    cin>>t;
    deleteit(t,start);
    break;

   case 3:
     traverse(start);
     break;

   case 4:
     return 0;
  }
 }
}