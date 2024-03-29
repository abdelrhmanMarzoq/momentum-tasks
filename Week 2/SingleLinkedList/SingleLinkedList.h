#ifndef LINKED_LIST
#define LINKED_LIST

typedef char boolean;

typedef struct node{
    unsigned int NodeData;
    struct node *NodeLink;
}Node;

typedef struct{
    unsigned int Size;
    Node *ListHead;
}List;




void Init_List (List *pl);

boolean Insert_Node_In_List(List *pl, int data, unsigned int pos);

void Destroy_List(List *pl);

boolean Empty_List(List *pl);

boolean Full_List(List *pl);

boolean List_Retrieve(List *pl, int *pe, unsigned int pos);

boolean List_Replace(List *pl, int e, unsigned int pos);

boolean List_Delete(List *pl, int *pe, unsigned int pos);

int Size_List(List *pl);

void List_Traverse(List *pl, void (*Visit)(int));







#endif // LINKED_LIST
