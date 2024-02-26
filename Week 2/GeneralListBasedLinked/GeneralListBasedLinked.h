#ifndef GENERAL_LIST
#define GENERAL_LIST

typedef char boolean;

typedef ListEntry;  //UserDefined

typedef struct listNode{
    ListEntry entry;
    struct listNode *next;
}ListNode;

typedef struct {
    ListNode *head;
    int Size;
}List;

void List_init(List *pl);

boolean List_Empty(List *pl);

boolean List_Full(List *pl);

int List_Size(List *pl);

void Destroy_List(List *pl);

boolean List_Insert(List *pl, ListEntry e,int pos);

void List_Delete(List *pl, ListEntry *pe,int pos);

void List_Retrieve(List *pl, ListEntry *pe,int pos);

void List_Replace(List *pl, ListEntry e,int pos);

#endif // GENERAL_LIST
