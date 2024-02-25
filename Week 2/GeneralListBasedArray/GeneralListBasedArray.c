
#include "GeneralList.h"


void List_init(List *pl)
{
    pl->Size = 0;
}

boolean List_Empty(List *pl)
{
    return !(pl->Size);
}

boolean List_Full(List *pl)
{
    return (pl->Size == MAXELEMENT);
}

int List_Size(List *pl)
{
    return pl->Size;
}

void Destroy_List(List *pl)
{
    pl->Size = 0;
}

void Insert_List(List *pl, ListEntry e,int p)
{
    for (int i = pl->Size; i <= p; i--)
    {
        pl->entry[i] = pl->entry[i-1];
    }
    pl->entry[p] = e;
    pl->Size++;
}
void Delete_List(List *pl, ListEntry *pe,int p)
{
    *pe = pl->entry[p];
    for (int i = p+1; i <= pl->Size-1; i++)
    {
        pl->entry[i-1] = pl->entry[i];
    }
    pl->Size--;
}

void List_Retrieve(List *pl, ListEntry *pe,int p)
{
    *pe = pl->entry[p];
}

void List_Replace(List *pl, ListEntry e,int p)
{
    pl->entry[p] = e;
}
