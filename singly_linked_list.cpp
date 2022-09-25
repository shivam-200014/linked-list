//first topic: linked list
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};
int size_of_list(node * &head)
{
    int size=0;
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
        size++;
        temp=temp->next;
    }
    return size;
}
void insert_at_head(int d,node* &head)
{
    node *temp=new node;
    temp->data=d;
    temp->next=head;
    head=temp;
}
void insert_at_tail(int d,node* &tail)
{
    node* temp=new node;
    temp->data=d;
    temp->next=NULL;
    tail->next=temp;
    tail=temp;
}
void insertAtPos(int pos,int d,node* &head,node* &tail)//it will work for any general position
{
    if(pos==1)
        insert_at_head(d,head);
    else{
        
        node *temp1=new node;
        node *temp=new node;
        node *middle=new node;
        middle->data=d;
        temp=head;
        for(int i=1;i<=pos-2;++i)
            temp=temp->next;
        temp1=temp->next;
        middle->next=temp1;
        temp->next=middle;
        if(temp1==NULL)
            tail=middle;//updating tail if node added at last pos,else no requirment
    }
}
void print(node* &head)//traversing singly linked list
{
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node *node1=new node;
    node *head,*tail;
    head=tail=node1;
    node1->data=5;
    node1->next=NULL;
    insertAtPos(2,10,head,tail);
    print(head);
    insertAtPos(3,15,head,tail);
    print(head);
    insertAtPos(1,0,head,tail);
    print(head);
    insertAtPos(3,12,head,tail);
    print(head);
    insertAtPos(6,20,head,tail);
    print(head);


}