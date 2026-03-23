#ifndef LEXER
#define LEXER

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "view_string.h"

typedef enum
{
    PLUS,
    STAR,
    STRING
} token_type;

typedef struct
{
    token_type type;
    string lexeme;
} token;

typedef struct
{
    token *value;
    uint64_t capacity;
    uint64_t len;
} token_list;

token_list *create_token_list(uint64_t capacity);
void add_token(token_list *l, string lexeme, token_type type);
void tokenizer(token_list *l, string source);
void free_token_list(token_list *l);

#endif // LEXER
