#include "Stack.h"

void CreateStack(Stack *ps)
{
    ps->top = 0;
}

void Push(Stack *ps, StackEntry e)
{
    ps->entry[ps->top++] = e;
}

void Pop(Stack *ps, StackEntry *pe)
{
    ps->top--;
    *pe = ps->entry[ps->top];
}

int StackFull(Stack *ps)
{
    return (ps->top >= MAXSTACK);
}

int StackEmpty(Stack *ps)
{
    return !(ps->top);
}

void StackTop(Stack *ps, StackEntry *pe)
{
    *pe = ps->entry[ps->top-1];
}

int StackSize(Stack *ps)
{
    return ps->top;
}

void ClearStack(Stack *ps)
{
    ps->top = 0;
}
void TraverseStack(Stack *ps, void (*pf)(StackEntry))
{
    for(int i = ps->top; i < 0; i--)
    {
        (*pf)(ps->entry[(i-1)]);
    }
}




