#include <iostream>
using namespace std;
struct Node{
int data;
Node *link;
};
Node *swap(Node *ptr1,Node* ptr2)
{
 Node *tmp=ptr2->link;
 ptr2->link=ptr1;
 ptr1->link=tmp;
 return ptr2;
}
void bubbleSort(Node **head,int count)
{
 int i,j;
 bool swapped;
 Node **h;
 for(i=0;i<=count;i++)
{
 swapped=false;
 h=head;
 for(j=0;j<count-i-1;j++)
{
 Node *p1=*h;
 Node *p2=p1->link;
 if(p1->data>p2->data)
{
 *h=swap(p1,p2);
  swapped=true;
}
h=&(*h)->link;
}
if(!swapped) break;
}
}

class List{
Node *first,*last;
int size;
public:
  List()
{ 
first=last=NULL;
size=0;
}
  List(const List& l)
{
  if(l.first)
{
  Node *cur,*temp=l.first;
  cur=first=new Node;
  size=l.size;
  while(temp->link)
{
  cur->data=temp->data;
  cur->link=new Node;
  temp=temp->link;
  cur=cur->link;
}
 cur->data=temp->data;
 cur->link=NULL;
 last=cur;
}
else 
{
first=last=NULL;
size=0;
}
}
void add_end(int a)
{
  if(first)
{
  last->link=new Node;
  last=last->link;
  last->data=a;
  last->link=NULL;
}
 else
  {
   last=first=new Node;
   last->data=a;
   last->link=NULL;
  }
  size++;
}
void add_front(int a)
{
 if(first)
{
  Node *p=new Node;
  p->data=a;
  p->link=first;
  first=p;
  }
else
 {
   last=first=new Node;
   last->data=a;
   last->link=NULL;
  }
  size++;
}
 ~List()
{
 Node *cur;
  while(first)
{
cur=first;
 first=first->link;
 delete cur;
}
last=first=NULL;
}
void reverse()
{
 Node *cur=first;
 Node *next=NULL,*prev=NULL;
 last=first;
while(cur)
{
 next=cur->link;
 cur->link=prev;
 prev=cur;
 cur=next;
}
first=prev;
}
 void sort()
{
  bubbleSort(&first,size);
}
void print()
{
	Node *cur=first;
	while(cur)
	{
		cout<<cur->data<<' ';
		cur=cur->link;
	}
	cout<<endl;
}
};
int main()
{
	List l1;
	for(int i=0;i<5;i++)
	l1.add_end(i);
	l1.print();
	l1.reverse();
	l1.print();
	
	List l2;
	l2.add_end(5);
	l2.add_end(1);
	l2.add_end(4);
	l2.add_front(6);
	l2.print();
	l2.sort();
	l2.print();
	return 0;
}
