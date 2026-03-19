/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(){
    if(top == NULL){
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main(){

    char exp[100];
    int i;

    printf("Enter Postfix Expression: ");
    fgets(exp,100,stdin);

    for(i=0; exp[i] != '\0'; i++){

        if(isdigit(exp[i])){
            push(exp[i] - '0');
        }

        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
            int b = pop();
            int a = pop();
            int res;

            switch(exp[i]){
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            push(res);
        }
    }

    printf("Result = %d", pop());

    return 0;
}