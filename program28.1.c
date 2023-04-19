/*write a program which serch first occurance of perticular elements from sigly linearlink list*/
//////////////////////////////////////////////////////////////////////////////
//
// Function Name :  SearchFirstOcc()  
// Description   :  Search First Occurrence Of Particular Element From Singly Linear Linked List
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


int SerchOccuranceFirst(PNODE First,int iNo)
{
    int iCnt = 0; // counter gatla
    while(First != NULL)
    {
        iCnt++; // counter++ 100, 200, 300
        if(First -> data == iNo) // 30 ha data 3 node madhe sapadla 
        {
            break;
        }
        First = First -> next; // jar 30 ha nehi sapadla node ++
    }
    return iCnt;
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
    iRet = SerchOccuranceFirst(Head,iNo);
    Display(Head);
    printf("Found is : %d\n",iRet);
    return 0;
}
