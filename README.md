# C-Style Comment NFA Validator

A C program that implements a Nondeterministic Finite Automaton (NFA) to validate C-style block comments. It evaluates user-inputted strings to ensure they exactly start with `/*`, end with `*/`, and do not contain the closing sequence anywhere inside the comment body.

## Automata Formal Definition

* **States (Q):** `{q0, q1, q2, q3, q4}`
* **Alphabet (Σ):** `{a, *, /}` *(where 'a' is a placeholder for any character that isn't a star or slash)*
* **Start State:** `q0`
* **Final/Accept State (F):** `{q4}`

## sample outputs
<img width="280" height="391" alt="image" src="https://github.com/user-attachments/assets/4f4801e7-46d1-4614-af21-2d241a6f3586" />
<img width="304" height="472" alt="image" src="https://github.com/user-attachments/assets/2a255a8b-87ee-44cd-9275-94a79a22e040" />


## Prerequisites

* A C compiler (such as `gcc` via MSYS2/MinGW-w64).

## Compilation and Execution

1. Open your terminal in the project directory.
2. Compile the source code using `gcc`:

```bash
gcc main.c -o main

```

3. Run the generated executable:

* **Windows:** `.\main.exe`
* **Mac/Linux:** `./main`

4. Follow the interactive terminal prompts to test various valid and invalid strings.

## Author

**Rachel Joy Pacot**
*CS13a - Automata Theory & Formal Language*
