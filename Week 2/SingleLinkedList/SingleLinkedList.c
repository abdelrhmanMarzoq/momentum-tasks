#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void Init_List (List *pl)
{
    pl->ListHead = NULL;
    pl->Size = 0;
}

boolean Insert_Node_In_List(List *pl, int data, unsigned int pos)
{
    Node *New;
    New = (Node *)malloc(sizeof(Node));
    int i;

    Node *TempNode = NULL;

    if (NULL != New && pos >=0 && pos <= pl->Size)
    {
        New->NodeData = data;
        if(pos == 0)
        {
            New->NodeLink = pl->ListHead;
            pl->ListHead = New;
        }
        else
        {
            for(TempNode = pl->ListHead, i = 0; i < pos-1; i++)
            {
                TempNode = TempNode->NodeLink;
            }
            New->NodeLink = TempNode->NodeLink;
            TempNode->NodeLink = New;
        }
        pl->Size++;
        return 1;
    }
    else{
        return 0;
    }
}

boolean List_Delete(List *pl, int *pe, unsigned int pos)
{
    Node *TempNode;
    Node *FreeNode;
    int i;

    if (pos >= 0 && pos < pl->Size)
    {
        if (pos == 0)
        {
            *pe = pl->ListHead->NodeData;
            FreeNode = pl->ListHead;
            pl->ListHead = pl->ListHead->NodeLink;
            free(FreeNode);
        }
        else
        {
            for (TempNode = pl->ListHead, i = 0; i <(pos-1); i++)
            {
                TempNode = TempNode->NodeLink;
            }
            FreeNode = TempNode->NodeLink;
            TempNode->NodeLink = FreeNode->NodeLink;
            *pe = FreeNode->NodeData;
            free(FreeNode);
        }
        pl->Size--;
        return 1;
    }
    else
    {
        return 0;
    }


}

boolean List_Retrieve(List *pl, int *pe, unsigned int pos)
{
    Node *TempNode;
    int i;
    if (pos >= 0 && pos < pl->Size)
    {
        for (TempNode = pl->ListHead, i = 0; i < pos; i++)
        {
            TempNode = TempNode->NodeLink;
        }
        *pe = TempNode->NodeData;
        return 1;
    }
    else
    {
        return 0;
    }
}

boolean List_Replace(List *pl, int e, unsigned int pos)
{
    Node *TempNode;
    int i;
    if (pos >= 0 && pos < pl->Size)
    {
        for (TempNode = pl->ListHead, i = 0; i < pos; i++)
        {
            TempNode = TempNode->NodeLink;
        }
        TempNode->NodeData = e;
        return 1;
    }
    else
    {
        return 0;
    }

}

void Destroy_List(List *pl)
{
    Node *TempNode;

    for (int i = 0; i < pl->Size; i++)
    {
        TempNode = pl->ListHead;
        pl->ListHead = pl->ListHead->NodeLink;
        free(TempNode);
    }
    pl->Size = 0;
}

boolean List_Full(List *pl)
{
    return 0;
}

boolean Empty_List(List *pl)
{
    return !(pl->ListHead);
}

int Size_List(List *pl)
{
    return pl->Size;
}


void List_Traverse(List *pl, void (*Visit)(int))
{
    Node *Traverse = pl->ListHead;
    if (Traverse != NULL)
    {
        while(Traverse != NULL)
        {
            Visit(Traverse->NodeData);
            Traverse = Traverse->NodeLink;
        }
    }
    else
    {
    }
}
