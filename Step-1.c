#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<errno.h>
char *str_in(void); // Function-0 declearation
/*main function*/ 
int main()
{
    printf("Enter the string: \n");
    char *str = str_in(); // function-0, call-0.
    if (str)
    {
        printf("You entered %s\n", str); // Print the string if the string is entered.
        int str_len = strlen(str); 
        /*Magic block*/
        for (int i = 0; i < (str_len); i++)
        {
            int val= str[(int)i];
            char bin[9];
            int j=7;
            //bin[8]='0';
            while (val>0)
            {
                bin[j]=(val%2)+'0';
                val /=2;
                j--;
            }
            while (j>=0)
            {
                bin[j]='0';
                j--;
            }
                        
            printf("%s\t", bin);
        }
        /*End of magic block*/
        free(str); // Free the allocated memory.
    }
    return 0;
}
/*End of main function.*/ 

/*Funxtion-0 defination.*/ 
char *str_in(void)
{
    char *str = malloc(16);
    size_t len = 0;
    size_t size = 16;
    int c;
    // Error handling if memory-allocation fails.
    if (!str)
    {
        perror("Error allocating the memory!");
    }
    while ((c = getchar()) != EOF && c != '\n') // Check if the buffer is full or there is a newline charecter.
    {
        if (len + 1 >= size) // Check if the lenght of the string is greater than the size allocated.
        {
            char *new_str = realloc(str, size * 2); // Reallocate the memory if string length is greater thean the size allocated.
            // Error handling if the reallocation fails.
            if (!new_str)
            {
                perror("Error reallocating the memory!");
            }
            str = new_str; // Update the str pointer to the newly allocated pointer.
            size *= 2;     // Update the size.
        }
        str[len++] = c; // Upend the charecter to the str and increment the length by 1.
    }
    if (len == 0)
    {
        free(str); // free the allocated memory if length of the string is 0.
    }
    str[len] = '\0'; // Add the NULL charecter at the end of the string.
    return str;      // Returning the string array to the main function.
}
/*End of function-0 defination.*/ 