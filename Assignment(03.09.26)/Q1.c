/*
A simple calculator recives an infix expression.It must 
a)convert infix expresion to postfix
b)Evalute the postfix expression

sample input :3+4*5
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
}

int precedence(char ch){
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]){
    int i, j = 0;
    char ch;
    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isdigit(ch)){
            postfix[j++] = ch;
        }
        else if (ch == '('){
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else{
            while (top != -1 && precedence(stack[top]) >= precedence(ch)){
             postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]){
    int s[MAX];
    int t = -1;
    int i, a, b;
    for (i = 0; postfix[i] != '\0'; i++){
        if (isdigit(postfix[i])){
            s[++t] = postfix[i] - '0';
        }
        else{
            b = s[t--];
            a = s[t--];
            switch (postfix[i]){
                case '+':
                    s[++t] = a + b;
                    break;
                case '-':
                    s[++t] = a - b;
                    break;
                case '*':
                    s[++t] = a * b;
                    break;
                case '/':
                    s[++t] = a / b;
                    break;
                case '^':
                    s[++t] = (int)pow(a, b);
                    break;
            }
        }
    }
    return s[t];
}

int main(){
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));
    return 0;
}
