#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100], c;
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i]; i++) {
        c = infix[i];
        if (isalnum(c))
            postfix[j++] = c;
        else if (c == '(')
            stack[++top] = c;
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(')
                postfix[j++] = stack[top--];
            top--;
        } else {
            while (top >= 0 && (prec(stack[top]) > prec(c) ||
                   (prec(stack[top]) == prec(c) && c != '^')))
                postfix[j++] = stack[top--];
            stack[++top] = c;
        }
    }
    while (top >= 0)
        postfix[j++] = stack[top--];
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}