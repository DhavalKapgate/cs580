typedef struct stack
{
	struct Node *tail;
}Stack;
Stack *createStack();
void push(Stack * stack, int value);
int pop(Stack * stack);
void show(Stack *stack);

