#include <stdio.h>
// Factorial
long fact(int n)
{
    if(n==0 || n==1)
        return 1;
    return n*fact(n-1);
}
// Fibonacci
int fibonacci(int n)
{
    if(n<=1)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);
}
//Tower of Hanoi
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int fact_num, fib_terms, disks;

    printf("Enter a number for factorial: ");
    scanf("%d", &fact_num);
    if(fact_num < 0) {
        printf("Invalid input. Please enter a non-negative integer!\n");
        return 1;
    }
    printf("Factorial of %d = %ld\n", fact_num, fact(fact_num));

    printf("\nEnter number of Fibonacci terms: ");
    scanf("%d", &fib_terms);
    if(fib_terms < 0) {
        printf("Invalid input. Please enter a non-negative integer!\n");
        return 1;
    }
    printf("Fibonacci series (%d terms): ", fib_terms);
    for(int i = 0; i < fib_terms; i++)
        printf("%d ", fibonacci(i));

    printf("\n\nEnter number of disks: ");
    scanf("%d", &disks);
    if(disks < 1) {
        printf("Invalid input. Please enter a positive integer!\n");
        return 1;
    }
    printf("Tower of Hanoi for %d disks:\n", disks);
    towerOfHanoi(disks, 'A', 'C', 'B');
    return 0;
}