/*2. Develop a Program in C for the following operations on Strings.   
a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP). 
b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with 
REP if PAT exists in STR. Report suitable messages in case PAT does not exist in STR .Support the 
program with functions for each of the above operations. Don't use Built-in functions.*/

#include <stdio.h>

// Global Variables
char STR[100], PAT[100], REP[100], ANS[100];
int s, p, r, a, flag = 0;

// Function Declarations
void read();
void replace();
void display();

int main() {
    read();      // Read inputs
    replace();   // Perform replacement
    display();   // Display results
    return 0;    // Return success
}

void read() {
    printf("Enter the MAIN string: \n");
    scanf(" %[^\n]s", STR); // Use " %[^...] to consume any leftover newline
    printf("Enter a PATTERN string: \n");
    scanf("%s", PAT);
    printf("Enter a REPLACE string: \n");
    scanf("%s", REP);
}

void replace() {
    s = p = a = 0; // Initialize indices
    while (STR[s] != '\0') {
        // Check for match
        if (STR[s] == PAT[p]) {
            p++;
            s++;
            // If the entire PAT string matches
            if (PAT[p] == '\0') {
                flag = 1; // Set flag to indicate a match was found
                for (r = 0; REP[r] != '\0'; r++, a++) {
                    ANS[a] = REP[r]; // Add replacement string to result
                }
                p = 0; // Reset pattern index
            }
        } else { // Mismatch
            ANS[a] = STR[s];
            s++;
            a++;
            p = 0; // Reset pattern index
        }
    }
    ANS[a] = '\0'; // Null-terminate the resultant string
}

void display() {
    if (flag == 0) {
        printf("Pattern not found!!!\n");
    } else {
        printf("\nThe RESULTANT string is:\n%s\n", ANS);
    }
}
