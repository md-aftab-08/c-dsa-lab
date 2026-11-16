#include <stdio.h>
#include <ctype.h>

int stack[100], top = -1;

int main() {
    char postfix[100], c;
    int i, a, b, r, k;

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    for (i = 0; postfix[i]; i++) {
        c = postfix[i];
        if (isdigit(c))
            stack[++top] = c - '0';
        else {
            b = stack[top--];
            a = stack[top--];
            switch (c) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
                case '^':
                    for (r = 1, k = 0; k < b; k++) r *= a;
                    stack[++top] = r;
                    break;
            }
        }
    }
    printf("Result = %d\n", stack[top]);
    return 0;
}