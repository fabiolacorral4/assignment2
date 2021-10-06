#include "str.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

/* Implementation of Str Module using Pointer Notation */

size_t Str_getLength(const char *s)
{
   assert(s != NULL);
   const char *end = s;
   while (*end != '\0')
      end++;
   return (size_t)(end - s);
}

char* Str_copy(char *dest, const char *src)
{
    assert(src != NULL);
    assert(dest != NULL);
    char *i = (char*) src;
    char *result = dest;
    while (*i != '\0')
    {
        *dest = *i;
        dest++;
        i++;
    }
    *dest = '\0';
    return result;
}

char* Str_concat(char *dest, const char *src)
{
    assert(src != NULL);
    assert(dest != NULL);
    char *i = (char*) src;
    char *result = dest;
    size_t len_dest = Str_getLength(dest);
    while(*i != '\0')
    {
        *(dest + len_dest) = *i;
        dest++;
        i++;
    }
    *(dest+len_dest) = '\0';
    return result;
}

int Str_compare(const char *str1, const char *str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);
    int result = 0;
    char *i = (char*)str1;
    size_t len_str1 = Str_getLength(str1);
    size_t len_str2 = Str_getLength(str2);
    while (*i != '\0')
    {
        if (*i == *str2)
        {
            i++;
            str2++;
            continue;
        } 
        else if (*i < *str2)
        {
            result = -1;
            return result;
        }
        else if (*i > *str2)
        {
            result = 1;
            return result;
        }
    }
    if (len_str1 < len_str2) result = -1;
    return result;
}

const char* Str_search(const char *s, const char *subs)
{
    assert(s != NULL);
    assert(subs != NULL);
    const char *i = (char*)s; 
    size_t len_subs = Str_getLength(subs);
    if (*subs == '\0') return s; 
    while (*i != '\0')
    {
        int count = 0;
        while (*(i + count) == *(subs+count))
        {
            if (count == len_subs-1) return i;
            else count++;
        }
        i++;
    }
    return NULL;
}