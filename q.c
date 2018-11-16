#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *get_dyna_line()
{
    const size_t buffer_length = 42;
    const size_t alloc_increment = 42;

    char buffer[buffer_length];
    char *result = NULL;
    size_t characters_got = 0;
    size_t result_read = 0;
    size_t result_avail = 0;

    while (fgets(buffer, buffer_length, stdin)) // пока  
    {
        characters_got = strlen(buffer);

        result_read += characters_got;

        if (result_read >= result_avail)
        {
            result_avail += alloc_increment;
            result = realloc(result, result_avail);
            strcat(result, buffer);
        }

        if (buffer[characters_got - 1] == '\n')
            break;
    }

    if (ferror(stdin))
    {
        if (result)
            free(result);

        return NULL;
    }

    return result;
}

int main()
{
    char* dyna_buffer;
 
    puts("Input a line:");
    if((dyna_buffer = get_dyna_line()) == NULL && ferror(stdin))
    fputs("Input error\n", stderr), exit(1);
 
    if(dyna_buffer)
    {
    printf("Your input: %s", dyna_buffer);
    
    free(dyna_buffer);
    }
    else
    puts("EOF");
        
    exit(0);
}