#include <bits/stdc++.h>
using namespace std;

struct Queue {
    int *arr;
    int front, rear, size, capacity;
};

Queue* createQueue(int capacity)
{
    Queue *q = new Queue;
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->arr = new int[capacity];
    return q;
}

void resize(Queue *q)
{
    int newCap = q->capacity * 2;
    int *newArr = new int[newCap];

    for (int i = 0; i < q->size; i++)
        newArr[i] = q->arr[(q->front + i) % q->capacity];

    delete[] q->arr;
    q->arr = newArr;
    q->capacity = newCap;
    q->front = 0;
    q->rear = q->size - 1;
}

void enqueue(Queue *q, int value)
{
    if (q->size == q->capacity)
        resize(q);

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
}

int dequeue(Queue *q)
{
    if (q->size == 0)
        return -1;

    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

int peek(Queue *q)
{
    if (q->size == 0)
        return -1;
    return q->arr[q->front];
}

void printQueue(Queue *q)
{
    for (int i = 0; i < q->size; i++) {
        if (i) cout << ",";
        cout << q->arr[(q->front + i) % q->capacity];
    }
    cout << endl;
}

int main()
{
    int capacity;
    cin >> capacity;

    Queue *q = createQueue(capacity);

    int x;
    while (cin >> x) {
        enqueue(q, x);
    }

    int d = dequeue(q);
    cout << d << endl;

    int p = peek(q);
    cout << p << endl;

    printQueue(q);

    delete[] q->arr;
    delete q;

    return 0;
}

    
