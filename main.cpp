#include <iostream>
#include <string>

bool validate_c_comment(const std::string& input) {
    int state = 0;

    for (char ch : input) {
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
    std::cout << "--- C-Style Comment NFA Validator ---" << std::endl;
    std::string test_string;
    std::string choice;

    while (true) {
        std::cout << "\nEnter a string to test: ";
        std::getline(std::cin, test_string);

        if (validate_c_comment(test_string)) {
            std::cout << "Result for '" << test_string << "': ACCEPTED\n";
        } else {
            std::cout << "Result for '" << test_string << "': REJECTED\n";
        }

        std::cout << "\nTest another string? (y/n): ";
        std::getline(std::cin, choice);

        if (choice == "n" || choice == "N") {
            std::cout << "\nExiting validator. Goodbye!\n\n";
            break;
        }
    }

    return 0;
}

