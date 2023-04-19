/*write a program which serch Last occurance of perticular elements from sigly linearlink list*/
//////////////////////////////////////////////////////////////////////////////
//
// Function Name :  SearchFirstOcc()  
// Description   :  Search Last Occurrence Of Particular Element From Singly Linear Linked List
// Input         :  Integer
// Output        :  Integer
// Author        :  Sushma Kawade
// Date          :  5 feb 2023
//
////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertATFirst(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));      

    newn->data = no;
    newn->next = NULL;

    if(*First == NULL) 
    {
        *First = newn;
    }
    else                
    {
        newn->next = *First;
        *First = newn;
    }
}

void Display(PNODE First)
{
    printf("Elements from the Linked List are : \n");

    while(First != NULL)
    {
        printf("| %d |-> ",First->data);
        First = First -> next;
    }
    printf("NULL \n");
}



int SearchLastOcc(PNODE First, int No)
{
    int iCnt = 0, Temp = 0; // counter, temperery container

    while(First != NULL) // travel till Next is NULL
    {
        iCnt++; // every time counter go to next time till No not found 100, 200 .... 600
        if(First -> data == No) // in 600 Node data is 30, so travel till 6 node
        {
            Temp = iCnt; // value of counter get store into tempery container
        }
        First = First -> next; // if 30 not found node -> Next
    }
    return Temp; // return the position of Temp to iRet in main
}


int main()
{
    PNODE Head = NULL;
    int iNo = 0,iRet = 0;
    InsertATFirst(&Head,70);
    InsertATFirst(&Head,30);
    InsertATFirst(&Head,50);
    InsertATFirst(&Head,40);
    InsertATFirst(&Head,30);
    InsertATFirst(&Head,20);
    InsertATFirst(&Head,10);
    printf("\nEnter element to search: ");
    scanf("%d", &iNo);
    iRet = SearchLastOcc(Head,iNo);
    Display(Head);
    printf("Found is : %d\n",iRet);
    return 0;
}
