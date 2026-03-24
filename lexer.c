#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include "include/view_string.h"
#include "include/lexer.h"

token_list *create_token_list(uint64_t capacity)
{
    token_list *l = (token_list *)malloc(sizeof(token_list));
    if (!l)
        return NULL;
    l->capacity = capacity;
    l->len = 0;
    l->value = (token *)malloc(sizeof(token) * capacity);
    if (!l->value)
    {
        free(l);
        return NULL;
    }

    return l;
}

void add_token(token_list *l, string lexeme, token_type type)
{
    if (l->len + 1 >= l->capacity)
    {
        // buffer overflow
    }

    l->value[l->len].lexeme = lexeme;
    l->value[l->len].type = type;
    l->len++;
}

void free_token_list(token_list *l)
{
    for (uint64_t index = 0; index < l->len; index++)
        if (l->value[index].lexeme != NULL) {
            free_string(l->value[index].lexeme);
        }
    free(l->value);
    free(l);
}

void tokenizer(token_list *l, string source)
{
    uint64_t start = 0, end = 0;
    for (;;)
    {
        if (end > source->len - 1)
            break;
        
        char character = get_character(source, end);

        if (isalnum(character))
        {
            do
            {
                if (end > source->len - 1) break;
                end++;
                character = get_character(source, end);
                // border character
            } while (isalnum(character));

            string lexeme = sub_string(source, start, end - 1);
            add_token(l, lexeme, STRING);
            start = end;
            continue;
        }

        switch (character)
        {
        case '+':
            add_token(l, NULL, PLUS);
            start = end + 1;
            break;

        case '*':
            add_token(l, NULL, STAR);
            start = end + 1;
            break;

        default:
            fprintf(stderr, "invalid symbols: '%c'\n", character);
            exit(EXIT_FAILURE);
            break;
        }

        end++;
    }
}