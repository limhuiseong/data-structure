#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init_queue(Queue* queue)
{
    queue -> front = 0;
    queue -> rear = 0;
}

int is_empty(Queue* queue)
{
    return queue -> front == queue -> rear;
}

int is_full(Queue* queue)
{
    return (queue -> rear + 1) % MAX_SIZE == queue -> front;
}

void enqueue(Queue* queue, int value)
{
    if(!is_full(queue))
    {
        queue -> data[queue -> rear] = value;
        queue -> rear = (queue -> rear + 1) % MAX_SIZE;
    }
}

int dequeue(Queue* queue)
{
    if (!is_empty(queue))
    {
        int value = queue -> data[queue -> front];
        queue -> front = (queue -> front + 1) % MAX_SIZE;
        return value;
    }
}

void print(Queue* queue)
{
    int i = queue -> front;
    while (i != queue -> rear)
    {
        printf("%d ", queue -> data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main()
{
    Queue queue;
    init_queue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 23);

    print(&queue);

    dequeue(&queue);

    print(&queue);

    return 0;
}