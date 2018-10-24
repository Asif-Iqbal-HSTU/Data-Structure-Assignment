#include<bits/stdc++.h>

using namespace std;

struct  node
{
    int data;
    node *next;
};

class List
{
private:
    node *head,*tail;
public:
    List()
    {
        head=NULL;
        tail=NULL;
    }
    void createnode(int value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    void display()
    {
        node *temp=new node;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void searching(int value)
    {
        node *temp=new node;
        node *t=new node;
        temp=head;
        while(temp!=NULL)
        {
            if(temp->data==value)
            {
                cout<<value<<" is in the list and the location is "<<temp->next-1;
                return;
            }
            else
            {
                temp=temp->next;
            }

        }
        cout<<"Item not found";

    }
    void Delete(int n)
    {
        node *temp = head, *prev = head;

        while(temp != NULL)
        {
            if(temp->data == n)
            {
                if(temp == head)
                    head = temp->next;
                else
                    prev->next = temp->next;
                delete temp;
                cout<<"\n"<<n<<" is successfully deleted from the list!"<<endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout<<"\n"<<n<<" is not present in the list. So deletion is not possible!"<<endl;
    }
};


int main()
{
    int i,n,a,s,c,d;
    List l;
    cout<<"Start with entering some elements in the list\n";
    cout<<"Enter number of element: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(i=0; i<n; i++)
    {
        cin>>a;
        l.createnode(a);
    }
    cout<<"The List is: ";
    l.display();
block:
    {
        cout<<"\nCHOICE LIST:\n1.Insertion \n2.Searching \n3.Delete \n0.Exit\nEnter choice: ";
        cin>>c;
        if(c==1)
        {
            cout<<"Enter Item to be inserted: ";
            cin>>a;
            l.createnode(a);
            cout<<"Now the list is: ";
            l.display();
            goto block;
        }
        else if(c==2)
        {
            cout<<"Enter item to be search: ";
            cin>>s;
            l.searching(s);
            goto block;
        }
        else if(c==3)
        {
            cout<<"Enter item to be deleted: ";
            cin>>d;
            l.Delete(d);
            cout<<"Now the list is: ";
            l.display();
            goto block;
        }
        else if(c==0)
        {
            exit(0);
        }
        else
        {
            cout<<"Invalid choice!!\n";
            goto block;
        }
    }
}
