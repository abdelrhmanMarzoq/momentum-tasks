#include "GeneralListBasedLinked.h"
#include <stdio.h>
#include <stdlib.h>


void List_init(List *pl)
{
    pl->head = NULL;
    pl->Size = 0;
}

boolean List_Empty(List *pl)
{
    return !(pl->head);
}

boolean List_Full(List *pl)
{
    return 0;
}

int List_Size(List *pl)
{
    return pl->Size;
}

void Destroy_List(List *pl)
{
    ListNode *pn;
    for (int i = 0; i < pl->Size; i++)
    {
        pn = pl->head;
        pl->head = pl->head->next;
        free(pn);
    }
    pl->Size = 0;
}

void List_Insert(List *pl, ListEntry e, int pos)
{
    ListNode *pq, *q;
    int i;
    pq = (ListNode *)malloc(sizeof(ListNode));
    if (NULL != pq && pos>=0 && pos<=pl->Size)
    {
        pq->entry = e;
        pq->next = NULL;
        if (pos == 0)
        {
            pq->next = pl->head;
            pl->head = pq;
        }
        else
        {
            for(q = pl->head,i = 0; i < (pos-1); i++)
            {
                q = q->next;
            }
            pq->next = q->next;
            q->next = pq;
        }
        pl->Size++;

    }
    else
    {

    }
}

boolean List_Delete(List *pl, ListEntry *pe,int pos)
{
    ListNode *temp, *q;
    int i;
    if(pos>=0 && pos<pl->Size)
    {
        if (pos == 0)
        {
            *pe = pl->head->entry;
            temp = pl->head;
            pl->head = pl->head->next;
            free(temp);
        }
        else
        {
            for (q = pl->head,i = 0; i < (pos-1); i++)
            {
                q = q->next;
            }
            temp = q->next;
            q->next = temp->next;
            *pe = temp->entry;
            free(temp);
        }

        pl->Size--;
    }
}

void List_Retrieve(List *pl, ListEntry *pe,int pos)
{
    ListNode *q;
    int i;
    if(pos>=0 && pos<pl->Size)
    {
        for (q = pl->head, i = 0; i < pos; i++)
        {
            q = q->next;
        }
        *pe = q->entry;
    }
}

void List_Replace(List *pl, ListEntry e,int pos)
{
    ListNode *q;
    int i;
    if (pos>=0 && pos<pl->Size)
    for (q = pl->head, i = 0; i < pos; i++)
    {
        q = q->next;
    }
    q->entry = e;
}
