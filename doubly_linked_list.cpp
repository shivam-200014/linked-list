#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* pre;
    node* next;
    node(int data)
    {
        this->data=data;
        this->pre=NULL;
        this->next=NULL;
    }
};
void ins_at_tail(int data,node* & tail)
{
    node* temp=new node(data);
    temp->pre=tail;
    tail->next=temp;
    tail=temp;
}
void ins_at_head(int data,node* &head)
{
    node* temp=new node(data);
    temp->next=head;
    head->pre=temp;
    head=temp;
}
void ins_at_pos(int pos,int data,node* &head,node* &tail)
{
    if(pos==1)
    {
        ins_at_head(data,head);
    }
    else{
        node* mid=new node(data);
        node* temp=head;
        for(int i=1;i<pos-1;++i)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            ins_at_tail(data,tail);
        }
        else{
            node* temp1=temp->next;
            temp->next=mid;
            mid->pre=temp;
            mid->next=temp1;
            temp1->pre=mid;

        }

    }
}
void deleteAt(int pos,node* &head,node* &tail)
{
    if(pos==1)
    {
        node* temp=head;
        head=head->next;
        temp->next=NULL;//required??
        delete temp;
    }
    else{
        node* temp=head;
        for(int i=1;i<pos;++i)
        {
            temp=temp->next;
        }
        node*temp1=temp->pre;
        node* temp2=temp->next;
        if(temp->next==NULL)
        {
            
            temp1->next=NULL;
            temp->pre=NULL;
            delete temp;
            tail=temp1;
        }
        else{
            temp1->next=temp2;
            temp2->pre=temp1;
            temp->next=NULL;
            temp->pre=NULL;
            delete temp;
        }
    }
}
void print(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node *head=new node(5);
    node *tail=head;
    ins_at_pos(2,10,head,tail);
    print(head);
    ins_at_pos(3,15,head,tail);
    print(head);
    ins_at_pos(1,0,head,tail);
    print(head);
    ins_at_pos(5,20,head,tail);
    print(head);
    ins_at_pos(4,12,head,tail);
    print(head);
    deleteAt(1,head,tail);
    print(head);
    deleteAt(3,head,tail);
    print(head);
    deleteAt(4,head,tail);
    print(head);
    cout<<head->data<<"\t"<<tail->data<<endl;

}
