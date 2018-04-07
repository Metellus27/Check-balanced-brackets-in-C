#include <stdio.h>
#include <stdlib.h>

typedef char stackType;

struct stack
{
    unsigned int index ;
    unsigned int capacity;
    stackType array[1000];
};


//
// very simple Stack operations
//

typedef struct stack stack;
void push(stack*,stackType);
stackType pop(stack*);
char isEmpty(stack*);

//
//Balanced brackets functions
//

char isBalanced(char*);


int main()
{

    char *s = " if() else {}";
    if(isBalanced(s)) printf("Balanced");
    else printf("Not");

    return 0;
}


void push(stack *mys, stackType element)
{
    if(mys->index < mys->capacity) mys->array[mys->index++] = element;
}

stackType pop(stack* mys)
{
    if(!isEmpty(mys)) return mys->array[--mys->index];
}


char isEmpty(stack* mys)
{
    if(mys->index == 0 ) return 1;
    else return 0;
}


char isBalanced(char *st)
{
    stack temp;
    temp.capacity = 10;
    temp.index = 0;

    char tmpChar;
    unsigned int i =0;
    while(st[i] != '\0')
    {

        if(st[i] =='{' || st[i] == '[' || st[i] == '(') push(&temp,st[i]); //open bracket detected

        if(st[i] =='}' || st[i] == ']' || st[i] == ')') //closed bracket detected
        {
            if(isEmpty(&temp)) return 0; //no open bracket for the closed bracket, not balanced
            else
            {
                tmpChar = pop(&temp);
                if(
                   st[i] == ']' && tmpChar !='[' ||
                   st[i] == '}' && tmpChar !='{' ||
                   st[i] == ')' && tmpChar !='('
                    )
                return 0;  //not balanced
            }
        }
        i++; //increment the loop
    }
    if(isEmpty(&temp)) return 1; // if there are no remaining open brackets
    else return 0;
}
