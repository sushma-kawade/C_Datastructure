/*write a program which display all elementc which are perfect from sigly linearlink list*/
//////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DisplayPerfect()  
// Description   :  find perfect number From Singly Linear Linked List
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

void DisplayPerfect(PNODE First)
{

    int iNo = 0, iCnt = 0; // 2 Variables gatle for % and + sathi

    while(First != NULL)
    {
        iNo = 0; // after every travelser th value of iNo is initialize to 0

//      initilize to 1,    icnt < 11,28,17,     100,200,300...600  
        for(iCnt = 1; iCnt < First -> data; iCnt++) 
        {
            if(First -> data % iCnt == 0) // 1 * 2 * 3 = 6 , 1 + 2 + 4 + 7 + 14 = 28
            {
                iNo = iNo + iCnt; // 1 + 2 + 3 = 6
            }
        }
        if(First -> data == iNo) // in iNo 6, 28 is stored
        {
            printf("%d\t", iNo); // display the value
        }
        First = First -> next; // if value is not found ++
    }
}


int main()
{
    PNODE Head = NULL;
    int iNo = 0,iRet = 0;

    InsertATFirst(&Head,89);
    InsertATFirst(&Head,6);
    InsertATFirst(&Head,41);
    InsertATFirst(&Head,17);
    InsertATFirst(&Head,28);
    InsertATFirst(&Head,11);
    Display(Head);
    DisplayPerfect(Head);

    return 0;
}
