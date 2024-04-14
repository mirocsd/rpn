#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define basic stack functions
void push(int *stack[], int *top, int *capacity, int element) {
    if (*top >= *capacity) {
        *capacity *= 2;
        int *new_stack = malloc(*capacity * sizeof(int));
        
        for (int i = 0; i <= *top; i++) {
            new_stack[i] = (*stack)[i];
        }
        free(*stack);
        *stack = new_stack;
    }
    
    
    (*top)++;
    (*stack)[*top] = element;
}

int pop(int *stack[], int *top) {
    int popped = (*stack)[*top];
    (*top)--;
    return popped;
}

int operate(int *stack[], char operand, int *top) {
    // we operate on stack[stack_size] and stack[stack_size - 1]
    int x = 0, y = 0;
    int result = 0;
    x = pop(stack, top);
    y = pop(stack, top);

    char operand_str[2] = {operand, '\0'};
    if (strcmp(operand_str, "p") == 0) {
        result = x + y;
    } else if (strcmp(operand_str, "s") == 0) {
        result = y - x;
    } else if (strcmp(operand_str, "*") == 0) {
        result = x * y;
    } else if (strcmp(operand_str, "/") == 0) {
        result = y / x;
    }

    return result;
}
void printStack(int *stack, int top) {
    printf("Stack contents (bottom to top): ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {

    int stack_cap = 4;
    int *stack = malloc(stack_cap * sizeof(int));
    int top = -1;
    int num = 0;
    char op = ' ';
    while (1) {
        while (scanf("%d", &num) > 0) {
            push(&stack, &top, &stack_cap, num);
        }

        if ((op = getchar()) == EOF) break;
        if (op == ' ' || op == '\n') continue;
        if (op == 'p' || op == 's' || op == '*' || op == '/') {
            int result = operate(&stack, op, &top);
            push(&stack, &top, &stack_cap, result);
        }
    }

    int final = pop(&stack, &top); // result is the last element in stack
    printf("%d\n", final);

    free(stack);
}