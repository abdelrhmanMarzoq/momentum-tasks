#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

#define MAX_ARRAY 100

void Infix_To_Post(Stack *ps, StackEntry *pe);
int precedence(char sympol);

char infix[MAX_ARRAY];
char Post[MAX_ARRAY];

int main() {
    printf("Please Enter infix expression  -->  ");
    gets(infix);

    // Creating Stack
    Stack s;
    StackEntry e;
    CreateStack(&s);


    Infix_To_Post(&s, &e);
    printf("%s",Post);

    return 0;
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
                    Push(ps, sympol); break;
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
                        if(!StackEmpty(ps)) StackTop(ps, pe);
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
    Post[j] = '\0';
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
