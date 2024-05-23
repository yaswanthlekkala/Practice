#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    long int x1 = 0;
    long int s = x;
    
    if (x < 0) {
        return false;
    }

    while (x > 0) {
        x1 *= 10;
        x1 += x % 10;
        x /= 10;
    }

    return s == x1;
}

int main() {
    int test_cases[] = {121, -121, 10, 12321, 0, 1234567899};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < num_cases; ++i) {
        int num = test_cases[i];
        printf("Is %d a palindrome? %s\n", num, isPalindrome(num) ? "Yes" : "No");
    }
    
    return 0;
}