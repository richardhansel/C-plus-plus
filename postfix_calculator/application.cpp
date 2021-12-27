// Programmer           : Richard Hansel
// Project number       : 5 (Postfix Expression Calculator)
// Project Description  : This program evaluates and calculates a postfix expression. It will return the value calculated to the user and the program will throw error messages when the values inputted are invalid.
// Date                 : 05/02/2021

#include <iostream>
#include <string>
#include "ArrayStack.h"
#include <ctype.h>
using namespace std;

int main()
{
    ArrayStack<int> stack;
    
    char keepGoing = 'Y';
    while(keepGoing == 'Y')
    {
        bool isError = false;
        string items;
        int value;
        int number1;
        int number2;
        int result;
        
        cout << "Enter an expression:" << endl;
        getline(cin, items);
        
        for (int ch = 0; ch < items.length() && !isError; ch++)
        {
            if(isdigit(items[ch]))
            {
                value = items[ch] - '0';
                stack.push(value);
            }
            else if(items[ch] == '+')
            {
                if(stack.isEmpty())
                {
                    isError = true;
                    break;
                }
                number2 = stack.peek();
                stack.pop();
                if(stack.isEmpty())
                {
                    isError = true;
                    break;
                }
                number1 = stack.peek();
                stack.pop();
                result = number1 + number2;
                stack.push(result);
            }
            else if(items[ch] == '-')
            {
                if(stack.isEmpty())
                {
                    isError = true;
                    break;
                }
                number2 = stack.peek();
                stack.pop();
                if(stack.isEmpty())
                {
                    isError = true;
                    break;
                }
                number1 = stack.peek();
                stack.pop();
                result = number1 - number2;
                stack.push(result);
            }
            else if(items[ch] == '*')
            {
                if(stack.isEmpty())
                {
                    isError = true;
                    break;
                }
                number2 = stack.peek();
                stack.pop();
                if(stack.isEmpty())
                {
                    isError = true;
                    break;
                }
                number1 = stack.peek();
                stack.pop();
                result = number1 * number2;
                stack.push(result);
            }
            else if(items[ch] == '/')
            {
                if(stack.isEmpty())
                {
                    isError = true;
                    break;
                }
                number2 = stack.peek();
                stack.pop();
                if(stack.isEmpty())
                {
                    isError = true;
                    break;
                }
                number1 = stack.peek();
                stack.pop();
                result = number1 / number2;
                stack.push(result);

            }
            else if(items[ch] == ' ')
            {
                // Leave it
            }
            else
            {
                cout << "error" << endl;
                isError = true; 
            }
        }
        if(!isError)
        {
            if(stack.isEmpty())
            {
                cout << "Error - error in expression" << endl;
            }
            else
            {
                result = stack.peek();
                stack.pop();
                
                if(!stack.isEmpty())
                {
                    cout << "Error - malformed expression" << endl;
                }
                else
                {
                    //everything is good
                    cout << "Value is: " << result << endl;
                }
            }
            cout << "Enter another expression? (Y/N):  ";
            cin  >> keepGoing;
            cin.ignore(99, '\n');
        }
    }
}  // end driver
