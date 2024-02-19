#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

#define MAX_ARRAY 100
void ReverseArray(char const*x);
void Infix_To_Post(Stack *ps, StackEntry *pe);
void Infix_To_Prefix(void);
int precedence(char sympol);

int counter;
char infix[MAX_ARRAY];
char Post[MAX_ARRAY];
char Prefix[MAX_ARRAY];

int main() {
    printf("Please Enter infix expression  -->  ");
    gets(infix);

    // Creating Stack
    Stack s;
    StackEntry e;
    CreateStack(&s);

    ReverseArray(&infix);
    printf("%s \n",infix);

    Infix_To_Post(&s, &e);
    printf("%s",Post);

    return 0;
}

void ReverseArray(char const*x)
{
    char *y = x;
    Stack s;
    StackEntry i;
    CreateStack(&s);

    while(*y != 0)
    {
        Push(&s, *y);
        y++;
    }
    y = x;
    while(!StackEmpty(&s))
    {
        Pop(&s, &i);
        *y = i;
        y++;
    }

}

void Infix_To_Post(Stack *ps, StackEntry *pe)
{
    int j = 0;
    char sympol;
    for(int i = 0; i<strlen(infix); i++)
    {
        sympol = infix[i];
        if(sympol != ' ' && sympol != '\t')
        {

            switch(sympol)
            {
                case '(' :
                    Push(ps, sympol);
                    counter ++;
                    break;
                case ')' :
                    Pop(ps , pe);
                    while(*pe != '(')
                    {
                        Post[j++] = *pe;
                        Pop(ps,pe);
                    }
                    break;
                case '+' :
                case '-' :
                case '*' :
                case '/' :
                case '^' :
                    StackTop(ps, pe);
                    while(!StackEmpty(ps) && precedence(*pe) >= precedence(sympol))
                    {
                        Pop(ps, pe);
                        Post[j++] = *pe;
                    }
                    Push(ps, sympol);
                    break;

                default :
                    Post[j++] = sympol;
            }
        }
    }
    while(!StackEmpty(ps))
    {
        Pop(ps, pe);
        Post[j++] = *pe;
    }
    ReverseArray(Post);
}


int precedence(char sympol)
{
    switch(sympol)
    {
        case '^' : return 3;
        case '*' :
        case '/' : return 2;
        case '+' :
        case '-' : return 1;
        default  : return 0;
    }
}


