#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main()
{
    int val, option, size, top = -1;
    // Get the size of stack
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("Invalid stack size, Must be greater than 0 \n");
        return 1;
    }
    // Allocate memory for stack
    int *stack = (int *)malloc(size * sizeof(int));

    // Verify memory allocation
    if (stack == NULL)
    {
        printf("Memory allocation is failed.....\n");
        return 1;
    }

    while (true)
    {
        printf(" 1) Push\n 2) Pop\n 3) Display\n 4) Top\n 5) Peek Element\n 6) Is empty\n 7) Exit\n--> Select an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            // PUSH
            if (top == size - 1)
            {
                printf("*** Stack overflow ***\n");
            }
            else
            {
                printf("--> Enter value: ");
                scanf("%d", &val);
                stack[++top] = val;
            }
            break;
        case 2:
            // POP
            if (top == -1)
            {
                printf("*** Stack underflow ***\n");
            }
            else
            {
                printf("Pop element is %d \n", stack[top--]);
            }
            break;
        case 3:
            // Display elements
            if (top == -1)
            {
                printf("*** Stack is empty *** \n");
            }
            else
            {
                printf("--> Elements are: ");
                for (int i = top; i >= 0; i--)
                {
                    printf("%d ", stack[i]);
                }
                printf("\n");
            }
            break;
        case 4:
            // TOP index
            printf("Top is at index: %d \n", top);
            break;
        case 5:
            // PEEK ELEMENT
            if (top == -1)
            {
                printf("*** Stack is empty *** \n");
            }
            else
                printf("Peek element is: %d \n", stack[top]);
            break;
        case 6:
            // Is empty
            printf(top == -1 ? "True, Stack is empty \n" : "False, Stack is not empty \n");
            break;
        case 7:
            free(stack); // Free dynamically allocated memory
            printf("Exiting program.....\n");
            exit(0);

        default:
            printf("Invalid choice, try again...\n");
            break;
        }
    }
}