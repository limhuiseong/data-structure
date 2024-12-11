#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack* stack)
{
    stack -> top = -1;
}

int is_empty(Stack* stack)
{
    return stack -> top == -1;
}

int is_full(Stack* stack)
{
    return stack -> top == MAX_SIZE - 1;
}

void push(Stack* stack, int value)
{
    if (!is_full(stack))
        stack -> data[++(stack -> top)] = value;
}

int pop(Stack* stack)
{
    if (!is_empty(stack))
        return stack -> data[(stack -> top)--];
}

int top(Stack* stack)
{
    if (!is_empty(stack))
        return stack -> data[stack -> top];
}

void print(Stack* stack)
{
    for (int i = stack -> top; i >= 0; i--)
    {
        printf("%3d. %d\n", i, stack -> data[i]);
    }
    printf("\n");
}

int main()
{
    Stack stack;
    
    init_stack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 5);
    print(&stack);

    pop(&stack);
    print(&stack);

    pop(&stack);
    print(&stack);

    pop(&stack);
    print(&stack);

    return 0;
}