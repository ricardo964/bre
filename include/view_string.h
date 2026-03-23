#ifndef VIEW_STRING
#define VIEW_STRING

#include <stdint.h>
#include <string.h>

typedef struct
{
    char *value;
    uint64_t len;
} v_string;

typedef v_string *string;

// v_string to
string create_string(uint64_t len);
string to_string(char *c);
void free_string(string s);
string sub_string(string s, uint64_t start, uint64_t end);
char get_character(string s, uint64_t i);

#endif // VIEW_STRING