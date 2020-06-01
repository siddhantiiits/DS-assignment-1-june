#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head;

void createnode(int n)
{
 head=(struct node *)malloc(sizeof(struct node));
 int data;
 printf("Enter head data=");
 scanf("%d",&data);
 head->data=data;
 head->link=NULL;
 struct node *temp=(struct node *)malloc(sizeof(struct node));
 temp=head;
 struct node *newnode;
 for(int a=0;a<n-1;a++)
 {
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter node data=");
  scanf("%d",&data);
  newnode->data=data;
  newnode->link=NULL;
  temp->link=newnode;
  temp=temp->link;
 }
}

void traverse()
{
 struct node *temp=(struct node *)malloc(sizeof(struct node));
 temp=head;
 while(temp)
 {
  printf("Data you entered=%d\n",temp->data);
  temp=temp->link;
 }
}

void main()
{
  int n;
  printf("No.of elements: ");
  scanf("%d",&n);
  createnode(n);
  printf("\nData you entered\n\n");
  traverse();
  int p;
  for(struct node *temp=head;temp->link!=NULL;temp=temp->link)
  {
   for(struct node *t=head;t->link!=NULL;t=t->link)
   {
      if(t->data>t->link->data)
      {
          p=t->data;
          t->data=t->link->data;
          t->link->data=p;
      }
    }
  }
  printf("\nSorted:\n\n");
  traverse();
}
