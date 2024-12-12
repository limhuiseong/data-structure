#include <iostream>

template <typename T>
class Stack
{
private:
    static const int MAX_SIZE = 100;
    T data[MAX_SIZE];
    int top;

public:
    Stack(): top(-1) {}

    bool is_empty() const 
    {
        return top == -1;
    }

    bool is_full() const
    {
        return top == MAX_SIZE - 1;
    }

    void push(const T& value)
    {
        if (!is_full())
            data[++top] = value;
    }

    T pop()
    {
        if (!is_empty())
            return data[top--];
    }

    void print() const
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%3d. %d\n", i, data[i]);
        }
        printf("\n");
    }
};

int main()
{
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(11);

    stack.print();

    stack.pop();

    stack.print();

    return 0;
}