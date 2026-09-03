#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool validate_c_comment(const char* input) {
    int state = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        switch (state) {
            // q0: if first chsracter is /, it moves to q1, else it moves to trap state
            case 0:
                if (ch == '/') state = 1;
                else state = -1;
                break;
            // q1: if 2nd character is *, it still accpts it and movs to q2
            case 1:
                if (ch == '*') state = 2;
                else state = -1;
                break;
            // q2: anything in here is fine, but if it sees a *, it goes to the next state. this is prepping to end
            case 2:
                if (ch == '*') state = 3;
                else state = 2; // Stays in body for 'a' or '/'
                break;
            // q3: if it sees a /, it moves to accept state and finishes.
            // if it sees a different character, it goes back to q2,
            //but if it sees another *, it stays in this state, prepping for the next character to be a / and finish the comment
            case 3:
                if (ch == '/') state = 4;
                else if (ch == '*') state = 3;
                else state = 2;
                break;
            // q4: Accept state. Trailing characters trigger trap
            case 4:
                state = -1;
                break;
            // -1: Trap state.
            case -1:
                state = -1;
                break;
        }
    }

    return state == 4;
}

//format
int main() {
    printf("--- C-Style Comment NFA Validator ---\n");
    char test_string[256];
    char choice[16];

    while (true) {
        printf("\nEnter a string to test: ");
        if (fgets(test_string, sizeof(test_string), stdin) != NULL) {
            // Remove the newline character left by fgets
            test_string[strcspn(test_string, "\n")] = '\0';
        }

        if (validate_c_comment(test_string)) {
            printf("Result for '%s': ACCEPTED\n", test_string);
        } else {
            printf("Result for '%s': REJECTED\n", test_string);
        }

        printf("\nTest another string? (y/n): ");
        if (fgets(choice, sizeof(choice), stdin) != NULL) {
            choice[strcspn(choice, "\n")] = '\0';
        }

        if (strcmp(choice, "n") == 0 || strcmp(choice, "N") == 0) {
            printf("\nExiting validator. Goodbye!\n\n");
            break;
        }
    }

    return 0;
}