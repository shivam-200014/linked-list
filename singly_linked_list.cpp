//first topic: linked list
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    //destructor
    ~node(){                                //ye destructor nahi samaj aa raha hai??????
        int value=this->data;
        //memory free
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data:"<<value<<endl;
    }
};
int size_of_list(node * &head)
{
    int size=0;
    //node *temp=new node;             
    //temp=head;
    node *temp=head;
    while(temp!=NULL)
    {
        size++;
        temp=temp->next;
    }
    return size;
}
void insert_at_head(int d,node* &head)
{
    //node *temp=new node;                  
    //temp->data=d;
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}
void insert_at_tail(int d,node* &tail)
{
    //node* temp=new node;                  
    //temp->data=d;
    //temp->next=NULL;
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
}
void insertAtPos(int pos,int d,node* &head,node* &tail)//it will work for any general position
{
    if(pos==1)
        insert_at_head(d,head);
    else{
        
        //node *temp1=new node;             
        //node *temp=new node;
        node *temp1,*temp;
        //node *middle=new node;             
        //middle->data=d;
        node *middle=new node(d);
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
    //node *temp=new node;                !!!
    //temp=head;
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void deleteAt(int pos,node* &head,node* &tail)
{
    //node* temp=new node;            !!!
    //temp=head;
    node* temp=head;
    if(pos==1)//memory free ??
    {
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        for(int i=1;i<pos-1;++i)
            temp=temp->next;
        //node* temp1=new node;       !!!
        //temp1=temp->next;
        node* temp1=temp->next;
        //node* temp2=new node;       !!!
        //temp2=temp1->next;
        node* temp2=temp1->next; 
        temp->next=temp2;
        temp1->next=NULL;
        delete temp1;
        if(temp2==NULL)
            tail=temp;
    }
}
int main()
{
    node *node1=new node(5);
    //node1->data=5;
    //node1->next=NULL;
    node *head,*tail;
    head=tail=node1;
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
    deleteAt(3,head,tail);
    print(head);
    deleteAt(1,head,tail);
    print(head);cout<<head->data<<" "<<tail->data<<endl;
    deleteAt(4,head,tail);
    print(head);cout<<head->data<<" "<<tail->data<<endl;
    cout<<"adress before delete:"<<head;
    delete head;
    cout<<"\t adress after delete:"<<head<<endl;
    cout<<head->data<<endl;
    cout<<head->next;
}
