/*student id:1702020
Name: Md. Asif Iqbal*/
#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#define mxn 1000000
using namespace std;
int size;
int *arr = (int*) malloc(mxn * sizeof(int));

char s[87678];
void view()
{
    int i;
    cout<<"your array is: ";
    for(i=1; i<=size; i++)
    {
        cout<<*(arr+i)<<" ";
    }
    cout<<"\n";
}

void newelement()
{
    int item, pos, i,*s;
    cout<<"Enter the ITEM to be inserted: ";
    cin>>item;
    cout<<"Enter position of ITEM: ";
    cin>>pos;
    for(i=size; i>=pos; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=item;
    s=&size;
    //size=&size+1;
    *s=*s+1;
    cout<<"Element added successfully and ";
    view();
}
void search()
{
    int item,loc=0,i=1;
    cout<<"Enter an ITEM to be searched: ";
    cin>>item;
    for(i=1; i<=size; i++)
    {
        if(arr[i]==item)
        {
            loc=i;
            cout<<item<<" is found in location "<<loc<<endl;
        }
    }
    if(loc==0)
    {
        cout<<"ITEM not found"<<endl;
    }
}
void del()
{
    int x=size;
    int item,loc=0,i=1,j,*s,ok=0;
    cout<<"Enter an ITEM to be deleted: ";
    cin>>item;
    for(i=1; i<=size; i++)
    {
        if(ok==1 && i!=1)
        {
            i--;
            ok=0;
        }
        if(arr[i]==item)
        {
            loc=i;
            for(j=loc; j<=size-1; j++)
            {
                arr[j]=arr[j+1];
            }
            size--;
            ok=1;
        }
    }
    if(loc==0)
    {
        cout<<"ITEM not found"<<endl;
    }
    else
    {
        cout<<"Element deleted successfully and ";
        view();
    }
}
void asort()
{
    int i,ptr,swap;
    for (i=1; i<=size-1; i++)
    {
        for (ptr=1; ptr<=size-i; ptr++)
        {
            if (arr[ptr]>arr[ptr+1])
            {
                swap=arr[ptr];
                arr[ptr]=arr[ptr+1];
                arr[ptr+1]=swap;
            }
        }
    }

    cout<<"After sorting in ascending order ";

    view();
}

void dsort()
{
    int i,ptr,swap;
    for (i=1; i<=size-1; i++)
    {
        for (ptr=1; ptr<=size-i; ptr++)
        {
            if (arr[ptr]<arr[ptr+1])
            {
                swap=arr[ptr];
                arr[ptr]=arr[ptr+1];
                arr[ptr+1]=swap;
            }
        }
    }

    cout<<"After sorting in descending order ";

    view();
}

void mem()
{
    int p,i,index,ad,loc;
    p=*arr+1;
    cout<<"Enter the index (N.B. index 1 means first element): ";
    cin>>index;
    index--;
    if(index>size)
    {
        cout<<"Index should be from 0 to size-1. So, your given index is invalid."<<endl;
    }
    else
    {
        ad=p+sizeof(int)*index;
        cout<<"The "<<index+1<<"th element is allocated in location "<<ad<<endl;
    }
}
void choose();
void more()
{
    int more;
    cout<<"Do you want to do perform more job? if YES, enter 1; otherwise enter 0: ";
    cin>>more;
    if(more==1)
    {
        system("cls");
        choose();
    }
    else
    {
        cout<<endl<<"THANK YOU";
        exit(0);
    }

}
void choose()
{
    int choice;
    cout<<"Enter your choice:\n";
    cout<<"1....View all elements\n";
    cout<<"2....Insert new element\n";
    cout<<"3....Search an element\n";
    cout<<"4....Delete an element\n";
    cout<<"5....Sort elements in ascending order\n";
    cout<<"6....Sort elements in descending order\n";
    cout<<"7....Find memory location of an element\n";
    cout<<"Enter a valid choice:";
    cin>>choice;
    while(1)
    {
        if(choice==1)
        {
            view();
            more();
        }
        else if(choice==2)
        {
            newelement();
            more();
        }
        else if(choice==3)
        {
            search();
            more();
        }
        else if(choice==4)
        {
            del();
            more();
        }
        else if(choice==5)
        {
            asort();
            more();
        }
        else if(choice==6)
        {
            dsort();
            more();
        }
        else if(choice==7)
        {
            mem();
            more();
        }
        else if(choice==0)
        {
            printf("INVALID CHOICE\n");
        }
    }
}

int main()
{
    int i,choice,decide,num=0;
    cout<<"Dear user, Firstly you are requested to give an array. \n";
    cout<<"Enter array size: ";
    cin>>size;
    cout<<"Enter array elements: ";
    for(i=1; i<=size; i++)
    {
        scanf("%d",arr+i);
    }
    cout<<"\nIf you want to see the job menu, enter any key; otherwise enter 0: ";
    cin>>decide;
    if(decide==0)
    {
        cout<<endl<<"THANK YOU";
        exit;
    }
    else
        choose();

}
