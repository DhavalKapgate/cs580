typedef struct queue
{
        struct Node *head;
}Queue;
Queue *createQueue();
void enqueue(Queue * queue, int value);
int dequeue(Queue * queue);
void Qshow(Queue *queue);

