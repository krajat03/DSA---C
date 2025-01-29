#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main()
{
    int size, option, val, front = -1, rear = -1;

    // Get the size of Queue
    printf("Enter the size of queue: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid queue size, Must be greater than 0 \n");
        return 1;
    }

    // Allocate memory for Queue
    int *queue = (int *)malloc(size * sizeof(int));

    // Verifying memory allocation
    if (queue == NULL)
    {
        printf("Memory allocation is failed..... \n");
        return 1;
    }
    while (true)
    {
        printf(" 1) Enqueue\n 2) Dequeue\n 3) Display\n 4) Rear position\n 5) Peek Element\n 6) Is empty\n 7) Exit\n--> Select an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:                                                             // REAR
            if (rear == size - 1)
            {
                printf("*** Queue is full *** \n");
            }
            else
            {
                if (rear == -1)
                {
                    front = 0;
                }
                printf("--> Enter element: ");
                scanf("%d", &val);
                queue[++rear] = val;
            }
            break;
        case 2:                                                             //FRONT
            if (front == -1)
            {
                printf("*** Queue is empty ***\n");
            }
            else
            {
                printf("Front element is %d \n", queue[front]);
                front++;
                if (front > rear)
                {
                    rear = -1;
                    front = -1;
                }
            }
            break;
        case 3:                                                             // Display element
            if (rear == -1)
            {
                printf("*** Queue is empty *** \n");
            }
            else
            {
                printf("--> Elements are: ");
                for (int i = front; i <= rear; i++)
                {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }
            break;
        case 4:                                                             // Get the rear index
            printf("--> Rear's index is: %d \n", rear);
            break;
        case 5:                                                             // Peek element
            if (rear == -1)
            {
                printf("*** Queue is empty ***\n");
            }
            else
                printf("Peek element is: %d \n", queue[front]);
            break;
        case 6:                                                             // Is empty
            printf("%s\n",(rear == -1 ? "True, Queue is empty" : "False, Queue is not empty"));
            break;
        case 7:                                                             //Exit program
            free(queue);
            printf("Exiting Program....\n");
            exit(0);
        default:
            printf("Invalid input, try again...\n");
            break;
        }
    }
}