#ifndef STACK
#define STACK

#define MAXSTACK 100

typedef char StackEntry;


typedef struct{
    StackEntry entry[MAXSTACK];
    int top;
}Stack;

void CreateStack(Stack *ps);
void Push(Stack *ps, StackEntry e);
int StackFull(Stack *ps);
void Pop(Stack *ps, StackEntry *pe);
int StackEmpty(Stack *ps);
void StackTop(Stack *ps, StackEntry *pe);
int StackSize(Stack *ps);
void ClearStack(Stack *ps);
void TraverseStack(Stack *ps, void (*pf)(StackEntry e));



#endif // STACK
