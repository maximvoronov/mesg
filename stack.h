
#ifndef STACK
#define STACK

struct Stack{
    const char type[];
    int size;

};
typedef Stack stack;

void pop(stack* stack);
void push(int value);


#endif
