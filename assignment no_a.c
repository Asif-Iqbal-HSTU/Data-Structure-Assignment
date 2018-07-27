/*student id:1702020
Name: Md. Asif Iqbal*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mxn 1000000

int *arr;
int view(int size,int arr[size])
{
    int i;
    printf("your array is: ");
    for(i=1; i<=size; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

int newelement(int size,int arr[size])
{
    int item, pos, i,*s;
    printf("Enter the ITEM to be inserted: ");
    scanf("%d",&item);
    printf("Enter position of ITEM: ");
    scanf("%d",&pos);
    for(i=size; i>=pos; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=item;
    size=size+1;
    printf("Element added successfully and ");
    view(size,arr);
    return size;
}
void search(int size,int arr[size])
{
    int item,loc=0,i=1;
    printf("Enter an ITEM to be searched: ");
    scanf("%d",&item);
    for(i=1; i<=size; i++)
    {
        if(arr[i]==item)
        {
            loc=i;
            printf("%d is found in location %d\n",item,loc);
        }
    }
    if(loc==0)
    {
        printf("ITEM not found\n");
    }
}
int del(int size,int arr[size])
{
    int x=size;
    int item,loc=0,i=1,j,*s,ok=0;
    printf("Enter an ITEM to be deleted: ");
    scanf("%d",&item);
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
            size=size-1;
            ok=1;
        }
    }
    if(loc==0)
    {
        printf("ITEM not found\n");
    }
    else
    {
        printf("Element deleted successfully and ");
        view(size,arr);
        return size;
    }
}
void asort(int size,int arr[size])
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

    printf("After sorting in ascending order ");

    view(size,arr);
}

void dsort(int size,int arr[size])
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
    printf("After sorting in descending order ");
    view(size,arr);
}

void mem(int size,int arr[size])
{
    int p,i,index,ad,loc;
    p=arr+1;
    printf("Enter the index (N.B. index 1 means first element): ");
    scanf("%d",&index);
    index--;
    if(index>size)
    {
        printf("Index should be from 0 to size-1. So, your given index is invalid.\n");
    }
    else
    {
        ad=p+sizeof(int)*index;
        printf("The %dth element is allocated in location %d\n",index+1,ad);
    }
}
void choose(int size,int arr[size])
{
    int choice;
    printf("Enter your choice:\n");
    printf("1....View all elements\n");
    printf("2....Insert new element\n");
    printf("3....Search an element\n");
    printf("4....Delete an element\n");
    printf("5....Sort elements in ascending order\n");
    printf("6....Sort elements in descending order\n");
    printf("7....Find memory location of an element\n");
    printf("Enter a valid choice:");
    while(1)
    {
        scanf("%d",&choice);
        if(choice==1)
        {
            view(size,arr);
            more(size,arr);
        }
        else if(choice==2)
        {
            size=newelement(size,arr);
            more(size,arr);

        }
        else if(choice==3)
        {
            search(size,arr);
            more(size,arr);
        }
        else if(choice==4)
        {
            size=del(size,arr);
            more(size,arr);
        }
        else if(choice==5)
        {
            asort(size,arr);
            more(size,arr);
        }
        else if(choice==6)
        {
            dsort(size,arr);
            more(size,arr);
        }
        else if(choice==7)
        {
            mem(size,arr);
            more(size,arr);
        }
        else if(choice==0)
        {
            printf("INVALID CHOICE\n");
        }
    }
}
void more(int size,int arr[size])
{
    int more;
    printf("\nDo you want to do perform more job? if YES, enter 1; otherwise enter 0: ");
    scanf("%d",&more);
    if(more==1)
    {
        system("cls");
        choose(size,arr);
    }
    else
    {
        printf("\n\n\tTHANK YOU");
        exit(0);
    }
}
int main()
{
    int size,i,choice,*arr,decide,ele,num=0;
    printf("Dear user, Firstly you are requested to give an array. \n");
    printf("Enter array size: ");
    scanf("%d",&size);
    arr = (int*) malloc(mxn * sizeof(int));
    printf("Enter array elements: ");
    for(i=1; i<=size; i++)
    {
        scanf("%d",arr+i);
    }
    printf("\nDear user, you can do some jobs with your array.. \n");
    printf("If you want to see the job menu, enter any key; otherwise enter 0: ");
    scanf("%d",&decide);
    if(decide==0)
    {
        printf("\n\n\tTHANK YOU");
        exit;
    }
    else
        choose(size,arr);

    return 0;
}
