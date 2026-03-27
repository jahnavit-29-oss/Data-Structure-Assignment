
// 1. Reverse a string using stack

// Algorithm:
// 1. Start
// 2. Read the String.
// 3. Push each character into stack
// 4. Pop characters one by one.
// 5. Print Popped Characters [Reversed string]
// 6. Stop

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char ch) {
    stack[++top] = ch;
}

// Pop function
char pop() {
    return stack[top--];
}

int main() {
    char str[10];
    int i;
    printf("Enter string: ");
    scanf("%s", str);

    // push all Characters
    for(i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    printf("Reversed string: ");
    // pop all Characters
    while(top != -1) {
        printf("%c", pop());
    }
    return 0;
}


// 2. Balanced Parentheses

// Algorithm:
// 1. Scan expression.
// 2. Push opening brackets.
// 3. On Closing bracket -> check match top
// 4. If mismatched -> not Balanced.
// 5. At end if stack empty -> Balanced.

#include <stdio.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int match(char a, char b) {
    return (a == '(' && b == ')') ||
           (a == '{' && b == '}') ||
           (a == '[' && b == ']');
}

int check(char *exp) {
    for(int i = 0; i < strlen(exp); i++) {
        // push open
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }
        // mismatch check
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(top == -1 || !match(stack[top], exp[i]))
                return 0;
            pop();
        }
    }
    return top == -1; // Balanced if empty
}

int main() {
    char exp[MAX];
    printf("Enter expression: ");
    scanf("%s", exp);
    if(check(exp))
        printf("Balanced expression\n");
    else
        printf("Not Balanced Expression\n");
    return 0;
}

// 3. Next Greater Element

// Algorithm:
// 1. Start
// 2. Take array input
// 3. Traverse array
// 4. Use stack to track elements.
// 5. For each element:
//    -> Compare with stack top
//    -> Print next greater
// 6. Stop

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int main() {
    int arr[] = {5,6,7,8,10};
    int n = 5, i;
    push(arr[0]);
    for(i = 1; i < n; i++) {
        while(top != -1 && stack[top] < arr[i]) {
            printf("%d => %d\n", pop(), arr[i]);
        }
        push(arr[i]);
    }
    while(top != -1) {
        printf("%d => -1\n", pop());
    }
    return 0;
}
   

// 4. Printer Queue Simulation

// Algorithm:
// 1. Start
// 2. Initialize queue
// 3. Display menu (Add, Print, Display)
// 4. Perform operations using FIFO
// 5. Stop

#include <stdio.h>
#define MAX 50

int queue[MAX];
int front = -1, rear = -1; // Initialize front and rear

void enqueue(int x) {
    if(rear == MAX-1) {
        // Check queue full
        printf("Queue full\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = x;
}

void dequeue() {
    // remove element
    if(front == -1) {
        printf("Queue Empty\n");
        return;
    }
    printf("Printed document: %d\n", queue[front++]);
    if(front > rear) front = rear = -1;
}

void display() {
    // display queue
    if(front == -1) {
        printf("No pending documents\n");
        return;
    }
    printf("Pending documents: ");
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, doc;
    while(1) {
        // menu loop
        printf("1. Add 2. Print 3. Display 4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter id: "); scanf("%d", &doc); enqueue(doc); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}


// 5. Circular Queue Basic Operations

// Algorithm:
// 1. Initialize front = -1, rear = -1
// 2. Enqueue: Insert element at queue[rear]
// 3. Dequeue: Remove from front
// 4. Peek: Return queue[front]
// 5. Display: Start from front and print until rear

#include <stdio.h>
#define SIZE 5 // fixed size of circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert element
void enqueue(int value) {
    if((rear+1)%SIZE == front) {
        printf("Queue is Full!\n");
    } else {
        if(front == -1) front = 0; // first element
        rear = (rear+1)%SIZE;
        queue[rear] = value;
        printf("%d inserted into queue.\n", value);
    }
}

// Function to delete element
void dequeue() {
    if(front == -1) {
        printf("Queue is Empty!\n");
    } else {
        int data = queue[front];
        if(front == rear) {
            front = rear = -1; // queue becomes empty
        } else {
            front = (front+1)%SIZE;
        }
        printf("%d removed from queue.\n", data);
    }
}

// Function to see front element
void peek() {
    if(front == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Function to display queue
void display() {
    if(front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while(1) {
            printf("%d ", queue[i]);
            if(i == rear) break;
            i = (i+1)%SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while(1) {
        // Main menu
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); enqueue(value); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}