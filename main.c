#include <stdio.h>
#include <stdint.h>
#include "include/lexer.h"
#include "include/view_string.h"

#define MAX_TOKENS 256

int main(uint32_t argv, char **args)
{
    if (argv != 3)
    {
        printf("[!] bre <expesion> <FILENAME>\n");
        return EXIT_FAILURE;
    }

    // verificate if the file exists

    string expresion = to_string(args[1]);

    token_list *list = create_token_list(MAX_TOKENS);
    tokenizer(list, expresion);

    for (uint64_t index = 0; index < list->len; index++)
    {
        if (list->value[index].lexeme == NULL)
        {
            printf(
                "token >> (%d)\n",
                list->value[index].type);
            continue;
        }

        printf(
            "token >> (%s, %d)\n",
            list->value[index].lexeme->value,
            list->value[index].type);
    }

    free_string(expresion);
    free_token_list(list);

    return 0;
}