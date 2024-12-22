/*5. Develop a Program in C for the following Stack Applications a. Evaluation of Suffix expression 
with single digit operands and operators: +, -, *, /, %, ^ b. Solving Tower of Hanoi problem with n 
disks */

//5a. 

/*
#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<ctype.h> 
int compute(char symbol, int op1, int op2) 
{ 
switch(symbol) 
{ 
case '+': return op1+op2; // Perform addition 
case '-': return op1-op2; // Perform subtraction 
case '*': return op1*op2; // Perform multiplaction 
case '/': return op1/op2; // Perform division 
case '%': return op1%op2; // Perform division and gives reminder 
case '$': 
case '^': return pow(op1,op2); // Compute power 
} 
} 
int main() 
{ 
    int s[20]; // Place for stack elements  
    int res; // Holds partial or final result 
    int op1; // First operand  
    int op2; // Second operand  
    int top; 
    // Points to the topmost element 
    int i; 
    // Index value
    char postfix[20]; // Input expression 
    char symbol; // Scanned postfix symbol  
    printf("Enter the postfix expression\n"); 
    scanf("%s",postfix); 
    top=-1; 
    for(i=0;i<strlen(postfix);i++) { 
        symbol=postfix[i]; // Obtains the next character 
        if(isdigit(symbol)) // If character is a digit or not  
        s[++top]=symbol-'0'; 
        else { 
            op2=s[top--]; 
            // Obtain second operand from stack 
            op1=s[top--]; 
            // Obtain first operand from stack 
            // Perform specified operation 
            res=compute(symbol,op1,op2); 
            //Push partial results on the stack 
            s[++top]=res; 
        } 
    } 
    res=s[top--]; 
    printf("the result is %d\n",res); 
return(0);
} */


//5b.
#include<stdio.h> 
void towers(int, char, char, char);  
int main() 
{ 
    int num; 
    printf("Enter the number of disks : "); 
    scanf("%d", &num); 
    printf("The sequence of moves involved in the Tower of Hanoi are :\n"); 
    towers(num, 'A', 'B', 'C'); 
    return(0);
} 
void towers(int n, char source, char temp, char dest) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from peg %c to peg %c", source, dest); 
        return; 
    } 
    towers(n - 1, source, dest, temp); 
    printf("\n Move disk %d from peg %c to peg %c", n, source, dest); 
    towers(n - 1, temp, source, dest); 
}
