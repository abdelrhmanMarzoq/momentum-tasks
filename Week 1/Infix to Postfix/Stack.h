#ifndef STACK
#define STACK


#define MAXSTACK 4
typedef char StackEntry;

typedef struct stack{
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


#endif // STACK
