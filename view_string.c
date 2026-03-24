#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "include/view_string.h"

string create_string(uint64_t capacity)
{
    string s = (string) malloc(sizeof(v_string));
    if (!s)
        return NULL;

    s->len = capacity - 1;
    s->value = (char *) calloc(capacity, sizeof(char));

    if (!s->value)
    {
        free(s);
        return NULL;
    }

    return s;
}

string to_string(char *c)
{
    uint64_t capacity = strlen(c) + 1;
    string s = create_string(capacity);
    if (!s)
        return NULL;

    strncpy(s->value, c, capacity);

    return s;
}

void free_string(string s)
{
    free(s->value);
    free(s);
}

string sub_string(string s, uint64_t start, uint64_t end)
{
    uint64_t capacity = end - start + 2;
    if (start > end || end >= s->len)
        return NULL;

    string new_s = create_string(capacity);
    if (!new_s)
    {
        free(new_s);
        return NULL;
    };

    strncpy(new_s->value, s->value + start, capacity - 1);
    new_s->value[capacity - 1] = '\0';

    return new_s;
}

char get_character(string s, uint64_t i)
{
    if (i + 1 > s->len)
        return -1;
    return s->value[i];
}