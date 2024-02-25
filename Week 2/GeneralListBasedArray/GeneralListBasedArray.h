#ifndef GENERAL_LIST
#define GENERAL_LIST

#define MAXELEMENT 100    //UserDefined


typedef char boolean;
typedef int ListEntry;    //UserDefined

typedef struct{
    ListEntry entry[MAXELEMENT];
    int Size;

}List;



void List_init(List *pl);

boolean List_Empty(List *pl);

boolean List_Full(List *pl);

int List_Size(List *pl);

void Destroy_List(List *pl);

void Insert_List(List *pl, ListEntry e,int p);

void Delete_List(List *pl, ListEntry *pe,int p);

void List_Retrieve(List *pl, ListEntry *pe,int p);
`
void List_Replace(List *pl, ListEntry e,int p);





#endif // GeneralList
